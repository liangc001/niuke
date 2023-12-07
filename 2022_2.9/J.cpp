#include <bits/stdc++.h>
using namespace std;

inline int read(){
	int x=0,t=1; char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	return x*t;
}

string cs1="in";
string cs2="out";
map<string,int> mp;
int ans;
queue<string> q;

signed main(){
	ios::sync_with_stdio(0);
	int t=read();
	while(t--){
		int n=read();
		mp.clear(); ans=0;
		while(!q.empty()) q.pop();
		string s,id;
		for(int i=1;i<=n;++i){
			cin>>s>>id;
			if(s==cs1){
				q.push(id);
			}
			else{
				while(mp[q.front()]==1){
					q.pop();
				}
				if(q.front()==id){
					ans++; q.pop();
				}
				else{
					mp[id]=1;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
