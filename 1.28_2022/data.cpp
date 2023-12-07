#include<bits/stdc++.h>

using namespace std;

int t,n,k;
string s;

signed main(){
    srand(time(0));
    t=rand()%5+1;
    cout<<t<<endl;
    while(t--){
        n=rand()%1000+1; k=rand()%n+1;
        cout<<n<<" "<<k<<endl;
        for(int i=1;i<=n;++i){
            int x=rand()%2;
            s+=(x+'0');
        }
        cout<<s<<endl;
    }
    return 0;
}