#include<bits/stdc++.h>

using namespace std;

#define maxn 500010
int n;
int a[maxn];
struct HE{
    int hi,sum;
}h[maxn];
int cnt,ans;
int dp1[maxn],dp2[maxn];

signed main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    h[++cnt].hi=a[1];
    h[cnt].sum=1;
    for(int i=2;i<=n;++i){
        if(a[i]==h[cnt].hi){
            h[cnt].sum++;
        }
        else{
            h[++cnt].hi=a[i];
            h[cnt].sum=1;
        }
    }
    for(int i=1;i<=cnt;++i){
        if(h[i].hi>h[i-1].hi){
            dp1[i]=dp1[i-1]+h[i].sum;
        }
        else{
            dp1[i]=h[i].sum;
        }
    }
    for(int i=cnt;i>=1;--i){
        if(h[i].hi>h[i+1].hi){
            dp2[i]=dp2[i+1]+h[i].sum;
        }
        else{
            dp2[i]=h[i].sum;
        }
    }
    for(int i=1;i<=cnt;++i){
        ans=max(ans,dp1[i]+dp2[i]-h[i].sum);
    }
    cout<<ans<<endl;
    return 0;
}