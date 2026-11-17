#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	while(getline(cin, s)){
		if(s==""){
			cout << endl;
			continue;
		}
		for (char c : s){
			cout << char((int(c)-7));
		}
		cout << endl;
	}
	return 0;
}
