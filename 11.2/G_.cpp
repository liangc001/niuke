#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
inline int read(){
	int x=0,t=1; char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	return x*t;
}

int n,up;
int ans;
double down;
double mo[5]={0,1,-2,0.5};

inline double ksm(double a,int b){
    double ans=1;
    while(b){
        if(b&1) ans=ans*a;
        a=a*a;
        b>>=1;
    }
    return ans;
}

inline void dfs(double now,int num){
    if(now>up||now<-up||(now<down&&now>-down)) return;
    if(num==n){
        if(now==1.0){
            ans=(ans+1)%mod; return;
        }
        else{
            return;
        }
    }
    for(int i=1;i<=3;++i){
        dfs(now*mo[i],num+1);
    }
}

signed main(){
    n=read();
    up=ksm(2,(n-1)/2);
    down=ksm(0.5,(n-1)/2);
    dfs(1,1);
    cout<<ans%mod<<endl;
    return 0;
}
