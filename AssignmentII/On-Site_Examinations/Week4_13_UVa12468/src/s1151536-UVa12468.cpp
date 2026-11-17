#include <bits/stdc++.h>
using namespace std;
int main(){
	int a=0, b=0;
	while(cin >> a >> b){
		if ((a==-1)&&(b==-1)){
			break;
		}
		vector<int> ans;
		ans.assign(4, 0);
		ans[0] = abs(b-a);
		ans[1] = abs(a-b);
		ans[2] = abs(100-a+b);
		ans[3] = abs(100-b+a);
		sort(ans.begin(), ans.end());
		cout << ans[0] << endl;
	}
	return 0;
}
