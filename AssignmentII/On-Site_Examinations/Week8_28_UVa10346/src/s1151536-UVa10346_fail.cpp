#include <bits/stdc++.h>
using namespace std;
int n=0, k=0;
int main(){
	while(cin >> n >> k){
		if(n==0 || n==1){
			cout << n << endl;
			continue;	
		}
		int buts=0, ans=0;
		while(true){
			ans += n;
			buts += n;
			if(buts<k && n==0)break;
			n=buts/k;
			buts = buts%k;
		}
	}
	return 0;
}
