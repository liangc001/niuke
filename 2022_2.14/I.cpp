#include <bits/stdc++.h>
#define maxn 300010
using namespace std;

inline int read(){
	int x=0,t=1; char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	return x*t;
}
#define inf 0x3f3f3f3f
int a[maxn],b[maxn];
int n,q;
int opt;
int pos;
int num;
int l,r;

struct TREE{
	int l,r,f;
	long long val;
}tree[4*maxn];

inline void build(int k,int l,int r){
	tree[k].l=l; tree[k].r=r;
	if(l==r){
		tree[k].val=b[l];
		return;
	}
	int mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	tree[k].val=min(tree[k<<1].val,tree[k<<1|1].val);
}

inline void cha(int k,int p,int val){
	if(p==tree[k].l&&p==tree[k].r){
		tree[k].val=val;
		return;
	}
	int mid=(tree[k].l+tree[k].r)>>1;
	if(p<=mid) cha(k<<1,p,val);
	if(p>mid) cha(k<<1|1,p,val);
	tree[k].val=min(tree[k<<1].val,tree[k<<1|1].val);
}

inline long long ask(int k,int l,int r){
	if(l<=tree[k].l&&r>=tree[k].r) return tree[k].val;
	int mid=(tree[k].l+tree[k].r)>>1;
	long long ans=inf;
	if(l<=mid) ans=min(ans,ask(k<<1,l,r));
	if(r>mid) ans=min(ans,ask(k<<1|1,l,r));
	return ans;
}

signed main(){
	n=read();
	q=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		b[i]=a[i]-a[i-1];
	}
	build(1,1,n);
	for(int i=1;i<=q;++i){
		opt=read();
		if(opt==1){
			pos=read(); num=read(); a[pos]=num;
			cha(1,pos,a[pos]-a[pos-1]);
			cha(1,pos+1,a[pos+1]-a[pos]);
		}
		else{
			l=read(); r=read();
			int flag=ask(1,l+1,r);
			if(flag<0){
				cout<<"No"<<endl;
			}
			else{
				cout<<"Yes"<<endl;
			}
		}
	}
	return 0;
}
