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

signed main(){
	n=read();
    for(int i=1;i<=n;++i){
    	bool flag=0;
        stack<int> s1;
        queue<int> s2;
        int now=i;
        while(now){
        	s1.push(now%10); s2.push(now%10);
        	now/=10;
		}
		while(!s2.empty()&&!s1.empty()){
			cout<<s1.top()<<" "<<s2.front()<<endl;
			if(s1.top()!=s2.front()){
				flag=1; break;
			}
			s1.pop(); s2.pop();
		}
		if(flag==1) continue;
		cout<<i<<endl;
    }
    return 0;
}
