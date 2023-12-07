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
int vis[500010];

signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	vis[0]=0;
	for(int i=n-1;i>=1;--i){
		if(vis[i]!=0){
			continue;
		}
		for(int j=n-1;j>=1;--j){
			if((i&j)==0&&vis[j]==0){
				vis[i]=j; vis[j]=i;
				break;
			}
		}
	}
	for(int i=0;i<n;++i){
        if(i!=0&&vis[i]==0){
            cout<<i<<" ";
        }
		else cout<<vis[i]<<" ";
	}
	return 0;
}
