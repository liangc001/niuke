#include<bits/stdc++.h>

using namespace std;

int t;
int n,k;
string s;

signed main(){
    cin>>t;
    while(t--){
        cin>>n>>k;
        int ans=0;
        cin>>s;
        for(int i=0;i<n;++i){
            for(int j=i;j<n;++j){
                int sum=0;
                for(int p=i;p<=j;++p){
                    if(s[p]=='0') sum++;
                }
                if(sum<=k) ans++;
            }

        }
        cout<<ans<<endl;
    }
    return 0;
}