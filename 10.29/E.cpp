#include <bits/stdc++.h>
using namespace std;

inline int read(){
	int x=0,t=1; char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	return x*t;
}

string s;
int ho,mi;
int ho_l[3];
int mi_l[3];

signed main(){
    cin>>s;
    for(int i=0;i<s.size();++i){
        if(i<=1){
            ho=ho*10+s[i]-'0';
        }
        else if(i>2&&i<=4){
            mi=mi*10+s[i]-'0';
        }
    }
    int now_mi=mi; 
    int now_ho=ho;
    bool flag=0;
    while(1){
        for(int i=now_ho;i>=0;--i){
            for(int j=(i==ho?mi-1:59);j>=0;--j){
                int kk=j;
                int zz=i;
                bool flag_ne=0;
                for(int q=1;q<=2;++q){
                    mi_l[q]=kk%10; kk/=10;
                }
                for(int q=2;q>=1;--q){
                    if(mi_l[q]!=zz%10){
                        flag_ne=1;
                        break;
                    }
                    zz/=10;
                }
                if(flag_ne==0){
                    flag=1;
                    cout<<i<<":"<<j<<endl;
                }
            }
            if(flag==1){
                break;
            }
        }
        if(flag==1){
            break;
        }
        if(now_ho==0){
            now_ho=23;
        }
    }
    flag=0;
    now_mi=mi; 
    now_ho=ho;
    while(1){
        for(int i=now_ho;i<=23;++i){
            for(int j=(i==ho?mi+1:0);j<60;++j){
                int kk=j;
                int zz=i;
                bool flag_ne=0;
                for(int q=1;q<=2;++q){
                    mi_l[q]=kk%10; kk/=10;
                }
                for(int q=2;q>=1;--q){
                    if(mi_l[q]!=zz%10){
                        flag_ne=1;
                        break;
                    }
                    zz/=10;
                }
                if(flag_ne==0){
                    flag=1;
                    cout<<i<<":"<<j<<endl;
                }
            }
            if(flag==1){
                break;
            }
        }
        if(flag==1){
            break;
        }
        if(now_ho==23){
            now_ho=0;
        }
    }
    return 0;
}
