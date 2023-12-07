#include<iostream>
#include<cstdio>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int lena,lenc;
char a[1001],b[1001],c[1001];
int main(){
	cin>>a>>b>>c;
    lena=strlen(a)-1;
    lenc=strlen(c);
    for(int i=0;i<lena;i++){ 
        if(a[i]==a[i+1]){
            if(b[i]!=b[i+1]){
                printf("Failed");
                return 0;
            }
        }
        if(b[i]==b[i+1]){
            if(a[i]!=a[i+1]){
                printf("Failed");
                return 0;
            }
        }
    }
    if(lena+1<26){
        printf("Failed");
        return 0;
    }
    for(int i=0;i<lenc;i++){
        for(int j=0;j<lena;j++){
            if(c[i]==a[j]){
                printf("%c",b[j]);
                break;
            }
        }
    }
    return 0;
}
