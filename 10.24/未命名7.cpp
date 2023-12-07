#include <bits/stdc++.h>
using namespace std;

inline int read(){
	int x=0,t=1; char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	return x*t;
}
char qq;
char s[10010];
bool flag=0;
int nn,xi,tim;
signed main(){
    scanf("%s",s+1);
    int num=0,f=0;
    for(int i=0;i<=strlen(s+1);++i){
        if(s[i]=='='){
            tim=i+1;
            flag=1; continue;
        }
        if(flag==0){
            if(s[i]=='+'||(i==0&&s[1]!='-')){
                f=1;
            }
            if(s[i]=='-'){
                f=-1;
            }
            if(s[i]<='9'&&s[i]>='0'){
                num=num*10+s[i]-48;
            }
            if((s[i+1]>'9'||s[i+1]<'0')&&s[i+1]!='-'&&s[i+1]!='+'&&s[i+1]!='='&&i+1<=strlen(s+1)){
                qq=s[i+1];
                if(num==0) num=1;
				xi+=(-1)*f*num;
                num=0;i++;
            }
            if(s[i+1]=='-'||s[i+1]=='+'||s[i+1]=='='||i+1>strlen(s+1)){
                nn+=f*num;num=0;
            }
        }
        else{
            if(s[i]=='+'||(i==tim&&s[tim]!='-')){
                f=1;
            }
            if(s[i]=='-'){
                f=-1;
            }
            if(s[i]<='9'&&s[i]>='0'){
                num=num*10+s[i]-48;
            }
            if((s[i+1]>'9'||s[i+1]<'0')&&s[i+1]!='-'&&s[i+1]!='+'&&s[i+1]!='='&&i+1<=strlen(s+1)){
            	if(num==0) num=1;
                qq=s[i+1];
                xi+=f*num;num=0;i++;
            }
            if(s[i+1]=='-'||s[i+1]=='+'||s[i+1]=='='||i+1>strlen(s+1)){
                nn+=(-1)*f*num;num=0;
            }
        }
    }
    bool flag=0;
    if((nn<0&&xi<0)||(nn>0&&xi>0)){
        flag=1;
    }
    nn=abs(nn); xi=abs(xi);
    if(nn==0){
    	printf("%c=0.000\n",qq);
    	return 0;
	}
    if(flag==1)printf("%c=%.3lf\n",qq,double(nn)/double(xi));
    else printf("%c=-%.3lf\n",qq,double(nn)/double(xi));
    return 0;
}
