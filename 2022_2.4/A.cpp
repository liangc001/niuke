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

int n;
int ans[500010];
int ac;

signed main(){
	ios::sync_with_stdio(0);
	n=read();
    ans[++ac]=0;
    n--;
    if(n==0){
    	cout<<0<<endl;
    	return 0;
	}
    int sum=1,cnt=0;
    for(int i=1;i<=64;++i){
        sum*=2;
        cnt++;
        if(sum>=n) break;
    }
    int l=1,r;
    sum=1;
    for(int i=1;i<=cnt;++i){
        sum*=2;
        r=sum-2;
        if(r>=l)for(int j=r;j>l;--j){
            ans[++ac]=j;
        }
        ans[++ac]=sum;
        ans[++ac]=sum-1;
        l=sum;
    }
    for(int i=1;i<=n+1;++i){
    	if(ans[i]>n) cout<<i-1<<" ";
    	else cout<<ans[i]<<" ";
	}
	return 0;
}
