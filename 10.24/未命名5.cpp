#include <bits/stdc++.h>
using namespace std;

inline int read(){
	int x=0,t=1; char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	return x*t;
}

string a;
string b="Bob";
bool flag=0;

signed main(){
    cin>>a;
    for(int i=0;i<a.size();++i){
        int now=strcmp(a.substr(i,3),b);
        if(now==0){
            flag=1; cout<<i; break;
        }
    }
    if(flag==0) cout<<-1;
    return 0;
}
