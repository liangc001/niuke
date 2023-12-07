#include <bits/stdc++.h>
using namespace std;

inline int read(){
	int x=0,t=1; char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	return x*t;
}
#define int long long
#define maxn 400010

int high[maxn],wide[maxn],sum[maxn];
string s;

inline int dfs(int u){
	high[u]=wide[u]=1; sum[u]=0;
	int v=u+1;
	for(;s[v]!=')';){
		int next=dfs(v);
		high[u]=max(high[u],high[v]+1);
		wide[u]+=wide[v]+1;
		sum[u]+=sum[v];
		v=next;
	}
	sum[u]=high[u]*wide[u]-sum[u];
	return v+1;
}

signed main(){
	int t=read();
	while(t--){
		cin>>s;
		s='('+s; s+=')';
		dfs(0);
		cout<<high[0]*wide[0]-sum[0]<<endl;
	}
	return 0;
}
