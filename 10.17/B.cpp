#include <bits/stdc++.h>
using namespace std;

inline int read(){
	int x=0,t=1; char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	return x*t;
}

int a[10]={0,1,2,3,4,5,6,7,8,9};

int sum;
int e,b,c,d;

signed main(){
	do{
//		for(register int i=1;i<=9;++i){
//			cout<<a[i]<<" ";
//		}
//		cout<<endl;
sum=e=b=c=d=0;
		for(int i=1;i<=4;++i){
			sum=sum*10+a[i];
		}
		e=a[5];
		for(register int i=6;i<=9;++i){
			b=b*10+a[i];
		}
		for(register int i=5;i<=6;++i){
			c=c*10+a[i];
		}
		for(register int i=7;i<=9;++i){
			d=d*10+a[i];
		}
		if(sum==e*b){
			printf("%d = %d x %d\n",sum,e,b);
		}
		if(sum==c*d){
			printf("%d = %d x %d\n",sum,c,d);
		}
//		if(sum==4396){
//			cout<<c<<" "<<d<<endl;
//			break;
//		}
	}while(next_permutation(a+1,a+10));
	return 0;
}
