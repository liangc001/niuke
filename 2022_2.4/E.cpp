#include<bits/stdc++.h>
#define N 100
using namespace std;
typedef long long ll;
ll c[N],a[N],b[N],n,m,ans,k,cnt,res;
void pre(){
	ll mm=24;
	c[4]=1;
	for(ll i=5;i<=75;i++){
		mm*=i;
		mm/=i-4;
		c[i]=mm/24;
	}
}
int main(){
	pre();
//	for(ll i=4;i<=75;i++) cout<<c[i]<<" ";
//	cout<<endl;
	cin>>k;
	for(ll i=75;i>=4;i--){
		if(k>=c[i]){
			if(i>=65) continue;
			a[++cnt]=i;
			b[cnt]=k/c[i];
			k-=c[i]*b[cnt];
		}
	}
	n=a[1];
	m=a[1]*(a[1]-1)/2;
	b[1]--;
	for(ll i=1;i<=cnt;i++){
		n+=b[i];
		m+=b[i]*(a[i]-1);
	}
	cout<<n;
	return 0;
}
