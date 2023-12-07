#include <bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
	int x=0,t=1; char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	return x*t;
}

int n,m;
int a[100][100];
bool flag;

signed main(){
    n=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=2;i<=n;++i){
        for(int j=1;j<=i-1;++j){
            cout<<i<<" "<<j<<" "<<a[i][j]<<endl;
            if(a[i][j]!=0){
                flag=1; break;
            }
        }
        if(flag==1) break;
    }
    if(flag==1) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}
