#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	while(getline(cin, s)){
		vector<int> A;
		vector<int> B;
		stringstream ss(s);
		int i=0;
		while(ss >> i){
			A.push_back(i);
		}
		getline(cin, s);
		stringstream sss(s);
		while(sss >> i){
			B.push_back(i);
		}
		vector<int> a;
		bool check=false;
		if (A.size()<B.size()){
			check = true;
			a = A;
			A = B;
			B = a;
		}else{
			a = B;
		}
		
		int ct = 0;
		for(int j : a){
			for(int k : A){
				if(j==k){
					ct++;
				}
			}
		}
		
		if(ct==0){
			cout << "A and B are disjoint" << endl;
		}else if(A.size() == a.size() && ct == A.size()){
			cout << "A equals B" << endl;
		}else if(a.size() < A.size() && !check && ct == a.size()){
			cout << "B is a proper subset of A" << endl;
		}else if(a.size() < A.size() && check && ct == a.size()){
			cout << "A is a proper subset of B" << endl;
		}else{
			cout << "I'm confused!" << endl;
		}
	}
	return 0;
}
