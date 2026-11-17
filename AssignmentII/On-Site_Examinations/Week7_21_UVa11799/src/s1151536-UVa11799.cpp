#include <bits/stdc++.h>
using namespace std;
int main(){
	int n=0, cnt=0;
	cin >> n;
	cin.ignore();
	while(n--){
		cnt++;
		string s="";
		getline(cin, s);
		stringstream ss(s);
		int num=0, maxium=0;
		while(ss >> num){
			maxium = max(maxium, num);
		}
		cout << "Case " << cnt << ": " << maxium << endl;
	}
	return 0;
}
