#include <bits/stdc++.h>
using namespace std;

inline int read(){
	int x=0,t=1; char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	return x*t;
}
inline void wri(int x){
    if(x<0){putchar('-');x=-x;}
    if(x>9)wri(x/10);
    putchar(x%10+'0');
}

#define maxn 100010
int n,m;
int a[maxn];
struct ASK{
	int l,r,cnt;
	int bl;
}q[maxn];
int an[maxn];
map<int,int> mp;

inline bool cmp(ASK a,ASK b){
    return (a.bl)^(b.bl)?a.l<b.l:(((a.bl)&1)?a.r<b.r:a.r>b.r);
}

signed main(){
	while(scanf("%d%d",&n,&m)!=-1){
		int l,r,ans=0;
		mp.clear();
		for(int i=1;i<=n;++i){
			a[i]=read();
			if(mp[a[i]]==0) ans++;
			mp[a[i]]++;
		}
		for(int i=1;i<=m;++i){
			q[i].l=read(); q[i].r=read(); q[i].cnt=i;
			q[i].bl=((q[i].l-1)/sqrt(n)/2)+1;
		}
		sort(q+1,q+1+m,cmp);
		l=q[1].l; r=q[1].r;
		for(int i=l+1;i<=r-1;++i){
			mp[a[i]]--;
			if(mp[a[i]]==0){
				ans--;
			}
		}
		an[q[1].cnt]=ans;
		for(int i=2;i<=m;++i){
			if(l>q[i].l){
				for(int j=q[i].l+1;j<=l;++j){
					mp[a[j]]--;
					if(mp[a[j]]==0){
						ans--;
					}
				}
				l=q[i].l;
			}
			if(l<q[i].l){
				for(int j=l+1;j<=q[i].l;++j){
					if(mp[a[j]]==0){
						ans++;
					}
					mp[a[j]]++;
				}
				l=q[i].l;
			}
			if(r>q[i].r){
				for(int j=q[i].r;j<=r-1;++j){
					if(mp[a[j]]==0){
						ans++;
					}
					mp[a[j]]++;
				}
				r=q[i].r;
			}
			if(r<q[i].r){
				for(int j=r;j<=q[i].r-1;++j){
					mp[a[j]]--;
					if(mp[a[j]]==0){
						ans--;
					}
				}
				r=q[i].r;
			}
			an[q[i].cnt]=ans;
		}
		for(int i=1;i<=m;++i){
			wri(an[i]);
			printf("\n");
		}
	}
	return 0;
}
