#include <bits/stdc++.h>
using namespace std;

inline int read(){
	int x=0,t=1; char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	return x*t;
}

#define maxn 100010
int n;
bool vis[maxn];

signed main(){
	cin>>n;
    for(int i=4;i<=n;++i){
        if(i%4==0) vis[i]=1;
        int now=i; if(vis[i]==1) continue;
        while(now!=0){
            cout<<now<<endl;
            int tes=now%10;
            if(tes==4){
                vis[i]=1;break;
            }
            tes/=4;
        }
    }
    for(int i=1;i<=n;++i){
        if(vis[i]==0) cout<<i<<endl;
    }
    return 0;
} 
