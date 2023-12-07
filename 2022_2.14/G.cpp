#include <bits/stdc++.h>
using namespace std;

inline int read(){
	int x=0,t=1; char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	return x*t;
}

string s;
int be;
long long sum;

signed main(){
	cin>>s;
	if(s[0]=='-') be=1;
	else be=0;
	bool flag=0;
	for(int i=be;i<s.size();++i){
		sum=sum*10+(s[i]-'0');
		if(sum>9223372036854775807){
			flag=1; break;
		}
	}
	if(flag==1){
		cout<<"BigInteger";
	}
	else if(sum<=9223372036854775807){
		cout<<"long";
	}
	else if(sum<=2147483647){
		cout<<"int";
	}
	else if(sum<=32768){
		cout<<"short";
	}
	else{
		cout<<"byte";
	}
	return 0;
}
