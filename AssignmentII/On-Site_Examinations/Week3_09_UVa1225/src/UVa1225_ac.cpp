#include <bits/stdc++.h>
using namespace std;
int main(){
	int n=0;
	cin >> n;
	vector<int> vec;
	while(n--){
		vec.assign(10, 0);
		int num=0;
		cin >> num;
		for (int i=0; i<=num; i++){
			int k=i;
			while(k != 0){
			int p=k%10;
			vec[p] += 1;
			k = k/10;
			}
		}
		for (int i=0; i<10; i++){
			cout << vec[i];
			if(i!=9){
				cout << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
