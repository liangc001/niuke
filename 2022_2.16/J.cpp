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
int a;
int vis[100010];
bool pl[100010];
queue<int> ops;
queue<int> q;

inline void bfs(){
	q.push(0);
	vis[0]=0;
	int cnt=0;
	while(!q.empty()){
		int now=q.front(); q.pop();
		if(pl[now]==1){
			cnt++;
		}
		if(cnt==t) return;
		for(int i=1;i<=500;++i){
			if(now+(i*i)>100000){
				break;
			}
			int num=now+(i*i);
			if(vis[num]) continue;
			q.push(num);
			vis[num]=vis[now]+1;
		}
		for(int i=1;i<=500;++i){
			if(now-(i*i)<0){
				break;
			}
			int num=now-(i*i);
			if(vis[num]) continue;
			q.push(num);
			vis[num]=vis[now]+1;
		}
	}
	return;
}

signed main(){
	t=read();
	for(int i=1;i<=t;++i){
		a=read();
		ops.push(a);
		pl[a]=1;
	}
	bfs();
	while(!ops.empty()){
		int now=ops.front(); ops.pop();
		cout<<vis[now]<<endl;
	}
	return 0;
}
