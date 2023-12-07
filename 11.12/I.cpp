#include<bits/stdc++.h>
#define int long long
#define lowbit(x) x&-x
#define maxn 1000010
using namespace std;

inline int read(){
	int x=0,t=1;
	char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	return x*t;
}

int t[maxn],c[maxn],a[maxn],b[maxn];
int n;
long long ans;
int ad[maxn];
int tree[maxn];

inline void add(int x){
    for(int i=x;i<=n;i+=lowbit(i)){
        tree[i]++;
    }
}

inline int ask(int x){
    int sum=0;
    for(int i=x;i>=1;i-=lowbit(i)){
        sum+=tree[i];
    }
    return sum;
}

signed main(){
	n=read();
	for(int i=1;i<=n;i++){
        int on=read();
        t[i]=t[i-1]+on;
        if(t[i]>0) ans++;
        ad[i]=t[i];
    }
    sort(ad+1,ad+1+n);
    int cnt=unique(ad+1,ad+1+n)-(ad+1);
    for(int i=1;i<=n;++i){
        t[i]=lower_bound(ad+1,ad+1+cnt,t[i])-ad;
    }
    for(int i=1;i<=n;++i){
        add(t[i]);
        ans+=ask(t[i]-1);
    }
	printf("%lld\n",ans);
	return 0;
}
