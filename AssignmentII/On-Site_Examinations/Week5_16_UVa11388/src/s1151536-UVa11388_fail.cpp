#include <bits/stdc++.h>
using namespace std;
int main(){
	int n=0;
	cin >> n;
	while(n--){
		long long G=0, L=0;
		cin >> G >> L;
		vector<long long> vec;
		for (int i=G; i*G<=L; i++){
			vec.push_back(i*G);
		}
		if(vec.size()<2){
			cout << -1 << endl;
		}
		cout << vec[0] << " " << vec[-1] << endl;
	}
	return 0;
}
