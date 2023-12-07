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
int f[400020];

signed main(){
    f[0]=0; f[1]=1;
    for(int i=2;i<=1000;++i){
        f[i]=f[i/2]+f[i%2];
    }
    cout<<f[0]<<" "<<f[1]<<" "<<f[2]<<" "<<f[3];
    for(int i=4;i<=50;++i){
		if(i%4==0)cout<<endl;
    	cout<<f[i]<<" ";
    }
    t=read();
    while(t--){
    }
    return 0;
}
