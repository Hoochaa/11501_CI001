#include <bits/stdc++.h>
using namespace std;
int main(){
	int n=0;
	cin >> n;
	for (int i=0; i<n; i++){
		int a=0, b=0, c=0, d=0;
		cin >> a >> b >> c >> d;
		int m=0;
		if(a>m){m=a;}
		if(b>m){m=b;}
		if(c>m){m=c;}
		if(d>m){m=d;}
		if (a+b+c+d < m*2){
			cout << "banana" << endl;
		}else if (a==b && b==c && c==d){
			cout << "square" << endl;
		}else if((a==b && c==d)or(a==c && b==d)){
			cout << "rectangle" << endl;
		}else{
			cout << "quadrangle" << endl;
		}
	}
	return 0;
}
