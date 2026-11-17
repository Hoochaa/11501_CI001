#include <bits/stdc++.h>
using namespace std;
int main(){
	int sin=0, pur=0;
	string s="";
	while(getline(cin ,s)){
		for (char c : s){
			if(int(c) == 39){
				if(sin%2==0){
					cout << "`";
				}else{
					cout << "'";
				}
				sin++;
			}else if (int(c) == 34){
				if(pur%2==0){
					cout << "``";
				}else{
					cout << "''";
				}
				pur++;
			}else{
				cout << c;
			}
		}
		cout << endl;
	}
}
