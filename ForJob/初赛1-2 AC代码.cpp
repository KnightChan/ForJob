#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;
const int N = 1010;
const long long oo = 0x8080808080808080;

struct Data
{
	int x, y, w;
	Data() {}
	Data(int x, int y, int w) : x(x), y(y), w(w) {}


}d[N];

bool operator < (const Data &A, const Data &B){
	if(A.x - A.y != B.x - B.y) return A.x - A.y < B.x - B.y;
	return A.y < B.y;
}

int n;

ll dp[N][N];
ll cal(int a, int b){
	if (d[a].x + d[a].y <= d[b].x - d[b].y)
		return 0;
	long long l = d[a].x + d[a].y - (d[b].x - d[b].y);
	return l * l;
}


double solve(){
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++)dp[i][j] = dp[i - 1][j];
        ll l = d[i].y;
        for (int k = 0; k < i; k++)
				if (d[k].x + d[k].y > d[i].x + d[i].y) {
                    if(dp[i - 1][k] + d[i].w >dp[i][k]){
                        dp[i][k] = dp[i - 1][k] + d[i].w;
                    }

				}
				else dp[i][i] = max(dp[i - 1][k] + cal(k, i) - 4 * l * l + d[i].w, dp[i][i]);
    }
    long long ans = oo;
		for(int i = 0; i <= n; i++)
			for (int j = 0; j <= i; j++){
                if(ans < dp[i][j])
                ans = dp[i][j];

			}

    return ans*0.25;
}


int main_chusai_ac1_2(){
    //freopen("in.txt","r",stdin);
	int ca;
	scanf("%d", &ca);
	for(int T = 1; T <= ca; T++){

		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			int x, y, w;
			scanf("%d%d%d", &x, &y, &w);
			d[i].x = x;
			d[i].y = y;
			d[i].w = 4*w;
		}
		d[0].x = -100000;
		d[0].y = 0;
		d[0].w = 0;
		sort(d + 1, d + 1 + n);
		memset(dp, 0x80, sizeof(dp));
		dp[0][0] = 0;
		printf("Case #%d: %.2f\n", T, solve() );
	}
	return 0;
}
