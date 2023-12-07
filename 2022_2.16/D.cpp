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
#define maxn 500010

int n;
struct A{
	int a,id;
}p[maxn];
int ans[maxn];
int cnt;

inline bool cmp(A x,A y){
	return x.a>y.a;
}

signed main(){
	n=read();
	for(int i=1;i<=n;++i){
		p[i].a=read(); p[i].id=i;
	}
	sort(p+1,p+1+n,cmp);
	int max_val=p[1].a;
	int sum=1;
	for(int i=n;i>=1;--i){
		if(sum*p[i].a>=max_val){
			for(int j=i;j>=1;--j){
				ans[++cnt]=p[j].id;
			}
			break;
		}
		sum*=2;
	}
	sort(ans+1,ans+1+cnt);
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;++i){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
