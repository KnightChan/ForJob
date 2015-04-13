#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int MergeSort(vector<int> &a, int l, int r, int *c){
	long long cnt = 0;
	int mid, i, j, tmp;
	if (r > l + 1){
		mid = (l + r) / 2;
		cnt += MergeSort(a, l, mid, c);
		cnt += MergeSort(a, mid, r, c);
		tmp = l;
		int lc = 0, rc = 0, last = -1;
		for (i = l, j = mid; i < mid && j < r;){
			if (a[i] == a[j])
			{
				last = a[i];
				lc = 0; rc = 0;
				while (i < mid && a[i] == last)
				{
					c[tmp++] = a[i++];
					lc++;
				}
				while (j < r && a[j] == last)
				{
					c[tmp++] = a[j++];
					rc++;
				}
				cnt += lc * rc;
			}
			else if (a[i] > a[j]){
				c[tmp++] = a[j++];
			}
			else c[tmp++] = a[i++];
		}
		if (j < r) for (; j < r; ++j) c[tmp++] = a[j];
		else for (; i < mid; ++i) c[tmp++] = a[i];
		for (i = l; i < r; ++i) a[i] = c[i];
	}
	if (cnt >= 1000000000) return 1000000000;
	return cnt;
}

int solution(vector<int> &A)
{
	int *c = new int[A.size()];
	return MergeSort(A, 0, A.size(), c);
}

int main______ppp()
{
	int i;
	for (i = 0; i < 2; i++)
	{
		printf("-"); 
		//printf("-\n");
	}
	return 0;
}