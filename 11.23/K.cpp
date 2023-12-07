#include <bits/stdc++.h>
#define maxn 1010 
#define inf 0x7fffffff
using namespace std;

inline int read(){
	int x=0,t=1; char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	return x*t;
}

int xx,yy,z1,z2,z3,z4;
int n;
struct NODEY{
	int l,r,maxx,minx;
};
int ly[maxn],lx[maxn];
struct NODEX{
	int l,r;
	NODEY y[maxn*4];
	inline void build(int k,int _l,int _r){
		y[k].l=_l; y[k].r=_r; y[k].maxx=-inf; y[k].minx=inf;
		if(_l==_r){
			ly[_l]=k; return;
		}
		int mid=(_l+_r)>>1;
		build(k<<1,_l,mid); build(k<<1|1,mid+1,_r);
	}
	inline int qmin(int k,int _l,int _r){
		if(y[k].l==_l&&y[k].r==r){
			return y[k].minx;
		}
		int mid=(y[k].l+y[k].r)>>1;
		if(_r<=mid) return qmin(k<<1,_l,_r);
		else if(_l>mid) return qmin(k<<1|1,_l,_r);
		else return min(qmin(k<<1,_l,mid),qmin(k<<1|1,mid+1,_r));
	}
	inline int qmax(int k,int _l,int _r){
		if(y[k].l==_l&&y[k].r==_r){
			return y[k].maxx;
		}
		int mid=(y[k].l+y[k].r)>>1;
		if(_r<=mid) return qmax(k<<1,_l,_r);
		else if(_l>mid) return qmax(k<<1|1,_l,_r);
		else return max(qmax(k<<1,_l,mid),qmax(k<<1|1,mid+1,_r));
	}
}x[maxn*4];

inline void build(int k,int l,int r){
	x[k].l=l; x[k].r=r; x[k].build(1,1,n);
	if(l==r){
		lx[l]=k; return;
	}
	int mid=(l+r)>>1;
	build(k<<1,l,mid); build(k<<1|1,mid+1,r);
}
inline void ma(int xt,int yt,int val){
	int tx=lx[xt]; int ty=ly[yt];
	x[tx].y[ty].minx=x[tx].y[ty].maxx=val;
	for(int i=tx;i;i>>=1){
		for(int j=ty;j;j>>=1){
			if(i==tx&&j==ty) continue;
			if(j==ty){
				x[i].y[j].minx=min(x[i<<1].y[j].minx,x[i<<1|1].y[j].minx);
				x[i].y[j].maxx=max(x[i<<1].y[j].maxx,x[i<<1|1].y[j].maxx);
			}
			else{
				x[i].y[j].minx=min(x[i].y[j<<1].minx,x[i].y[j<<1|1].minx);
				x[i].y[j].maxx=max(x[i].y[j<<1].maxx,x[i].y[j<<1|1].maxx);
			}
		}
	}
}//µ¥µãÐÞ¸Ä 
inline int qmin(int k,int x1,int x2,int y1,int y2){
	if(x[k].l==x1&&x[k].r==x2){
		return x[k].qmin(1,y1,y2);
	}
	int mid=(x[k].l+x[k].r)>>1;
	if(x2<=mid) return qmin(k<<1,x1,x2,y1,y2);
	else if(x1>mid) return qmin(k<<1|1,x1,x2,y1,y2);
	else return min(qmin(k<<1,x1,mid,y1,y2),qmin(k<<1|1,mid+1,x2,y1,y2));
}
inline int qmax(int k,int x1,int x2,int y1,int y2){
	if(x[k].l==x1&&x[k].r==x2){
		return x[k].qmax(1,y1,y2);
	}
	int mid=(x[k].l+x[k].r)>>1;
	if(x2<=mid) return qmax(k<<1,x1,x2,y1,y2);
	else if(x1>mid) return qmax(k<<1|1,x1,x2,y1,y2);
	else return max(qmax(k<<1,x1,mid,y1,y2),qmax(k<<1|1,mid+1,x2,y1,y2));
}
int val;
signed main(){
	n=read();
	build(1,1,n);
	for(int i=1;i<=n;++i){
		xx=read(); yy=read();val=read();
		ma(xx,yy,val);
		cout<<qmax(1,1,xx,1,yy)<<endl;
//		z1=read(); z2=read(); z3=read(); z4=read();
//		if(n==1) printf("0 0 0 0\n");
//		else printf("%d %d %d %d\n",qmax(1,1,xx,1,yy),qmax(1,1,xx,yy,n),qmax(1,xx,n,1,yy),qmax(1,xx,n,yy,n));
	}
}
