#include <bits/stdc++.h>
using namespace std;
int main(){
	int n=0;
	while(cin>>n){
		if(n==0){
			break;
		}
		if (n!=0){
		int dx=0, dy=0;
		cin >> dx >> dy;
		for (int i=0; i<n; i++){
			int x=0, y=0;
			cin >> x >> y;
			if(dx==x or dy==y){
				cout << "divisa" << endl;
			}else if(dx<x && dy<y){
				cout << "NE" << endl;
			}else if(dx>x && dy<y){
				cout << "NO" << endl;
			}else if(dx>x && dy>y){
				cout << "SO" << endl;
			}else{
				cout << "SE" << endl;
			}
			
		}
		}
	}
	return 0;
}
