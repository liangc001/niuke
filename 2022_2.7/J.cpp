#include <bits/stdc++.h>
#define lowbit(x) x&(-x)
#define maxn 200010
using namespace std;

inline int read(){
	int x=0,t=1; char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	return x*t;
}

int n,m;
int a[maxn];
struct ASK{
	int l,r,cnt;
}q[maxn];
int ans[maxn];
int tree[maxn];
map<int,int> mp;

inline void add(int x,int y){
	for(int i=x;i<=2*n;i+=lowbit(i)){
		tree[i]+=y;
	}
}

inline int ask(int x){
	int sum=0;
	for(int i=x;i>=1;i-=lowbit(i)){
		sum+=tree[i];
	}
	return sum;
}

inline bool cmp(ASK x,ASK y){
	return x.r<y.r;
}

signed main(){
	ios::sync_with_stdio(0);
	while(cin>>n>>m){
		memset(tree,0,sizeof(tree));
		mp.clear();
		for(int i=1;i<=n;++i){
			a[i]=read(); a[i+n]=a[i]; 
		}
		for(int i=1;i<=m;++i){
			int l,r;
			l=read(); r=read(); q[i].cnt=i;
			q[i].l=r; q[i].r=l+n;
		}
		sort(q+1,q+1+m,cmp);
		int r=0;
		for(int i=1;i<=m;++i){
			while(r<q[i].r){
				r++;
				if(mp[a[r]]){
					add(mp[a[r]],-1);
					mp[a[r]]=r;
					add(mp[a[r]],1);
				}
				else{
					mp[a[r]]=r;
					add(mp[a[r]],1);
				}
			}
			ans[q[i].cnt]=ask(q[i].r)-ask(q[i].l-1);
		}
		for(int i=1;i<=m;++i){
			cout<<ans[i]<<endl;
		}
	}
	return 0;
}
