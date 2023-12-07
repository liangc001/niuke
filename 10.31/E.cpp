#include <bits/stdc++.h>
using namespace std;

inline int read(){
	int x=0,t=1; char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	return x*t;
}

#define maxn 100010
int n,k;
double p[maxn];
double ans1;
double ans2;
double nowk[1000];
int cnt1,cnt2;
double last[maxn];

inline void dfs(int now){
    if(cnt1==k&&cnt2==n-k){
        double ti=1;
        for(int i=1;i<=cnt1;++i){
            ti=ti*nowk[i];
        }
        for(int i=1;i<=cnt2;++i){
            ti=ti*(1.0-last[i]);
        }
        ans2+=ti;
        return;
    }
	if(now>n) return;
    if(cnt1>k) return;
    if(cnt2>n-k) return;
    nowk[++cnt1]=p[now];
    dfs(now+1);
    cnt1--;
    last[++cnt2]=p[now];
    dfs(now+1);
    cnt2--;
}

signed main(){
    n=read(); k=read();
    for(int i=1;i<=n;++i){
        cin>>p[i]; ans1+=p[i];
    }
    printf("%.4lf\n",ans1);
    dfs(1);
    printf("%.4lf\n",ans2);
    return 0;
}
