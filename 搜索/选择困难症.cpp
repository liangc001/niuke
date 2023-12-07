#include<bits/stdc++.h>
#define int long long
using namespace std;

int k,m;
int a[110],v[110][110];
int ans;

inline void dfs(int now,int sum){
    if(sum>m){
        int tes=1;
        for(int j=now+1;j<=k;++j){
            tes*=(a[j]+1);
        }
        ans+=tes;
        return;
    }
    if(now==k+1){
        return;
    }
    for(int i=1;i<=a[now];++i){
        dfs(now+1,sum+v[now][i]);
    }
    dfs(now+1,sum);
}

signed main(){
    ios::sync_with_stdio(false);
    while(cin>>k>>m){
    	ans=0;
    for(int i=1;i<=k;++i){
        cin>>a[i];
        for(int j=1;j<=a[i];++j){
            cin>>v[i][j];
        }
    }
    dfs(1,0);
    cout<<ans<<endl;
    }
    return 0;
}
