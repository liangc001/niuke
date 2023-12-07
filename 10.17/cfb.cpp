#include <bits/stdc++.h>
using namespace std;

inline int read(){
	int x=0,t=1; char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	return x*t;
}

double h,s,v,l,k;
int n,ans;

signed main(){
    cin>>h>>s>>v>>l>>k>>n;
    double tim=sqrt((h-k)*2/10.0);
    double res_tim=sqrt((h)*2/10.0);
    double dis_las=res_tim*v;
    double dis=tim*v;
    double dis_l=s-dis_las;
    double dis_r=s-dis+l;
//    int ans=(min(n-1,(int)dis_r))-(max((int)(dis_l+1),0));
//    if(abs(dis_r-(int)dis_r+1)<=0.00001&&(int)(dis_r)+1<n-1) ans++;
//    if(abs(dis_l-(int)dis_l<=0.00001)&&(int)dis_l>0) ans++;
for(int i=0;i<=n-1;++i){
	int now=(double)(i+0.00001);
	if(now>=dis_l&&now-0.00002<=dis_r) ans++;
}
    cout<<ans<<endl;
    return 0;
}
