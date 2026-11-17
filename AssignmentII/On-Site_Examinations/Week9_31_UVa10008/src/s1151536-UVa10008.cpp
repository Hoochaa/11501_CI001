#include <bits/stdc++.h>
using namespace std;
int main(){
	vector<vector<int>> vec;
	vector<int> buf;
	buf.assign(2, 0);
	vec.assign(26, buf);
	for (int i=25; i>=0; i--){
		vec[25-i][1] = i;
	}
	int n=0;
	cin >> n;
	cin.ignore();
	string s="";
	while(n--){
		getline(cin, s);
		if(s=="")continue;
		for (char c : s){
			if((int('a')<=int(c) && int('z')>=int(c)) || (int('A')<=int(c) && int('Z')>=int(c))){
				c = toupper(c);
				vec[int(c)-int('A')][0] += 1;
			}
		}
	}
	sort(vec.begin(), vec.end());
	for (int i=25; i>=0; i--){
		if(vec[i][0]>0){
			cout << char(abs(vec[i][1]-25)+int('A')) << " " << vec[i][0] << endl;
		}
	}
	return 0;
}
