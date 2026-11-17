#include <bits/stdc++.h>
using namespace std;
int n=0, buf=0;
vector<int> vec;
int main(){
	
	while(cin >> n){
		if(n==0){
			cout << "Minimum exchange operations : 0" << endl;
			continue;
		}
		vec.assign(n, 0);
		for (int i=0; i<n; i++){
			cin >> buf;
			vec[i] = buf;
		}
		int ans=0;
		for (int i=0; i<n; i++){
			if(vec[i] > vec[n-1]){
				for (int j=i; j<(n-i)/2+i; j++){
					swap(vec[j], vec[n-1-j]);
				}
				ans += 1;
			}
		}
		cout << "Minimum exchange operations : " << ans << endl;
	}

	return 0;
}
