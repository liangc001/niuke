#include <bits/stdc++.h>
using namespace std;

inline int read(){
	int x=0,t=1; char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	return x*t;
}
#define maxn 100
int t;
int a,b,n;
int k[maxn];

inline bool cmp(int a,int b){
    return a>b;
}

signed main(){
    t=read();
    while(t--){
        a=read(); b=read(); n=read();
        bool flag=0;
        for(int i=1;i<=n;++i) k[i]=read();
        sort(k+1,k+1+n,cmp);
        for(int i=1;i<=n;++i){
            if(a==0&&b==0){
                flag=1; break;
            }
            if(k[i]%2==1&&b>0){
                k[i]--; b--;
            }
            while(a>0&&k[i]>0){
                k[i]-=2;
                a--;
            }
        }
        if(flag==0){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}
