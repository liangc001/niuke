#include<bits/stdc++.h>

int t,a,b;

using namespace std;

signed main(){
    srand(time(0));
    int t;
    t=rand()%10;
    cout<<t<<endl;
    for(int i=1;i<=t;++i){
        a=rand()%100; b=rand()%100;
        printf("%X %X\n",a,b);
    }
    return 0;
}