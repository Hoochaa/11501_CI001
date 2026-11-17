#include <bits/stdc++.h>
using namespace std;
int main(){
	int n = 0;
	cin >> n;
	for (int i=0; i<n; i++){
		int a=0, b=0;
		cin >> a >> b;
		if(a > b){
			cout << ">" << endl;
		}else if(a<b){
			cout << "<" << endl;
		}else{
			cout << "=" << endl;
		}
	}
	return 0;
}
