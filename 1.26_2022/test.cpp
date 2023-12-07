#include<bits/stdc++.h>

using namespace std;


signed main(){
    while(1){
        system("data.exe > data.txt");
        system("L1.exe < data.txt > L1.txt");
        system("L2.exe < data.txt > L2.txt");
        if(system("fc L1.txt L2.txt")){
            break;
        }
    }
    return 0;
}