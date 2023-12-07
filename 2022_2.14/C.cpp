#include <bits/stdc++.h>
using namespace std;

inline int read(){
	int x=0,t=1; char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	return x*t;
}

int t;
int n;
int a[10];
priority_queue<int,vector<int>,less<int> > q1;
priority_queue<int,vector<int>,greater<int> > q2;

signed main(){
    t=read();
    while(t--){
        n=read();
        int sum=0;
        while(!q1.empty()) q1.pop();
        while(!q2.empty()) q2.pop();
        for(int i=1;i<=n;++i){
            a[i]=read();
        }
        sort(a+1,a+1+n);
        sum++;
        for(int i=2;i<=n;++i){
            if(a[i]-a[i-1]<=2){
                sum++;
            }
            else{
                cout<<sum<<endl;
                q1.push(sum);
                q2.push(sum);
                sum=1;
            }
        }
        cout<<endl;
        //cout<<q1.top()<<" "<<q2.top()<<endl;
    }
    return 0;
}
