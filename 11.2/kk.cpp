#include <bits/stdc++.h>
using namespace std;

inline int read(){
	int x=0,t=1; char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	return x*t;
}

string s2;
char s1[2000];
int f[2000][2000];

signed main(){
    while(scanf("%s",s1)!=-1){
    memset(f,0,sizeof(f));
        for(int i=0;i<strlen(s1);++i){
            if(s1[i]>='A'&&s1[i]<='Z')
                s2[i]=s1[i]+32;
            else s2[i]=s1[i];
        }
    for(int i=0;i<strlen(s1);++i) f[i][i]=1;
    for(int i=1;i<strlen(s1);++i){
        int tmp=0;
        for(int j=0;j+i<strlen(s1);++j){
            if(s2[j]==s2[j+i]){
                tmp=f[j+1][j+i-1]+2;
            }
            else{
                tmp=max(f[j+1][j+i],f[j][j+i-1]);
            }
            f[j][j+i]=tmp;
        }
    }
    cout<<strlen(s1)-f[0][strlen(s1)-1]<<endl;
    }
    return 0;
}
