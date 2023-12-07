#include <bits/stdc++.h>
using namespace std;

inline int read(){
	int x=0,t=1; char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	return x*t;
}


#define maxn 1000010
int n;
struct EDGE{
    int nex,to;
}edge[maxn*2];
int head[maxn],cnt;
int a,b;
int fa[maxn];
bool vis[maxn];
int sz[maxn];
int ans,kk;
int dp[maxn];

inline void add(int u,int v){
    edge[++cnt].to=v;
    edge[cnt].nex=head[u];
    head[u]=cnt;
}

inline void dfs(int now){
	sz[now]=1;
	for(int i=head[now];i;i=edge[i].nex){
		int v=edge[i].to;
		if(v==fa[now]) continue;
		fa[v]=now; dp[v]=dp[now]+1;
		dfs(v);
        sz[now]+=sz[v];
        if(now==1){
        	kk=max(kk,sz[v]);
		}
	}
}


signed main(){
    n=read();
    for(int i=1;i<=n-1;++i){
        a=read(); b=read();
        add(a,b); add(b,a);
    }
    dp[1]=0;
    dfs(1);
    cout<<kk<<endl;
    return 0;
}
