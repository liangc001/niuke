#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define inf 0x7fffffff
int t;
int ans;
string s;
int k;
int cnt;
int f[maxn];
queue<int> q[27];

signed main(){
    cin>>t;
    while(t--){
        cin>>s;
        cin>>k;
        ans=inf;
        if(k==1){
            cout<<1<<endl;
            continue;
        }
        for(int i=0;i<s.size();++i){
            q[s[i]-'a'+1].push(i+1);
        }
        for(int i=1;i<=26;++i){
            cnt=0;
            memset(f,0,sizeof(f));
            while(!q[i].empty()){
                int now=q[i].front(); q[i].pop();
                f[++cnt]=now;
                if(cnt>=k){
                    ans=min(ans,f[cnt]-f[cnt-k+1]+1);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
