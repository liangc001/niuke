#include <bits/stdc++.h>
using namespace std;

inline int read(){
	int x=0,t=1; char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	return x*t;
}


int t,n;
struct O{
	int s,e,h,p;
}a[50];
int max_ha,max_ji;

inline bool cmp(O x,O y){
	if(x.s==y.s) return x.e<y.e;
	else return x.s<y.s;
}

inline void dfs(int now,int end,int ha,int ji){
	if(ha>max_ha||(ha==max_ha&&ji>max_ji)){
		max_ha=ha;
		max_ji=ji;
	}
	if(now>n){
		return;
	}
	if(a[now].s>=end){
		dfs(now+1,a[now].e,ha+a[now].h,ji+a[now].p);
	}
//	if()
	dfs(now+1,end,ha,ji);
}

signed main(){
	t=read();
	while(t--){
		max_ha=0,max_ji=0;
		n=read();
		for(int i=1;i<=n;++i){
			a[i].s=read();
			a[i].e=read();
			a[i].h=read();
			a[i].p=read();
		}
		sort(a+1,a+1+n,cmp);
		dfs(1,0,0,0);
		cout<<max_ha<<" "<<max_ji<<endl;
	}
	return 0;
}
