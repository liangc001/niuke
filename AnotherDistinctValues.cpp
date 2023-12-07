#include<bits/stdc++.h>
using namespace std;

int t;
int n,now,tes,cnt,num;

signed main(){
    cin>>t;
    while(t--){
        cin>>n;
        if(n%2==1){
            cout<<"impossible"<<endl;
            continue;
        }
        else{
            cout<<"possible"<<endl;
        }
        now=(n%2==0?n/2:(n+1)/2);
        tes=n-now;
        cnt=0;
        for(int i=1;i<=now;++i){
            num=-1;
            for(int j=1;j<=n;++j){
                num++;
                if(j>now){
                    cout<<-1<<" ";
                }
                else if(cnt>=num){
                    cout<<0<<" ";
                }
                else{
                    cout<<1<<" ";
                }
            }
            cnt++;
            cout<<endl;
        }
        for(int i=now+1;i<=n;++i){
                num=0;
            for(int j=1;j<=n;++j){
                num++;
                if(j<=now){
                    cout<<1<<" ";
                }
                else if(cnt>=num){
                    cout<<0<<" ";
                }
                else{
                    cout<<-1<<" ";
                }
            }
            cnt++;
            cout<<endl;
            }
        }
    return 0;
}