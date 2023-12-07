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
int a[1000010];
int ans;
bool flag;
int now;

signed main(){
    n=read();
    a[n+1]=0;
    for(int i=1;i<=n+1;++i){
        if(i<=n) a[i]=read();
        if(flag==0){
            if(a[i]>a[1]){
                flag=1;
                i--;
                continue;
            }
        }
        else{
            if(a[i]>now){
                now=a[i];
            }
            else{
                ans++; now=0;
            }
        }
    }
    if(ans!=1)cout<<ans;
    else cout<<0;
    return 0;
}
