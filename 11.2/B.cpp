#include <bits/stdc++.h>
using namespace std;

inline int read(){
	int x=0,t=1; char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	return x*t;
}

int f[100010];
int t;
int x[1010],cnt;
int max_x=0;

int worsk(int a,int b){
    int ans=0;
    while(b){
        int c=a%b;
        a=b; b=a%b;
        ans++;
    }
    return ans;
}

signed main(){
	t=read();
    f[1]=1; f[2]=1;
    while(t--){
        x[++cnt]=read();
        max_x=max(max_x,x[cnt]);
    }
    for(int i=3;i<=max_x+1;++i){
        f[i]=f[i-1]+f[i-2];
    }
    for(int i=1;i<=cnt;++i){
        cout<<worsk(f[x[i]],f[x[i+1]])<<endl;
    }
    return 0;
}
