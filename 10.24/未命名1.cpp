#include <bits/stdc++.h>
using namespace std;

inline int read(){
	int x=0,t=1; char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	return x*t;
}

#define maxn 1000010
int cnt;
char a[maxn];
int n,sum;

inline void dfs(int now){
	if(sum==n){
		for(int i=1;i<=cnt;++i){
        	cout<<a[i];
    	}
    	//return 0;
    	goto ::here;
	} 
    if(sum>n){
        return ;
    }
    a[++cnt]='N'; sum=2*sum+1;
    dfs(now+1);
    cnt--;
    a[++cnt]='G';
    sum=(sum-1)/2;
    sum=sum*2+2;
    dfs(now+1);
    cnt--;
    sum=(sum-2)/2;
}

signed main(){
    n=read();
    dfs(1);
    here;
    return 0;
}
