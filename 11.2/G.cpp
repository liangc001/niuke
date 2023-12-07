#include <bits/stdc++.h>
#define int long long
using namespace std;
#define mod 1000000007

inline int read(){
	int x=0,t=1; char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	return x*t;
}

int C[1010][1010];

void init(){
    for(int i=0;i<=1000;++i){
        C[i][0]=1; C[i][i]=1;
        for(int j=1;j<i;++j){
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
        }
    }
}
int ans;
signed main(){
    init();
    int x=read();
    for(int i=0;i*2<=x-1;i+=2){
        ans+=C[x-1][i]*C[x-1-i][i]%mod;
    }
    cout<<ans%mod<<endl;
    return 0;
}
