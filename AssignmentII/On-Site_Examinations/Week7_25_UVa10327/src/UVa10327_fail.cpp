#include <bits/stdc++.h>
using namespace std;
int main(){
	int n=0, buf=0;
	vector<int> vec;
	while(cin >> n){
		vec.assign(n, 0);
		for (int i=0; i<n; i++){
			cin >> buf;
			vec[i] = buf;
		}
		int ans=0;
		for (int j=0; j<n-1; j++){
			for (int k=j+1; k<n; k++){
				if(vec[j] > vec[k]){
					ans++;
					swap(vec[j], vec[k]);
				}
			}
		}
		cout << "Minimum exchange operations : " << ans << endl;
	}

	return 0;
}
