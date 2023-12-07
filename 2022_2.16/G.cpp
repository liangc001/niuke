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
int t;
int a[maxn];

signed main(){
	t=read();
	while(t--){
		int n=read();
		int a=0,b=0;
		for(int i=1;i<=n;++i){
			a[i]=read();
			if(a[i]%2==1){
				b++;
				b+=(a[i]-1)/2;
			}
			else{
				int sum=a[i]/2;
				a+=sum;
			}
		}
		if(a>b){
			cout<<"Bob"<<endl;
		}
		else{
			cout<<"Alice"<<endl;
		}
	}
	return 0;
}
