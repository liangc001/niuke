#include<bits/stdc++.h>

using namespace std;

int t,n,m,q;
int x,y,s;
int a[200010];

inline int p(int x,int y){
	return (x-1)*m+y;
} 

signed main(){
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
    	cin>>n>>m>>q;
    	for(int i=1;i<=n;++i){
    		for(int j=1;j<=m;++j){
    			a[p(i,j)]=0;
			}
		}
		for(int i=1;i<=q;++i){
			cin>>x>>y>>s;
			a[p(x,y)]++;
			for(int j=1;j<=s;j++){
                if(x-j>=1&&y-j>=1)
                    a[p(x-j,y-j)]++;
                else break;
            }
            for(int j=1;j<=s;j++){
                if(x-j>=1&&y+j<=m)
                  a[p(x-j,y+j)]++;
                else break;
            }
            for(int j=1;j<=s;j++){
                if(x+j<=n&&y-j>=1)
                    a[p(x+j,y-j)]++;
                else break;
            }
            for(int j=1;j<=s;j++){
                if(x+j<=n&&y+j<=m)
                    a[p(x+j,y+j)]++;
                else break;
            }
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				cout<<a[p(i,j)]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}
