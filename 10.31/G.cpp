#include <bits/stdc++.h>
using namespace std;

inline int read(){
	int x=0,t=1; char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	return x*t;
}

int mon_run[15]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int mon_pin[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};
string s1,s2;
int l_ye,l_mo,l_da;
int r_ye,r_mo,r_da;
int zan[5],cnt;

inline bool check(int ye,int mo,int da){
    memset(zan,0,sizeof(zan)); cnt=0;
    bool flag_now=0;
    for(int i=1;i<=2;++i){
        zan[++cnt]=da%10; da/=10;
    }
    for(int i=1;i<=2;++i){
        zan[++cnt]=mo%10; mo/=10;
    }
    for(int i=4;i>=1;--i){
        if(zan[i]!=ye%10){
            flag_now=1; break;
        }
        else ye/=10;
    }
    if(flag_now==1) return false;
    else return true;
}

signed main(){
    cin>>s1; cin>>s2;
    for(int i=0;i<s1.size();++i){
        if(i<4) l_ye=l_ye*10+s1[i]-'0';
        else if(i>=4&&i<6) l_mo=l_mo*10+s1[i]-'0';
        else l_da=l_da*10+s1[i]-'0';
    }
    for(int i=0;i<s2.size();++i){
        if(i<4) r_ye=r_ye*10+s2[i]-'0';
        else if(i>=4&&i<6) r_mo=r_mo*10+s2[i]-'0';
        else r_da=r_da*10+s2[i]-'0';
    }
    int now_ye=l_ye; int now_mo=l_mo; int now_da=l_da;
    int ans=0; bool flag=0;
    while(1){
        if((now_ye%4==0&&now_ye%100!=0)||now_ye%400==0){
            for(int i=1;i<=mon_run[now_mo];++i){
                if(check(now_ye,now_mo,i)) ans++;
                if(now_ye==r_ye&&now_mo==r_mo&&i==r_da){
                    flag=1; break;
                }
            }
        }
        else{
            for(int i=1;i<=mon_pin[now_mo];++i){
                if(check(now_ye,now_mo,i)) ans++;
                if(now_ye==r_ye&&now_mo==r_mo&&i==r_da){
                    flag=1; break;
                }
            }
        }
        if(flag==1){
            break;
        }
        if(now_mo==12) now_mo=1,now_ye++;
        else now_mo++;
    }
    cout<<ans<<endl;
    return 0;
}
