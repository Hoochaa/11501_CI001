#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n=0;
	while(cin >> n && n>=0 && n<1000000001){
		if(n==0){
			cout << 0 << endl;
			continue;
		}
		long long p=log(n)/log(3);
		while(p>=0){
			long long num = pow(3, p);
			cout << (n/num);
			n = n%num;
			p--;
		}
		cout << endl;
	}
	return 0;
}
