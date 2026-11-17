#include <bits/stdc++.h>
using namespace std;
int main(){
	int a=0, b=0;
	while(cin >> a >> b){
		if (a==0 && b==0){
			break;
		}
		float r=pow(b, 0.5);
		float l=pow(a, 0.5);
		r = int(r);
		if(l>int(l)){
			l = int(l)+1;
		}else{
			l = int(l);
		}
		cout << (r-l+1) << endl;
	}
	return 0;
}
