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
struct pencil{
    int num,val;
    double ave;
}pen[5];

bool cmp(pencil a,pencil b){
    return a.ave>b.ave;
}

signed main(){
    n=read();
    for(int i=1;i<=n;++i){
        pen[i].num=read(); pen[i].val=read();
        pen[i].ave=(double)pen[i].val/(double)pen[i].num;
    }
    sort(pen+1,pen+1+3,cmp);
    cout<<pen[1].num;
}
