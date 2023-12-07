#include<bits/stdc++.h>

using namespace std;

string s;

signed main(){
    ios::sync_with_stdio(0);
    cin>>s;
    int suma=0,sumb=0;
    bool f=0;
    int ansa=0,ansb=0;
    for(int i=0;i<s.size();++i){
        if(s[i]=='b'){
            sumb++;
        }
        if(s[i]=='a'){
            break;
        }
    }
    for(int i=s.size()-1;i>=0;--i){
        if(s[i]=='a'){
            suma++;
        }
        else break;
    }
    for(int i=sumb;i<=s.size()-sumb+1;++i){
        cout<<s[i]<<endl;
        if(s[i]=='a'){
            ansa++;
        }
        else{
            ansb++;
        }
    }
    cout<<min(ansa,ansb)<<endl;
    return 0;
}