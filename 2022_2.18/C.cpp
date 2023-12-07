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

int a,b,c,p1,p2,q1,q2;
int ans=1e16;

signed main(){
	a=read(); b=read(); c=read(); p1=read(); p2=read(); q1=read(); q2=read();
	int d=__gcd(a,b);
	if(c%d!=0||(a==0&&b==0)){
		cout<<"Kuon"<<endl;
		return 0;
	}
	if(a==0&&b!=0){
        if(c%b!=0){
            cout<<"Kuon"<<endl;
		    return 0;
        }
		int y=c/b;
		cout<<q2*y*y+q1*y<<endl;
		return 0;
	}
	if(a!=0&&b==0){
        if(c%a!=0){
            cout<<"Kuon"<<endl;
		    return 0;
        }
		int x=c/a;
		cout<<p2*x*x+p1*x<<endl;
		return 0;
	}
	for(int x=(-1e5);x<=(1e5);++x){
		int sum=c-a*x;
		if(sum%b==0){
			int y=sum/b;
			ans=min(ans,p2*x*x+p1*x+q2*y*y+q1*y);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
