#include<bits/stdc++.h>
#define maxm 1010
using namespace std;

string a,b;

inline bool comp(string st1,string st2){
	int len1=st1.size(); int len2=st2.size();
	if(len1!=len2) return len1<len2;
	for(int i=0;i<len1;++i){
		if(st1[i]!=st2[i]) return st1[i]<st2[i];
	}
	return false;
}//<(其余同理) 
inline string add(string str1,string str2){
	int sum[maxm],a[maxm],b[maxm];
	memset(sum,0,sizeof(sum));
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	int len1=str1.size(); int len2=str2.size();
	for(int i=1;i<=len1;++i) a[i]=str1[len1-i]-'0';
	for(int i=1;i<=len2;++i) b[i]=str2[len2-i]-'0';
	int lens=max(len1,len2);
	for(int i=1;i<=lens;++i){
		sum[i]+=a[i]+b[i];
		if(sum[i]>=10){
			sum[i]-=10;
			sum[i+1]++;
		}
	}
	while(sum[lens+1])lens++;
	string ans;
	for(int i=lens;i>=1;--i) ans+=sum[i]+'0';
	return ans;
}

signed main(){
    ios::sync_with_stdio(0);
    cin>>a>>b;
    cout<<add(a,b)<<endl;
    return 0;
}