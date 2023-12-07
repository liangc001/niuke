#include<bits/stdc++.h>
#define int long long
using namespace std;

int t;
string x;
string y;

signed main(){
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
        cin>>x>>y;
            int a=0; int b=0;
            for(int i=0;i<x.size();++i){
                int now;
                if(x[i]>='0'&&x[i]<='9'){
                    now=x[i]-'0';
                }
                else{
                    now=x[i]-'A'+10;
                }
                a=a*16+now;
            }
            for(int i=0;i<y.size();++i){
                int now;
                if(y[i]>='0'&&y[i]<='9'){
                    now=y[i]-'0';
                }
                else{
                    now=y[i]-'A'+10;
                }
                b=b*16+now;
            }
            if(2*a+10>3*b+5){
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
            continue;
    }
}