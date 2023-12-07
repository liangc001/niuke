#include<bits/stdc++.h>
#define SIZE 1005
using namespace std;
int x[SIZE],y[SIZE],xx[SIZE],yy[SIZE],n,flag;
string s,t;
void converts(int *a){
	for(int i=0;i<SIZE;i++) a[i]=0;
}
void add(int *a,int *b){
	for(int i=0;i<SIZE;i++)
		if((a[i]+=b[i])>=16){
			a[i+1]++; 
			a[i]-=16;
		}
}
int main(){
	cin>>n;
	while(n--){
		cin>>s>>t;
		flag=0;
		int ls=s.size(),lt=t.size();
		converts(x);
		converts(y);
		converts(xx);
		converts(yy);
		for(int i=0;i<ls;i++){
			if(s[i]>='0'&&s[i]<='9'){
				x[ls-i-1]=xx[ls-i-1]=s[i]-'0';
			}else{
				x[ls-i-1]=xx[ls-i-1]=s[i]-'A'+10;
			}
		}
		for(int i=0;i<lt;i++){
			if(t[i]>='0'&&t[i]<='9'){
				y[lt-i-1]=yy[lt-i-1]=t[i]-'0';
			}else{
				y[lt-i-1]=yy[lt-i-1]=t[i]-'A'+10;
			}
		}
//		for(int i=20;i>=0;i--) cout<<x[i];
//		cout<<endl;
//		for(int i=20;i>=0;i--) cout<<y[i];
//		cout<<endl;
		add(x,xx);
		converts(xx);
		xx[0]=5;
		add(x,xx);
		add(y,yy);
		add(y,yy);
//		for(int i=20;i>=0;i--) cout<<x[i];
//		cout<<endl;
//		for(int i=20;i>=0;i--) cout<<y[i];
//		cout<<endl;
		for(int i=SIZE-1;i>=0;i--){
			if(x[i]>y[i]){
				flag=1;
				break;
			}else if(x[i]<y[i]){
				break;
			}
		}
		if(flag) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}