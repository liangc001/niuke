#include<bits/stdc++.h>

using namespace std;

int n,k;
string s[100010];
map<string,int> mp;
int ans;

signed main(){
    ios::sync_with_stdio(0);
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>s[i];
    }
    for(int i=1;i<=k+2;++i){
        mp[s[i]]++; ans+=mp[s[i]]-1;
    }
    for(int i=k+3;i<=n;++i){
        mp[s[i-k-2]]--;
        mp[s[i]]++;
        ans+=mp[s[i]]-1;
    }
    if(n==1||k==1){
    	cout<<0<<endl;
	} 
    else cout<<ans<<endl;
    return 0;
}
