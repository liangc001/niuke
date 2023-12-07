#include<bits/stdc++.h>

using namespace std;

signed main(){
    int n,m;
    srand(time(0));
    n=rand()%10+1; m=rand()%10+1;
    cout<<n<<" "<<m<<endl;
    for(int i=1;i<=n;++i){
        string s;
        for(int i=1;i<=m;++i){
            int x=rand()%2;
            s=s+(char)(x+'0');
        }
        cout<<s<<endl;
    }
    return 0;
}