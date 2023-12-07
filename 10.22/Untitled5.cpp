#include <bits/stdc++.h>
using namespace std;

inline int read(){
	int x=0,t=1; char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	return x*t;
}


int n;
int r;
stack<int> s;

signed main(){
    n=read(); r=read();
    cout<<n<<"=";
    if(n==0) cout<<0;
    while(n){
    	int now=n%r;
        n/=r;
    	if(now<0)now-=r,n++;
        s.push(now);
    }
	while(!s.empty()){
		int now=s.top();if(now>=10){
            if(now==10)cout<<'A';
            if(now==11)cout<<'B';
            if(now==12)cout<<'C';
            if(now==13)cout<<'D';
            if(now==14)cout<<'E';
            if(now==15)cout<<'F';
            if(now==16)cout<<'G';
            if(now==17)cout<<'H';
            if(now==18)cout<<'I';
            if(now==19)cout<<'J';
        }
        else cout<<now;
		s.pop();
	}
    cout<<"(base";
    cout<<r;
	cout<<")"<<endl;
    return 0;
}
