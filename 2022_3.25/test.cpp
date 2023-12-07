#include<bits/stdc++.h>
using namespace std;


signed main(){
	while(1){
		system("data.exe > data.txt");
		system("A.exe < data.txt > a.txt");
		system("A2.exe < data.txt > a2.txt");
		if(system("fc a.txt a2.txt")) break;
	}
	return 0; 
}
