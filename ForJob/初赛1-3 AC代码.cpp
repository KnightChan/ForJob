#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

namespace chusai3_ac{

int T,Case,n,m,i,j,k,s,t,u,v,ans;
int prime[1000005],p[1000005],cnt[1000005],tot;
int a[1005];

#define inf 1000000000
struct Dinic_maximum_flow
{
	#define Graph_n 1005
	#define Graph_m 2000005
	#define flow_value int
	
	int son[Graph_n],next[Graph_m],ed[Graph_m],d[Graph_n],q[Graph_n],ll,rr;
	flow_value flow[Graph_m],sum,tmp;
	int n,S,T,tot,i,u,v;
	bool vis[Graph_n];
	
	inline void clear(int N){for(n=N,tot=1,i=0;i<=n;++i)son[i]=0;}
	inline void add(int u,int v,flow_value c)
	{
		next[++tot]=son[u];son[u]=tot;ed[tot]=v;flow[tot]=c;
		next[++tot]=son[v];son[v]=tot;ed[tot]=u;flow[tot]=0;
	}
	flow_value find(int now,flow_value Flow)
	{
		if(now==T||!Flow)return Flow;
		flow_value tmp,w=0;
		for(int i=son[now];i&&w<Flow;i=next[i])
		if(flow[i]&&d[now]+1==d[ed[i]])
		{
			tmp=find(ed[i],min(Flow-w,flow[i]));
			flow[i]-=tmp;flow[i^1]+=tmp;w+=tmp;
		}
		if(!w)d[now]=inf;
		return w;
	}
	bool bfs()
	{
		for(i=0;i<=n;++i)vis[i]=false;
		q[rr=1]=S;vis[S]=true;
		for(ll=0;ll<rr&&!vis[T];)
		{
			u=q[++ll];
			for(i=son[u];i;i=next[i])
			if(flow[i]&&!vis[ed[i]])
			{
				v=ed[i];
				q[++rr]=v;
				d[v]=d[u]+1;
				vis[v]=true;
			}
		}
		return vis[T];
	}
	flow_value dinic(int s,int t)
	{
		S=s;T=t;
		for(sum=d[S]=0;bfs();)sum+=find(S,inf);
		return sum;
	}
	
	#undef Graph_n
	#undef Graph_m
	#undef flow_value
}G;

int main_chusai_ac1_3()
{
	n=500000;
	for(i=2;i<=n;++i)
	{
		if(!p[i])p[i]=prime[++tot]=i;
		for(j=1;j<=tot&&prime[j]<=p[i]&&prime[j]<=n/i;++j)p[i*prime[j]]=prime[j];
	}
	for(i=2;i<=n;++i)cnt[i]=cnt[i/p[i]]+1;
	scanf("%d",&T);
	for(;T;--T)
	{
		scanf("%d",&n);s=0;t=n+1;
		for(i=1;i<=n;++i)scanf("%d",&a[i]);
		G.clear(n+1);
		for(i=1;i<=n;++i)if(cnt[a[i]]&1)G.add(s,i,1);else G.add(i,t,1);
		for(i=1;i<=n;++i)
		if(cnt[a[i]]&1)
		for(j=1;j<=n;++j)
		if(!(cnt[a[j]]&1))
		{
			u=a[i];v=a[j];
			if(u>v)swap(u,v);
			if(v%u==0&&p[v/u]==v/u)
			G.add(i,j,1);
		}
		ans=n-G.dinic(s,t);
		++Case;
		printf("Case #%d: %d\n",Case,ans);
	}
	return 0;
}
}