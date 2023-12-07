#include<bits/stdc++.h>
#include<time.h>
using namespace std;

signed main(){
	srand(time(0));
	int n=rand()%10+1; int k=rand()%n+1;
	cout<<n<<" "<<k<<endl;
	for(int i=1;i<=n;++i){
		int x=rand()%9+1;
		cout<<x<<" ";
	}
	return 0;
} 
