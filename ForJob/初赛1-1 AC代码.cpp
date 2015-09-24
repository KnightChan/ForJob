#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<cmath>
#include<malloc.h>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<deque>
#include<list>
#include<map>
#include<set>
#include<string>
#include<fstream>
#include<iostream>

namespace chusai1_ac{
#define me(x) memset(x,0,sizeof(x))
#define sy system("pause")
#define maxn 100005
using namespace std;
struct edge
{
	int to,nx;
};
edge es[maxn*2];
int st[maxn],en;
void d__add(int x,int y)
{
	edge e;
	e.to=y;
	e.nx=st[x];
	es[++en]=e;
	st[x]=en;
}
void add(int x,int y)
{
	d__add(x,y);
	d__add(y,x);
}
map<int,int> cs[maxn];
int n,q,ans;
int fa[maxn],color[maxn];
void dfs(int x)
{
	int i,tot=0;
	for (i=st[x];i;i=es[i].nx) if (es[i].to!=fa[x])
	{
		fa[es[i].to]=x;
		tot++;
		dfs(es[i].to);
	}
	cs[x][0]=tot;
}
void change(int x,int y)
{
	if (color[x]==color[fa[x]]) ans++;
	ans+=cs[x][color[x]];
	if (fa[x])
	{
		cs[fa[x]][color[x]]--;
		cs[fa[x]][y]++;
	}
	color[x]=y;
	if (color[x]==color[fa[x]]) ans--;
	ans-=cs[x][color[x]];
}
void solve(int cas)
{
	int i,a,b;
	scanf("%d",&n);
	me(st); en=0;
	for (i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		add(a,b);
	}
	for (i=1;i<=n;i++) cs[i].clear();
	fa[1]=0; me(color); color[0]=-10000097;
	dfs(1); ans=1;
	scanf("%d",&q);
	printf("Case #%d:\n",cas);
	for (i=0;i<q;i++)
	{
		scanf("%d",&a);
		if (a==1) printf("%d\n",ans);
		else
		{
			scanf("%d%d",&a,&b);
			change(a,b);
		}
	}
}
int main_chusai_ac1_1()
{
	int T,i;
	scanf("%d",&T);
	for (i=1;i<=T;i++) solve(i);
	return 0;
}
}