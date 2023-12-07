#include<bits/stdc++.h>
#define int long long
using namespace std;

int t;
int n,k;
string s;

signed main(){
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
        cin>>n>>k;
        cin>>s;
        s=' '+s;
        int cnt=0;
        int ans=0;
        int dis=0;
        for(int i=1;i<=n;++i){
            if(s[i]=='0'){
                cnt++;
                while(dis<=i&&cnt>k){
                    dis++;
                    if(s[dis]=='0'){
                        cnt--;
                    }
                }
            }
            ans+=i-dis;
        }
        cout<<ans<<endl;
    }
    return 0;
}