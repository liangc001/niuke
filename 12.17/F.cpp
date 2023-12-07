#include <bits/stdc++.h>
using namespace std;

inline int read(){
	int x=0,t=1; char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	return x*t;
}

int n;
char s1[200010],s2[200010];
int kmp[200010],cnt;
int k;
int len1,len2;

inline bool check(){
    cnt=0;
//     for(int i=1;i<=k;++i) cout<<s3[i];
//     cout<<endl;
    for(int i=2;i<=strlen(s1+1);i++){
        while(cnt&&s1[i]!=s1[cnt+1]) cnt=kmp[cnt];
        if(s1[cnt+1]==s1[i]) cnt++;
        kmp[i]=cnt;
    }
    int sum=0;
    for(int i=1;i<=strlen(s2+1);i++){
        while(sum>0&&s2[sum+1]!=s1[i]) sum=kmp[sum];
        if(s2[sum+1]==s1[i]) sum++;
        if(sum==len2) {
            return 1;
            sum=kmp[sum];
        }
    }
    return 0;
}

signed main(){
    n=read();
    cin>>s1+1>>s2+1;
    bool f=0;
    len2=strlen(s2+1);
    for(int i=1;i<=len2;++i){
        s2[len2+(++k)]=s2[i];
    }
    if(check()){
         f=1; 
    }
    if(f==1){
        cout<<"wow"<<endl;
    }
    else{
        cout<<"TAT"<<endl;
    }
    return 0;
}
