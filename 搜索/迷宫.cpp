#include<bits/stdc++.h>
#define inf 1000000007
using namespace std;

int h,w;
char mp[510][510];
int ans[510][510];
int bx,by,ex,ey;
int mx[5]={0,0,0,1,-1};
int my[5]={0,1,-1,0,0};
bool vis[510][510];
int x,y;

int bfs(char s,char t){
	memset(vis,0,sizeof(vis));
	memset(ans,0,sizeof(ans));
	if(s=='S'){
		x=bx,y=by;
	}
	else{
		x=ex,y=ey;
	}
	vis[x][y]=1; 
	ans[x][y]=0;
	queue<pair<int,int> > q;
		q.push(make_pair(x,y));
	while(!q.empty()){
		int nx=q.front().first;
		int ny=q.front().second;
		q.pop();
		for(int i=1;i<=4;++i){
			int tx=nx+mx[i];
			int ty=ny+my[i];
			if(mp[tx][ty]==t){
				return ans[nx][ny]+1;
			}
			if(tx>=1&&tx<=h&&ty>=1&&ty<=w&&((s=='S'&&!vis[tx][ty]&&mp[tx][ty]!='W'&&mp[tx][ty]!='D')||(s=='K'&&!vis[tx][ty]&&mp[tx][ty]!='W'))){
				ans[tx][ty]=ans[nx][ny]+1;
				vis[tx][ty]=1;
				q.push(make_pair(tx,ty));
			}
		}
	}
	return inf;
}

signed main(){
    cin>>h>>w;
    for(int i=1;i<=h;++i){
        string s;
        cin>>s;
        for(int j=0;j<s.size();++j){
            mp[i][j+1]=s[j];
            if(mp[i][j+1]=='S'){
                bx=i; by=j+1;
            }
            if(mp[i][j+1]=='K'){
                ex=i; ey=j+1;
            }
        }
    }
    int ans1=inf;
	ans1=min(ans1,bfs('S','E'));
	ans1=min(ans1,bfs('S','K')+bfs('K','E'));
	if(ans1>=inf){
		cout<<-1<<endl;
	}
	else{
		cout<<ans1<<endl;
	}
    return 0;
}
