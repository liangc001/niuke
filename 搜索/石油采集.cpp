#include<bits/stdc++.h>

using namespace std;

int t;
int n;
int sum,ans1,ans2;
char mp[110][110];
int mx[5]={0,0,0,1,-1};
int my[5]={0,1,-1,0,0};

inline void dfs(int x,int y){
	if(x<1||x>n||y<1||y>n||mp[x][y]!='#') return;
	if((x+y)%2==0) ans1++;
	else ans2++;
	mp[x][y]='.';
	for(int i=1;i<=4;++i){
		dfs(x+mx[i],y+my[i]);
	}
}

int tim=0; 

signed main(){
    cin>>t;
    while(t--){
    	tim++;
        cin>>n;
        for(int i=1;i<=n;++i){
            string s;
            cin>>s;
            for(int j=0;j<s.size();++j){
                mp[i][j+1]=s[j];
            }
        }
        sum=0;
        for(int i=1;i<=n;++i){
        	for(int j=1;j<=n;++j){
        		if(mp[i][j]=='#'){
        			ans1=0; ans2=0;
        			dfs(i,j);
        			sum+=min(ans1,ans2);
				}
			}
		}
		cout<<"Case "<<tim<<": "<<sum<<endl;
//		cout<<sum<<endl;
    }
    return 0;
}
