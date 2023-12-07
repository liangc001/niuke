#include<bits/stdc++.h>

#define int long long

using namespace std;

const int maxn=1e7;
int ans[maxn];
int cnt;
bool is_prime[maxn];
int prime[maxn];

signed main(){
    ios::sync_with_stdio(0);
    is_prime[1]=1;
    for(register int i=2;i<=maxn;++i){
		if(!is_prime[i]) prime[++cnt]=i;
		for(register int j=1;j<=cnt&&i*prime[j]<=maxn;++j){
			is_prime[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
    for(int i=1;i<=maxn;++i){
        if(is_prime[i]==0){
            if(i%4==1||i%4==2){
                ans[i]=ans[i-1]+1;
            }
            else{
                ans[i]=ans[i-1];
            }
        }
        else{
            ans[i]=ans[i-1];
        }
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<ans[r]-ans[l-1]<<endl;
    }
    return 0;
}