#include <bits/stdc++.h>
#define maxn 200000
using namespace std;

inline int read(){
	int x=0,t=1; char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	return x*t;
}

int t;
int n,q;
int u,v;
int tim;

int f[maxn+10],sz[maxn+10],he[maxn+10];

inline int find(int x){
	if(x==f[x]) return x;
	else return f[x]=find(f[x]);
}

inline void merge(int a,int b){
	f[a]=find(b);
}

inline bool check(int a,int b){
	if(a==b) return 1;
	else return 0;
}

signed main(){
	cin>>t;
	while(t--){
		tim++;
		cout<<"Case #"<<tim<<":"<<endl;
		n=read(); q=read(); int cnt=n;
		for(int i=1;i<=maxn;++i){
			f[i]=i; sz[i]=1; he[i]=i;
		}
		while(q--){
			int f=read();
			if(f==1){
				u=read(); v=read();
				int nu=find(he[u]); int nv=find(he[v]);
				if(check(nu,nv)){
					continue;
				}
				sz[nu]+=sz[nv];
				merge(nv,nu);
			}
			else if(f==2){
				u=read();
				sz[find(he[u])]--;
				he[u]=++cnt;
			}
			else if(f==3){
				u=read();
				cout<<sz[find(he[u])]<<endl;
			}
			else{
				u=read(); v=read();
				int nu=find(he[u]); int nv=find(he[v]);
				if(check(nu,nv)){
					cout<<"YES"<<endl;
				}
				else{
					cout<<"NO"<<endl;
				}
			}
		}
	}
	return 0;
}
