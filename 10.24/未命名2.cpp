#include <bits/stdc++.h>
using namespace std;

inline int read(){
	int x=0,t=1; char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	return x*t;
}

list<int> l;
int n,a;

int main(){
    n=read();
    for(int i=1;i<=n;++i){
        a=read();
        l.push_back(a);
    }
    l.unique();
    list<int>::iterator it;
    for(it=l.begin();it!=l.end();it++){
        cout<<*it<<" ";
    }
    return 0;
}
