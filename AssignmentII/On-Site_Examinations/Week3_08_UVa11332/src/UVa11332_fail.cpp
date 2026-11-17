#include <bits/stdc++.h>
using namespace std;
int main(){
	int n=0;
	while(cin >> n){
		int ans=0;
		while(true){
			ans += n%10;
			if (n==ans){break;}
			n = n/10;
			if(n==0){n=ans; ans=0;}
		}
		cout << ans << endl;
	}
	return 0;
}
