#include<bits/stdc++.h>


using namespace std;



signed main(){
    while(1){
        system("data.exe > data.txt");
        system("C.exe < data.txt > c.txt");
        system("cc.exe < data.txt > cc.txt");
        if(system("fc c.txt cc.txt")){
            break;
        }
    }
    return 0;
}