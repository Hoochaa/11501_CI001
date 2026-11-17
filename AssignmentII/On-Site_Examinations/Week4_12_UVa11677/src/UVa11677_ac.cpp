#include <bits/stdc++.h>
using namespace std;
int main(){
	int a=0, b=0, c=0, d=0;
	while(cin >> a >> b >> c >> d){
		if((a==0)&&(b==0)&&(c==0)&&(d==0)){
			break;
		}
		int t1 = a*60+b;
		int t2 = c*60+d;
		int ans = 0;
		if (t1>t2){
			ans = 24*60-t1+t2;
		}else{
			ans = t2-t1;
		}
		cout << ans << endl;
	}
	return 0;
}
