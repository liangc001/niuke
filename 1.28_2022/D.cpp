#include<bits/stdc++.h>
#define int long long
#define inf_ 0x7fffffff

using namespace std;

inline int read(){
    int x=0,t=1; char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
    if(ch=='-') t=-1,ch=getchar();
    while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
    return x*t;
}

#define maxn 100010

int n,m;
struct EDGE{
    int to,nex,val;
}edge[500010];
int head[maxn];
int cnt,s;
int u,v,w;
bool vis[maxn];
int dis[maxn];
struct ANS{
    int t,val;
}t[maxn];
bool tim[maxn];

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
    for(int i=1;i<=n;++i) dis[i]=inf_;
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

inline bool cmp(ANS x,ANS y){
    if(x.t==y.t){
        return x.val>y.val;
    }
    else{
        return x.t>y.t;
    }
}

signed main(){
    n=read(); m=read(); s=0;
    for(int i=1;i<=m;++i){
        u=read(); v=read(); w=read();
        add(u,v,w);
        add(v,u,w);
    }
    dij();
    for(int i=1;i<=n;++i){
        t[i].t=read();
        t[i].val=dis[i];
    }
    sort(t+1,t+1+n,cmp);
    int ans=0,cnt=1;
    priority_queue<int> q;
    for(int i=n;i>=1;--i){
        while(cnt<=n){
            if(t[cnt].t>=i){
                q.push(t[cnt].val);
                cnt++;
            }
            else{
                break;
            }
        }
        if(!q.empty()){
            ans+=q.top(); q.pop();
        }
    }
    while(!q.empty()){
        ans-=q.top(); q.pop();
    }
    cout<<ans<<endl;
    return 0;
}