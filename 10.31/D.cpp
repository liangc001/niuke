#include <bits/stdc++.h>
#define maxn 3000
#define inf_ 0x7fffffff
using namespace std;

inline int read(){
	int x=0,t=1; char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	return x*t;
}

int m;

struct EDGE{
    int to,nex,val;
}edge[500010];
int head[300],cnt;
int n,s;
int l,r;
int dis[maxn];
bool vis[maxn];

struct node{
    int v,w;
    inline bool operator < (const node &a) const{
        return w>a.w;
    }
};

priority_queue<node> q;

inline void add(int u, int v,int w){
    edge[++cnt].to=v;
    edge[cnt].nex=head[u];
    edge[cnt].val=w;
    head[u]=cnt;
}

inline void dij(){
    for(int i=0;i<=m;++i) dis[i]=inf_;
    q.push((node){s,0});
    dis[s]=0;
    while(!q.empty()){
        node now=q.top(); q.pop();
        if(vis[now.v]==1) continue;
        vis[now.v]=1;
        for(int i=head[now.v];i;i=edge[i].nex){
            int v=edge[i].to;
            if(dis[now.v]+edge[i].val<dis[v]){
                dis[v]=dis[now.v]+edge[i].val;
                q.push((node){v,dis[v]});
            }

        }
    }
}

signed main(){
    m=read(); n=read(); s=0;
    for(int i=1;i<=n;++i){
        l=read(); r=read();
        add(l,r,1);
    }
    for(int i=0;i<=m-1;++i){
    	add(i,i+1,1); add(i+1,i,1);
    }
    dij();
    cout<<dis[m]<<endl;
    return 0;
}
