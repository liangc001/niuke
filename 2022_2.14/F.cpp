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
string ans;

bool flag=0;

signed main(){
	cin>>s;
	for(int i=1;i<s.size();++i){
		if(s[i]>='a'&&s[i]<='z'){
			flag=1; break;
		}
	}
	if(flag==1){
		ans=s;
	}
	else{
		for(int i=0;i<s.size();++i){
			if(s[i]>='a'&&s[i]<='z'){
				ans[i]=s[i]-'a'+'A';
			}
			else{
				ans[i]=s[i]-'A'+'a';
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
