#include <bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
	int x=0,t=1; char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	return x*t;
}

const int pri[15]={2,3,5,7,11,13,17,19,23,29,31,37};
int n,m;
int ans,num;

inline void dfs(int now,int las,int p,int s){
	if(s>num||(s==num&&p<ans)){
		num=s; ans=p;
	}
	if(now>=10) return;
	for(int i=1;i<=las;++i){
		if(p*pri[now]>n) break;
		p*=pri[now];
		dfs(now+1,i,p,s*(i+1));
	}
}

signed main(){
	n=read();
	dfs(0,31,1,1);
	cout<<ans<<endl;
	return 0;
}
