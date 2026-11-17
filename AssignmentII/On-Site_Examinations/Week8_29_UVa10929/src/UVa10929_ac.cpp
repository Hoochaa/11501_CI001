#include <bits/stdc++.h>
using namespace std;
int main(){
	string s="";
	//1=49
	while(cin >> s && s!="0"){
		int l=0, r=0;
		for (int i=0; i<s.size(); i++){
			int num = int(s[i])-48;
			if(i%2==0){
				l += num;
			}else{
				r += num;
			}
		}
		if(abs(l-r)%11==0){
			cout << s << " is a multiple of 11." << endl;
		}else{
			cout << s << " is not a multiple of 11." << endl;
		}
	}
	return 0;
}
