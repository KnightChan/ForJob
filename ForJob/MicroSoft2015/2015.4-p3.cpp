#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <unordered_map>
#include <string>
#include <math.h>
#include <string.h>

using namespace std;

#define INF 0x03F3F3F3F

const int N = 1010;
int path[N], vis[N];

void Dijkstra(int cost[][N], int lowcost[N], int n, int beg){
	int i, j, min;
	memset(vis, 0, sizeof(vis));
	vis[beg] = 1;
	for (i = 0; i<n; i++){
		lowcost[i] = cost[beg][i]; path[i] = beg;
		cout << lowcost[i] << "," << n << ";";
	}
	lowcost[beg] = 0;
	path[beg] = -1; // 树根的标记
	int pre = beg;
	for (i = 1; i<n; i++){
		min = INF;
		for (j = 0; j<n; j++)
			// 下面的加法可能导致溢出,INF不能取太大
			if (vis[j] == 0 && lowcost[pre] + cost[pre][j]<lowcost[j]){
			lowcost[j] = lowcost[pre] + cost[pre][j];
			path[j] = pre;
			}
		for (j = 0; j<n; j++)
			if (vis[j] == 0 && lowcost[j] < min){
			min = lowcost[j]; pre = j;
			}
		vis[pre] = 1;
	}
	cout << lowcost[N - 1] << endl;
}

#define DIJTYPE int
const DIJTYPE MAX = 9999999;
const int MAXLEN = N;
//DIJTYPE cost[MAXLEN][MAXLEN];
DIJTYPE dist[N];
int cost[N][N], lowcost[N];
int pre[MAXLEN];
int n;
void Dijkstra1(int u){
	int s[MAXLEN], i, j, k;
	DIJTYPE min;
	for (i = 1; i <= n; i++){
		dist[i] = cost[u][i];
		s[i] = 0;
		if (cost[u][i] != MAX) pre[i] = u;
		else pre[i] = 0;
	}
	s[u] = 1;
	dist[u] = 0;
	for (i = 1; i <= n; i++){
		min = MAX;
		k = 0;
		for (j = 1; j <= n; j++)
			if (s[j] == 0 && dist[j] != 0 && dist[j]<min){
			min = dist[j];
			k = j;
			}
		s[k] = 1;
		if (k == 0) continue;
		for (j = 1; j <= n; j++)
			if (s[j] == 0 && cost[k][j] + min<dist[j]){
			dist[j] = cost[k][j] + min;
			pre[j] = k;
			}
	}
}

struct Point{
	int x, y;
};

int calcDis(Point &a, Point &b)
{
	return min(abs(a.x - b.x), abs(a.y - b.y));
}


Point p[N];

int main2015p3()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i].x >> p[i].y;
	for (int i = 0; i < n; i++)
	{
		cost[i][i] = 0;
		for (int j = i + 1; j < n; j++)
		{
			cost[i][j] = calcDis(p[i], p[j]);
			cost[j][i] = cost[i][j];
		}
	}
	Dijkstra1(0);
	cout << dist[n - 1] << endl;
}