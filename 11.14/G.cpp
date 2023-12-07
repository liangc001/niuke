#include <bits/stdc++.h>
using namespace std;

inline int read(){
	int x=0,t=1; char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	return x*t;
}

#define maxn 1010
int n,m;
int f[maxn];

inline int find(int x){
    if(x==f[x]) return f[x];
    else return f[x]=find(f[x]);
}

inline int afind(int x,int sum){
    if(x==f[x]) return sum;
    else{
        afind(f[x],sum+1);
    }
}

signed main(){
    n=read(); m=read();
    for(int i=1;i<=n;++i) f[i]=i;
    for(int i=1;i<=m;++i){
        int x=read(); int y=read();
        int fx=find(x);
        int fy=find(y);
        if(fx!=fy){
            f[fy]=fx;
        }
    }
    for(int i=1;i<=n;++i){
        cout<<afind(i,0)<<endl;
    }
    return 0;
}
