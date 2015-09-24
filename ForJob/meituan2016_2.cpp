#include<stdio.h>
#include<math.h>

int average(double Y, double X, int N) {
	for (int i = 0; i < N; i++)
	{
		Y = (Y + 1) * (1 - X) + 21 * X;
	}
	return (int)(ceil(Y));
}
