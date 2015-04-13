#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;


int solution(vector< vector<int> > &A) {
	// write your code in C++11
	int M = A.size();
	if (M == 0) return 0;
	int N = A[0].size();
	//vector<long long> suml(N, 0), sumr(N, 0), sumu(M, 0), sumd(M, 0);
	long long *suml = new long long[N], *sumr = new long long[N], *sumu = new long long[M], *sumd = new long long[M];
	sumu[0] = 0;
	for (int i = 1; i < M; i++)
	{
		sumu[i] = sumu[i - 1];
		for (int j = 0; j < N; j++)
			sumu[i] += A[i][j];
	}
	sumd[M - 1] = 0;
	for (int i = M - 2; i >= 0; i--)
	{
		sumd[i] = sumu[i + 1];
		for (int j = 0; j < N; j++)
			sumu[i] += A[i][j];
	}
	suml[0] = 0;
	for (int i = 1; i < N; i++)
	{
		suml[i] = suml[i - 1];
		for (int j = 0; j < M; j++)
			suml[i] += A[j][i];
	}
	sumr[N - 1] = 0;
	for (int i = N - 2; i >= 0; i++)
	{
		sumr[i] = sumr[i + 1];
		for (int j = 0; j < M; j++)
			sumr[i] += A[j][i];
	}
	int cnt = 0;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			if (sumu[i] == sumd[i] && suml[j] == sumr[j])
				++cnt;
	return cnt;
}
