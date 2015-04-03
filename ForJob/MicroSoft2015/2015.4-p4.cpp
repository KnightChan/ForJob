#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <unordered_map>
#include <string>
#include <math.h>
#include <string.h>
#include <stack>

using namespace std;


struct Candi{
	char gen;
	int v, s;
};

int f[1001][101][101];
Candi can[101];
int path1[101];

/*wa*/
int main2015p4()
{
	int N, X, Y, B;
	cin >> N >> X >> Y >> B;
	for (int i = 0; i < N; i++)
		cin >> can[i].gen >> can[i].v >> can[i].s;
	memset(f, 0, sizeof(f));
	for (int i = 0; i < N; i++)
	{
		for (int j = B; j >= can[i].s; j--)
		{
			for (int x = 0; x <= X; x++)
				for (int y = 0; y <= Y;y++)
					if (can[i].gen == 'M' && x > 0)
					{
						if (f[j][x][y] < f[j - can[i].s][x - 1][y] + can[i].v)
						{
							path1[j] = i;
							f[j][x][y] = f[j - can[i].s][x - 1][y] + can[i].v;
						}
					}
					else if(can[i].gen == 'F' && y > 0){
						if (f[j][x][y] < f[j - can[i].s][x][y - 1] + can[i].v)
						{
							path1[j] = i;
							f[j][x][y] = f[j - can[i].s][x][y - 1] + can[i].v;
						}
					}
		}
	}
	int maxv = 0, maxb = INT_MAX;
	for (int i = 0; i < B;i ++)
		if (maxv < f[i][X][Y]){
		maxv = f[i][X][Y];
		maxb = i;
		}
	stack<int> st;
	while (path1[maxb])
	{
		st.push(path1[maxb]);
		maxb -= can[maxb].s;
	}
	cout << maxv << " " << maxb << endl;
	while (!st.empty())
	{
		st.pop();
	}
	return 0;
}