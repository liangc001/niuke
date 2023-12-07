#include<bits/stdc++.h>

using namespace std;

int t,n,m;
char mp[50][50];
int tim[50][50];
int bx,by,ex,ey;
int hx,hy;
bool vis[50][50];
int mx[5]={0,0,0,1,-1};
int my[5]={0,1,-1,0,0};
struct PA{
    int x,y,ti;
}pa[100010];

inline void bfs(){
    queue<pair<int,int> > q;
        memset(vis,0,sizeof(vis));
        tim[hx][hy]=0;
        vis[hx][hy]=1;
    q.push(make_pair(hx,hy));
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(x<1||x>n||y<1||y>m) continue;
        for(int i=1;i<=4;++i){
            int nx=x+mx[i];
            int ny=y+my[i];
            if(nx<=n&&nx>=1&&ny<=m&&ny>=1&&!vis[nx][ny]){
                tim[nx][ny]=tim[x][y]+1;
                vis[nx][ny]=1;
                q.push(make_pair(nx,ny));
            }
        }
    }
}

inline int dfs(){
    queue<PA> q;
    q.push((PA){bx,by,0});
    vis[bx][by]=1;
    while(!q.empty()){
        PA now=q.front(); q.pop();
        int x=now.x; int y=now.y;
            if(x==ex&&y==ey){
                return now.ti;
            }
        for(int i=1;i<=4;++i){
            int nx=x+mx[i]; int ny=my[i];
            if(nx<1||nx>n||ny<1||ny>m||mp[nx][ny]=='#'||now.ti+1>=tim[nx][ny]) continue;
            if(vis[nx][ny]) continue;
            vis[nx][ny]=1;
            q.push((PA){nx,ny,now.ti+1});
        }
    }
    return -1;
}

signed main(){
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;++i){
            string s;
            cin>>s;
            for(int j=0;j<s.size();++j){
                mp[i][j+1]=s[j];
                if(mp[i][j+1]=='S'){
                    bx=i; by=j+1;
                }
                if(mp[i][j+1]=='E'){
                    ex=i; ey=j+1;
                }
                if(mp[i][j+1]=='*'){
                    hx=i; hy=j+1;
                }
            }
        }
        bfs();
        int ans=dfs();
        if(ans!=-1){
            cout<<ans<<endl;
        }
        else{
            cout<<"T_T"<<endl;
        }
    }
    return 0;
}
