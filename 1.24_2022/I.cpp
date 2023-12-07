#include<bits/stdc++.h>
using namespace std;

int n,m;
char mp[1010][1010];
int ans1[1010][1010],ans2[1010][1010];
int up,down;
bool flag=0;
bool flag2=0;
int mx1[5]={0,1,0,0};
int my1[5]={0,0,1,-1};
int mx2[5]={0,-1,0,0};
int my2[5]={0,0,1,-1};

inline void dfs1(int x,int y,int tim){
    if(y<1||y>m) return;
    if(tim>=ans1[x][y]||x>up) return;
    ans1[x][y]=min(ans1[x][y],tim);
    for(int i=1;i<=3;++i){
        int nx=x+mx1[i];
        int ny=y+my1[i];
        if(nx>=1&&nx<=up&&ny>=1&&ny<=m){
            if(mp[nx][ny]=='1') dfs1(nx,ny,tim);
            else dfs1(nx,ny,tim+1);
        }
    }
}

inline void dfs2(int x,int y,int tim){
    if(y<1||y>m) return;
    if(tim>=ans2[x][y]||x<down) return;
    ans2[x][y]=min(ans2[x][y],tim);
    for(int i=1;i<=3;++i){
        int nx=x+mx2[i];
        int ny=y+my2[i];
        if(nx>=down&&nx<=n&&ny>=1&&ny<=m){
            if(mp[nx][ny]=='1') dfs2(nx,ny,tim);
            else dfs2(nx,ny,tim+1);
        }
    }
}

signed main(){
    int sum=0x7fffffff;
    ios::sync_with_stdio(0);
    memset(ans2,0x3f,sizeof(ans2));
    memset(ans1,0x3f,sizeof(ans1));
    cin>>n>>m;
    if(n==1){
        flag=1;
    }
    if(n%2==0){
        up=down=n/2;
    }
    else{
        up=down=(n-1)/2;
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
        if(mp[1][i]=='1'){
            dfs1(1,i,0);
        }
        else{
            dfs1(1,i,1);
        }
    }
    for(int i=1;i<=m;++i){
        if(mp[n][i]=='1'){
            dfs2(n,i,0);
        }
        else{
            dfs2(n,i,1);
        }
    }
    for(int i=1;i<=m;++i){
        // cout<<ans1[up][i]<<" "<<ans2[down][i]<<endl;
        if(mp[up][i]=='1'){
            sum=min(sum,ans1[up][i]+ans2[down][i]);
        }
        else{
            sum=min(sum,ans1[up][i]+ans2[down][i]-1);
        }
    }
    cout<<sum<<endl;
    return 0;
}