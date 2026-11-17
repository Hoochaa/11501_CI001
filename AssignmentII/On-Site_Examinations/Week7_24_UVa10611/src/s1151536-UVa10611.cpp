#include <bits/stdc++.h>
using namespace std;
int l, r;
int n, m, buf;
vector<long long> lady;
int bsearch(long long x){
	l=0; r=n-1;
	int mid=0;
	while(l<r){
		mid = (l+r)/2;
		if(lady[mid] == x){
			l = mid-1;
			r = mid+1;
			return 0;
		}
		if(lady[mid] > x){
			r = mid - 1; 
		}else if(lady[mid] < x){
			l = mid + 1;
		}
	}
	l=mid;
	r=mid+1;
	return 0;
}

int main(){
	cin >> n;
	if(n==0){
		cout << "X X" << endl;
		return 0;
	}
	for(int i=0; i<n; i++){
		cin >> buf;
		lady.push_back(buf);
	}
	sort(lady.begin(), lady.end());
	cin >> m;
	for(int i=0; i<m; i++){
		long long buf=0;
		cin >> buf;
		if(buf < lady[0]){
			cout << "X " << lady[0] << endl;
			continue; 
		}else if(buf > lady[n-1]){
			cout << lady[n-1] << " X" << endl;
			continue; 
		}
		bsearch(buf);
		cout << lady[l] << " " << lady[r] << endl;
	}
	return 0;
}
