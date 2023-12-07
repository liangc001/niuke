#include<bits/stdc++.h>

using namespace std;

int t;
int n;
string s;
string bs="accepted";

signed main(){
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
        int ans=0x7fffffff;
        cin>>n;
        cin>>s;
        for(int i=0;i<s.size()-7;++i){
            int sum=0;
            for(int j=0;j<8;++j){
                if(s[j+i]!=bs[j]) sum++;
            }
            ans=min(ans,sum);
        }
        cout<<ans<<endl;
    }
    return 0;
}