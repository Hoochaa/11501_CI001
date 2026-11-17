#include <bits/stdc++.h>
using namespace std;
int main(){
	int l=0, r=0, buf=1;
	vector<int> vec;
	vec.assign(100001, 0);
	for(int i=1; i<int(pow(100000, 0.5)); i++){
		vec[i*i] = 1;
	}
	
	while(cin >> l >> r){
		int ans =0;
		if(l==0 && r==0)break;
		for (int i=l; i<r+1; i++){
			ans += vec[i];
		}
		cout << ans << endl;
	}
	
	/*
	for(int i=1; i<100002; i++){
		vec[i] = vec[i-1] + vec[i];
		cout << vec[i] << " ";
	}
	cout << endl;
	int ans=0;
	while(cin >> l >> r){
		if(l==0 && r==0) break;
		if(l==0)l=1;
		ans = vec[r] - vec[l-1];
		cout << ans << endl;
	}
	*/
	return 0;
}
