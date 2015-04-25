#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

/*==================================================*\
| 最大团问题 DP + DFS
| INIT: g[][]邻接矩阵;
| CALL: res = clique(n);
\*==================================================*/
const int V = 1001;
int g[V][V], dp[V], stk[V][V], mx;
int dfs(int n, int ns, int dep){
	if (0 == ns) {
		if (dep > mx) mx = dep;
		return 1;
	}
	int i, j, k, p, cnt;
	for (i = 0; i < ns; i++) {
		k = stk[dep][i]; cnt = 0;
		if (dep + n - k <= mx) return 0;
		if (dep + dp[k] <= mx) return 0;
		for (j = i + 1; j < ns; j++) {
			p = stk[dep][j];
			if (g[k][p]) stk[dep + 1][cnt++] = p;
		}
		dfs(n, cnt, dep + 1);
	}
	return 1;
}

int clique(int n){
	int i, j, ns;
	for (mx = 0, i = n - 1; i >= 0; i--) {
		// vertex: 0 ~ n-1
		for (ns = 0, j = i + 1; j < n; j++)
			if (g[i][j]) stk[1][ns++] = j;
		dfs(n, ns, 1); dp[i] = mx;
	}
	return mx;
}

const int N = 250001;
bool is[N]; int prm[N];
int getprm(int n){
	int i, j, k = 0;
	int s, e = (int)(sqrt(0.0 + n) + 1);
	memset(is, 1, sizeof(is));
	prm[k++] = 2; is[0] = is[1] = 0;
	for (i = 4; i < n; i += 2) is[i] = 0;
	for (i = 3; i < e; i += 2) if (is[i]) {
		prm[k++] = i;
		for (s = i * 2, j = i * i; j < n; j += s) is[j] = 0;
		// 因为j是奇数，所以+奇数i后是偶数，不必处理！
	}
	for (; i < n; i += 2) if (is[i]) prm[k++] = i;
	return k; // 返回素数的个数
}

int a[V];
int main_bianchengmeichusai3()
{
	int T;
	cin >> T;
	getprm(250001);
	for (int tt = 1; tt <= T; tt++)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		for (int i = 0; i < n; i++)
			dp[i] = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
			g[i][j] = 0;
			stk[i][j] = 0;
			if (a[j] % a[i] == 0 && is[a[j] / a[i]]);
			else g[i][j] = 1;
			}
		int ans = clique(n);
		printf("Case #%d: %d\n", tt, ans);
	}
	return 0;
}