#include <bits/stdc++.h>
using namespace std;
int main(){
	int n=0;
	cin >> n;
	while(n--){
		long long G=0, L=0;
		cin >> G >> L;
		vector<int> G_vec;
		vector<int> res;
		for (int i=1; i*G<=L; i++){
			G_vec.push_back(i*G);
		}
		for (int i=0; i<G_vec.size(); i++){
			if(L%G_vec[i]==0){
				res.push_back(G_vec[i]);
			}
		}
		sort(res.begin(), res.end());
		if(res.size()<2){
			cout << -1 << endl;
			continue;
		}
		cout << res[0] << " " << res[1] << endl;
		
	}
	return 0;
}
