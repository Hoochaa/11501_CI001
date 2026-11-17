#include <bits/stdc++.h>
using namespace std;
int main(){
	int n=0;
	cin >> n;
	for (int i=0; i<n; i++){
		int a=0, b=0, c=0;
		cin >> a >> b >> c;
		if (b<c){swap(b, c);}
		if (a<c){swap(a, c);}
		if (a<b){swap(a, b);}
		cout << "Case " << i+1 << ": " << b << endl;
	}
	return 0;
}
