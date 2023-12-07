#include <bits/stdc++.h>
using namespace std;

inline int read(){
	int x=0,t=1; char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	return x*t;
}

int n,q;


signed main(){
	srand(time(0));
	n=rand()%100+1; q=rand()%100+1;
	cout<<n<<" "<<q<<endl;
	for(int i=1;i<=n;++i){
		int x=rand()%10000+1;
		cout<<x<<" ";
	}
	cout<<endl;
	for(int i=1;i<=q;++i){
		int opt=rand()%2+1;
		cout<<opt<<" ";
		if(opt==1){
			int pos=rand()%n+1; int num=rand()%10000+1;
			cout<<pos<<" "<<num;
		}
		else{
			int l=rand()%n+1;
			int r=0;
			while(r<l){
				r=rand()%n+1;
			}
			cout<<l<<" "<<r;
		}
		cout<<endl;
	}
	return 0;
}
