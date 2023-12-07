#include <bits/stdc++.h>
using namespace std;

inline int read(){
	int x=0,t=1; char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	return x*t;
}

int t;
int n,m,k;
char a[510][510];
char ans[510][510];
struct lis{
    int x,y;
}p[2510];

int movx[5]={0,1,-1,0,0};
int movy[5]={0,0,0,1,-1};
bool vis[510][510];

inline void bfs(int x,int y){
    if(x>n||x<1||y>m||y<1||vis[x][y]==1){
        return;
    }
    vis[x][y]=1;
    if(a[x][y]=='*'){
        return;
    }
    else if(a[x][y]>='1'&&a[x][y]<='9'){
        ans[x][y]=a[x][y];
        return;
    }
    else{
    	ans[x][y]='0';
    	for(int i=1;i<=4;++i){
        	bfs(x+movx[i],y+movy[i]);
    	}
	}
}

signed main(){
    t=read();
    while(t--){
        n=read(); m=read(); k=read();
        bool flag=0;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
            	vis[i][j]=0;
                cin>>a[i][j];
                ans[i][j]='.';
            }
        }
        for(int i=1;i<=k;++i){
            p[i].x=read();
            p[i].y=read();
        }
        for(int i=1;i<=k;++i){
            if(a[p[i].x][p[i].y]=='.'){
                bfs(p[i].x,p[i].y);
            }
            else if(a[p[i].x][p[i].y]=='*'){
                cout<<"Game over in step "<<i<<endl;
                flag=1;
                break;
            }
        }
        if(flag==1){
            continue;
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                cout<<ans[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}
