#include<bits/stdc++.h>
#include<stdio.h> 
#define int long long
#define mod 998244353
using namespace std;

struct QES{
    int l,r;
    int id;
    int ans;
}q[100010];
int k;
int cnt;

inline int ksm(int a,int b){
    int sum=1;
    while(b){
        if(b&1) sum=(sum*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return sum%mod;
}

inline bool cmp(QES x,QES y){
    if(x.l==y.l){
        return x.r<y.r;
    }
    else{
        return x.l<y.l;
    }
}

inline bool cmp2(QES x,QES y){
    return x.id<y.id;
}

signed main(){
    ios::sync_with_stdio(0);
    cin>>k;
    cin>>cnt;
    for(int i=1;i<=cnt;++i){
        cin>>q[i].l>>q[i].r;
        q[i].id=i;
    }
    sort(q+1,q+1+cnt,cmp);
    int l=q[1].l,r=q[1].r;
    for(int i=l;i<=r;++i){
        q[1].ans=(q[1].ans+ksm(i,k))%mod;
    }
    for(int i=2;i<=cnt;++i){
        q[i].ans=q[i-1].ans%mod;
        if(l<q[i].l){
            for(int j=l;j<q[i].l;++j){
                q[i].ans=(q[i].ans-ksm(j,k))%mod;
            }
        }
        if(l>q[i].l){
            for(int j=q[i].l;j<l;++j){
                q[i].ans=(q[i].ans+ksm(j,k))%mod;
            }
        }
        if(r<q[i].r){
            for(int j=r+1;j<=q[i].r;++j){
                q[i].ans=(q[i].ans+ksm(j,k))%mod;
            }
        }
        if(r>q[i].r){
            for(int j=q[i].r+1;j<=r;++j){
                q[i].ans=(q[i].ans-ksm(j,k))%mod;
            }
        }
        l=q[i].l; r=q[i].r;
    }
    sort(q+1,q+1+cnt,cmp2);
    for(int i=1;i<=cnt;++i){
        cout<<q[i].ans%mod<<endl;
    }
    return 0;
}
