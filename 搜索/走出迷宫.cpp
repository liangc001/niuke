#include<bits/stdc++.h>

using namespace std;

int n,m;
char mp[510][510];
int bx,by,ex,ey;
bool flag;
int mx[5]={0,0,0,1,-1};
int my[5]={0,1,-1,0,0};
bool vis[510][510];

inline void dfs(int x,int y){
    if(flag==1){
        return;
    }
    if(x==ex&&y==ey){
        flag=1;
        return;
    }
    for(int i=1;i<=4;++i){
        int nx=x+mx[i];
        int ny=y+my[i];
        if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&mp[nx][ny]=='.'&&!vis[nx][ny]){
        	vis[nx][ny]=1;
            dfs(nx,ny);
        }
    }
}

signed main(){
    while(cin>>n>>m){
        flag=0;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;++i){
            string s;
            cin>>s;
            for(int j=0;j<s.size();++j){
            	mp[i][j+1]=s[j];
                if(mp[i][j+1]=='S'){
                    bx=i,by=j+1;
                    mp[i][j+1]='.';
                }
                else if(mp[i][j+1]=='E'){
                    ex=i,ey=j+1;
                    mp[i][j+1]='.';
                }
            }
        }
        dfs(bx,by);
        if(flag==1){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}
