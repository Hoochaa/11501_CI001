#include <bits/stdc++.h>
using namespace std;
int main(){
	int n=0;
	cin >> n;
	for (int i=0; i<n; i++){
		int num=0;
		vector<int> vec;
		cin >> num;
		for (int j=0; j<num; j++){
			int buf=0;
			cin >> buf;
			vec.push_back(buf);
		}
		int ans=0;
		for (int j=0; j<num-1; j++){
			for (int k=j+1; k<num; k++){
				if(vec[j] > vec[k]){
					ans++;
					swap(vec[j], vec[k]);
				}
			}
		}
		cout << "Optimal train swapping takes " <<  ans  << " swaps." << endl;
	}
	return 0;
}
