#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n=0;
	while(cin >> n && n!=0){
		if(n==0){
			cout << 0 << endl;
			continue;
		}
		long long p=log(n)/log(2);
		int c=0;
		cout << "The parity of ";
		while(p>=0){
			long long num = pow(2, p);
			if(n/num==1)c++;
			cout << (n/num);
			n = n%num;
			p--;
		}
		cout << " is " << c << " (mod 2)." << endl;
	}
	return 0;
}
