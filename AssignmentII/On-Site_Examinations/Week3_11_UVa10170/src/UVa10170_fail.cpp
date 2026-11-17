#include <bits/stdc++.h>
using namespace std;
int main(){
	int a=0, b=0;
	while(cin >> a >> b){
		a--;
		while(b>0){
			a++;
			b -= a;
		}
		cout << a << endl;
	}
	return 0;
}
