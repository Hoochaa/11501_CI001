#include <bits/stdc++.h>
using namespace std;
int main(){
	int i=0;
	cin >> i;
	while(i--){
		long double n;
		cin >> n;
		n = (n * 0.4819277 + 4.13655);
		n = abs(int(n)%10);
		cout << n << endl;
	}
	return 0;
}
