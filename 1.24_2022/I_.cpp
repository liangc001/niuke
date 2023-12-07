#include<bits/stdc++.h>

using namespace std;

bool flag,flag2;
int n,m;
char mp[1010][1010];
int mx[5]={0,1,-1,0,0};
int my[5]={0,0,0,1,-1};
bool vis[1010][1010];

struct NODE{
    int x,y,tim;
    inline bool operator <(const NODE &a)const{
            return tim>a.tim;
    }
};
priority_queue<NODE> q;

signed main(){
    int sum=0x7fffffff;
    ios::sync_with_stdio(0);
    cin>>n>>m;
    if(n==1){
        flag=1;
    }
    for(int i=1;i<=n;++i){
        string s;
        cin>>s; s=' '+s;
        for(int j=1;j<=m;++j){
            mp[i][j]=s[j];
            if(mp[i][j]=='1'){
                flag2=1;
            }
        }
    }
    if(flag==1&&flag2==1){
        cout<<0<<endl; return 0;
    }
    if(flag2==0){
        cout<<n<<endl; return 0;
    }
    for(int i=1;i<=m;++i){
        q.push((NODE){1,i,mp[1][i]=='0'?1:0});
    }
    while(!q.empty()){
        NODE now=q.top(); q.pop();
        if(vis[now.x][now.y]) continue;
        vis[now.x][now.y]=1;
        if(now.x==n+1){
            cout<<now.tim-1<<endl;
            return 0;
        }
        for(int i=1;i<=4;++i){
            int nx=now.x+mx[i];
            int ny=now.y+my[i];
            if(nx>=1&&nx<=n+1&&ny>=1&&ny<=m){
                q.push((NODE){nx,ny,now.tim+(mp[nx][ny]=='0'?1:0)});
            }
        }
    }
    return 0;
}