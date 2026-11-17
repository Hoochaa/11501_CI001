#include <bits/stdc++.h>
using namespace std;
int main(){
	long long s=0;
	while(cin >> s && s!=0){
		if(s%11 == 0 && s>=11){
			cout << s << " is a multiple of 11." << endl;
		}else{
			cout << s << " is not a multiple of 11." << endl;
		}
	}
	return 0;
}
