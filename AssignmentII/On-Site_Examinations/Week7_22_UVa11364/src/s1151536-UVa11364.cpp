#include <bits/stdc++.h>
using namespace std;
int main(){
	int n=0;
	cin >> n;
	while(n--){
		int k=0;
		cin >> k;
		vector<int> vec;
		int buf=0;
		for (int i=0; i<k; i++){
			cin >> buf;
			vec.push_back(buf);
		}
		sort(vec.begin(), vec.end());
		int l=vec[0], r=vec[vec.size()-1], mid=vec[(vec.size()-1)/2];
		cout << (mid-l + r-mid)*2 << endl; 
	}
	return 0;
}
