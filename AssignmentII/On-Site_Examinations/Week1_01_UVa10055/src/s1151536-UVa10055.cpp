#include <bits/stdc++.h>
using namespace std;
int main(){
	int a=0, b=0;
	while (cin >> a >> b){
    	if(a>b){
        	cout << a-b << endl;
        }else{
        	cout << b-a << endl;
        }
    }
  	return 0;
}
