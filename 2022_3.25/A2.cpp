#include<bits/stdc++.h>

using namespace std;

#define maxn 100010
int n,k;
int pos[maxn];
map<string,int> mp;
string s[maxn];
int ans;

signed main(){
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>s[i];
        if(mp[s[i]]==0){
            mp[s[i]]=i;
            pos[i]=0;
        }
        else{
            pos[i]=mp[s[i]];
            mp[s[i]]=i;
        }
        int now=pos[i];
        while(now){
            if(i-now-1<=k){
                ans++;
            }
            else{
                break;
            }
            now=pos[now];
        }
    }
    if(k==1||n==1){
    	cout<<0<<endl;
	} 
    else cout<<ans<<endl;
    return 0;
}
