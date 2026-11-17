#include <bits/stdc++.h>
using namespace std;

int main(){
	int n=0;
	cin >> n;
	cin.ignore();
	string s="";
	while(n--){
		map<string, float> mp;
		int num=0;
		while(getline(cin, s) && s!=""){
			if(!mp[s])mp[s] = 0;
			mp[s]++;
			num++;
		}
		for (auto a : mp){
			cout << fixed << setprecision(4) << a.first << " " << a.second/num*100.0 << endl;
		}
		if(n!=0)cout << endl;
	}
	return 0;
}
