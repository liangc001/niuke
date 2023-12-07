#include<bits/stdc++.h>

using namespace std;

int n;
bool flag=0;
int ls[110];
int s;
int mo[110];
int o;
int a[20][20];

signed main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin>>a[i][j];
        }
    }
    if(n==2){
    	int o1[5]={0,1,2,3,4};
    	int o2[5]={0,3,1,4,2};
    	int o3[5]={0,2,4,1,3};
    	int o4[5]={0,4,3,2,1};
    	int ok=1;
    	for(int i=1;i<=n;++i){
    		for(int j=1;j<=n;++j){
    			if(a[i][j]!=o1[ok]){
    				 flag=1;break;
				}
				ok++;
			}
		}
		if(flag==0){
			cout<<"YES"<<endl; return 0;
		}
		flag=0;
		ok=1;
		for(int i=1;i<=n;++i){
    		for(int j=1;j<=n;++j){
    			if(a[i][j]!=o2[ok]){
    				 flag=1;break;
				}
				ok++;
			}
		}
		if(flag==0){
			cout<<"YES"<<endl; return 0;
		}
		flag=0;
		ok=1;
		for(int i=1;i<=n;++i){
    		for(int j=1;j<=n;++j){
    			if(a[i][j]!=o3[ok]){
    				 flag=1;break;
				}
				ok++;
			}
		}
		if(flag==0){
			cout<<"YES"<<endl; return 0;
		}
		flag=0;
		ok=1;
		for(int i=1;i<=n;++i){
    		for(int j=1;j<=n;++j){
    			if(a[i][j]!=o4[ok]){
    				 flag=1;break;
				}
				ok++;
			}
		}
		if(flag==0){
			cout<<"YES"<<endl; return 0;
		}
		cout<<"NO"<<endl;
		return 0;
	}
    int cnt=n+2;
    for(int i=2;i<=n-1;++i){
        for(int j=2;j<=n-1;++j){
            if(a[i][j]!=cnt){
                flag=1; break;
            }
            cnt++;
        }
        if(flag==1) break;
        cnt+=2;
    }
    if(flag==1){
        cout<<"NO"<<endl;
        return 0;
    }
    int l=1,r=n;
    for(int i=l;i<=r;++i){
        ls[++s]=i;
    }
    for(int i=1;i<=n-1;++i){
        r=r+n;
        ls[++s]=r;
    }
    for(int i=1;i<=n-1;++i){
        r=r-1;
        ls[++s]=r;
    }
    for(int i=1;i<=n-2;++i){
        r=r-n;
        ls[++s]=r;
    }
    for(int i=1;i<=s;++i){
        ls[s+i]=ls[i];
    }
    int x=1,y=1;
    bool kk=0;
    while(1){
        mo[++o]=a[x][y];
        if(x==1){
            if(y==n){
                x++; continue;
            }
            y++;
        }
        else if(y==n){
            if(x==n){
                y--; continue;
            }
            x++;
        }
        else if(x==n){
            if(y==1){
                x--;continue;
            }
            y--;
        }
        else if(y==1){
            x--;
        }
        if(y==1&&x==1&&kk==1){
            break;
        }
        kk=1;
    }
    int be=0;
    for(int i=1;i<=s;++i){
    	if(ls[i]==mo[1]){
    		be=i; break;
		}
	}
	if(be==0){
		flag=1;
	}
	if(flag==1){
        cout<<"NO"<<endl;
        return 0;
    }
    for(int i=1;i<=o;++i){
    	if(mo[i]!=ls[be+i-1]){
    		flag=1; break;
		}
	}
	if(flag==1){
        cout<<"NO"<<endl;
        return 0;
    }
    else cout<<"YES"<<endl;
    return 0;
}
