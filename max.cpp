#include<bits/stdc++.h>
#define int long long
using namespace std;

int c,n;

signed main(){
    cin>>c>>n;
    int ons=n/c;
    if(c>=n){
        cout<<-1<<endl;
        return 0;
    }
    if(ons==1){
        cout<<c*c<<endl;
        return 0;
    }
    int x=c*ons;
    int y=c*(ons-1);
    cout<<x*y<<endl;
    return 0;
}