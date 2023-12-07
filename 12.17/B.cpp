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

signed main(){
    int t=read();
    while(t--){
        int a=read(); int b=read();
        int l=read(); int r=read();
        if(l==0){
        	cout<<0<<endl;
        	continue;
		}
        int n=a*b/__gcd(a,b);
        if(n>r){
            cout<<-1<<endl;
            continue;
        }
        if(n>=l&&n<=r){
            cout<<n<<endl;
            continue;
        }
        n=n*((l/n)+1);
        if(n>=l&&n<=r){
            cout<<n<<endl;
            continue;
        }
        cout<<-1<<endl;
    }
    return 0;
}
