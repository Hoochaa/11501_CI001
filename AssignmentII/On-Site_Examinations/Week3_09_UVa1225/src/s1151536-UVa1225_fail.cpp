#include <bits/stdc++.h>
using namespace std;
int main(){
	int a=0, b=0;
	while(cin >> a >>  b){
		if (a==0 && b==0){break;}
		int ans=0;
		while(a!=0&&b!=0){
			ans += (a%10+b%10)/10;
			a /= 10;
			b /= 10;
		}
		if (ans==0){
			cout << "No carry operation." << endl;
		}else{
			cout << ans << " carry operation." << endl;
		}
	}
	return 0;
}
