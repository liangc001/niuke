#include <bits/stdc++.h>
using namespace std;

inline int read(){
	int x=0,t=1; char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	return x*t;
}

signed main(){
	while(1){
		system("data.exe > data.txt");
		system("E.exe < data.txt > e.txt");
		FILE *fp;
		fp=fopen("e.txt","r");
		int n;
		fscanf(fp,"%d",n);
		if(n>75){
			cout<<n<<endl; break;
		}
		else{
			cout<<"YES"<<endl;
		}
	}
	return 0;
}
