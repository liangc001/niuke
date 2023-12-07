#include <bits/stdc++.h>
using namespace std;

inline int read(){
	int x=0,t=1; char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	return x*t;
}

int n,k,t;
list<int> s;

signed main(){
	t=read();
	list<int>::iterator it;
	while(t--){
		s.clear();
		n=read(); k=read();
		for(int i=1;i<=n;++i){
			s.push_back(i);
		}
		it=s.begin();
		while(!s.empty()){
			for(int i=1;i<k;++i){
				++it;
				if(it==s.end()) it=s.begin();
			}
			printf("%d ",*it);
			it=s.erase(it);
			if(it==s.end()) it=s.begin();
		}
		cout<<endl;
	}
	return 0;
}
