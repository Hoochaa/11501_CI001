#include <bits/stdc++.h>
using namespace std;
int main(){
	int n=0;
	cin >> n;
	while(n--){
		long long G=0, L=0;
		cin >> G >> L;
		if(L%G != 0){
			cout << -1 << endl;
			continue;
		}
		cout << G << " " << L << endl;
	}
	return 0;
}
