#include <bits/stdc++.h>
using namespace std;

int GCD(int x, int y){
	if(y>x){
		swap(x, y);
	}
	if(x%y==0){
		return y;
	}
	x = x%y;
	return GCD(y, x);
}

int main(){
	int n=0;
	while(cin >> n){
		if(n==0){
			break;
		}
		int G=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				G+=GCD(i,j);
			}
		}
		cout << G << endl;
	}
	return 0;
}
