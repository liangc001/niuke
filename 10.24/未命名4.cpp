#include <bits/stdc++.h>
using namespace std;

inline int read(){
	int x=0,t=1; char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	return x*t;
}

#define maxn 100
int n;
int a[maxn][maxn];

signed main(){
    n=read();
    if(n==1){
    	cout<<1<<endl;
    	return 0;
	}
    int num=n%2==0?n/2:n/2+1;
    int now=1;
    for(int k=1;k<=num;++k){
        int l=k,r=n-k+1,u=k,d=n-k+1;
        int i=k,j=k;
        bool flag=0;
        while(1){
        	if(i>d){
			i--,j--;continue;}
        	if(j<l){
			j++,i--;continue;}
        	if(j>r){
			j--,i++;continue;}
        	if(i<u)break;
        	if(i==k&&j==k&&flag==1) break;
            if(i==u&&j<=r&&j>=l){
                a[i][j]=now;
                flag=1;
            now++;
                j++;continue;
            }
            else if(j==r&&i<=d&&i>=u){
                a[i][j]=now;
            now++;
                i++;continue;
            }
            else if(i==d&&j<=r&&j>=l){
                a[i][j]=now;
            now++;
                j--;continue;
            }
            else if(j==l&&i<=d&&i>=u){
                a[i][j]=now;
            now++;
                i--;continue;
            }
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
