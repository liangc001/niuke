#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,p2,p3;

signed main(){
    cin>>n>>p2>>p3;
    if(n<=2){
        cout<<min(p2,p3)<<endl;
        return 0;
    }
    if(n==3){
        cout<<min(2*p2,p3)<<endl;
        return 0;
    }
    double x2=(double)p2/2.0;
    double x3=(double)p3/3.0;
    int num2=n/2;int num3=n/3;int yu2=n%2; int yu3=n%3;
    if(x2>x3){
        if(yu3==0){
            cout<<num3*p3<<endl; return 0;
        }
        else if(yu3==1){
            cout<<min((num3-1)*p3+2*p2,min((num3+1)*p3,num3*p3+p2))<<endl; return 0;
        }
        else{
            cout<<min((num3*p3)+p2,(num3+1)*p3)<<endl;return 0;
        }
    }
    else if(x2<x3){
        if(yu2==0){
            cout<<num2*p2<<endl; return 0;
        }
        else{
                cout<<min((num2-1)*p2+p3,(num2+1)*p2)<<endl;
        }
    }
    else{
        cout<<(yu2==0?num2*p2:(num2+1)*p2); return 0;
    }
}