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
double f[maxn][500];

signed main(){
    n=read(); k=read();
    f[1][0]=1;f[0][0]=1;
    for(int i=1;i<=n;++i){
        cin>>p[i];
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=i;++j){
            f[i][j]=f[i-1][j]*(1.0000-p[i])+f[i-1][j-1]*p[i];
        }
    }
    printf("%.4lf\n",f[n][k]);
    return 0;
}
