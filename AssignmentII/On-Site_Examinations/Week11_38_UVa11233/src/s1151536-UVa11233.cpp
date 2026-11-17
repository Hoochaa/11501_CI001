#include <bits/stdc++.h>
using namespace std;
int main(){
	int a, b;
	cin >> a >> b;
	map<string, string> mp;
	while(a--){
		string sa, sb;
		cin >> sa >> sb;
		mp[sa] = sb;
	}
	while(b--){
		string s;
		cin >> s;
		if(mp[s]!=""){
			cout << mp[s] << endl;
		}else if (s[s.size()-1] == 'y' && s[s.size()-2] != 'u' && s[s.size()-2] != 'a' && s[s.size()-2] != 'e' && s[s.size()-2] != 'i' && s[s.size()-2] != 'o'){
			s[s.size()-1] = 'i';
			cout << s << "es" << endl;
		}else if (s[s.size()-1] == 'o' || s[s.size()-1] == 's' || s[s.size()-1] == 'x'){
			cout << s << "es" << endl;
		}else if(s[s.size()-1]=='h' && (s[s.size()-2] == 's' || s[s.size()-2] == 'c')){
			cout << s << "es" << endl;
		}else{
			cout << s << "s" << endl;
		}
	}
	return 0;
}
