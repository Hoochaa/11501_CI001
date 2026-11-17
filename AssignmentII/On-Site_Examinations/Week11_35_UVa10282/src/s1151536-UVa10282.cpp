#include <bits/stdc++.h>
using namespace std;
int main(){
	map<string, string> mp;
	string s="";
	while(getline(cin, s)){
		if(s=="")break;
		stringstream ss(s);
		string a="", b="";
		ss >> a >> b;
		mp[b] = a;
	}
	while(getline(cin, s)){
		if(mp[s] != ""){
			cout << mp[s] << endl;
		}else{
			cout << "eh" << endl;
		}
	}
	
	return 0;
}
