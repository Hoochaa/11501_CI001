#include <bits/stdc++.h>
using namespace std;
int main(){
	string s="";
	string chars = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
	while(cin >> s){
		int n=s.size();
		for (int i=0; i<n; i++){
			if(s[i] == '0'){
				s[i] = 'O';
			}
		}
		
		bool PALINDROME=true;
		for (int i=0; i<n/2; i++){
			if(s[i] != s[n-i-1]){
				PALINDROME = false;
				break;
			}
		}
		
		bool mirror=true;
		for (int i=0; i<n/2; i++){
			char mirrored = ' ';
			if(s[i] >= int('A') && s[i] <= int('Z')){
				mirrored = chars[int(s[i])-int('A')];
			}else if(int(s[i])>=int('1') && int(s[i])<=int('9')){
				mirrored = chars[int(s[i])-int('1')+26];
			}else{
				mirror = false;
				break;
			}
			//cout << s[i] << " " << mirrored << endl;
			if(s[n-i-1] != mirrored){
				mirror = false;
				break;
			}
			
		}
		
		cout << s;
		if(PALINDROME && mirror){
			cout << " -- is a mirrored palindrome." << endl;
			continue;
		}
		if(!PALINDROME && !mirror){
			cout << "  -- is not a palindrome." << endl;
			continue;
		}
		if(!PALINDROME && mirror){
			cout << " -- is a mirrored string." << endl;
			continue;
		}
		if(PALINDROME && !mirror){
			cout << " -- is a regular palindrome." << endl;
			continue;
		}
	}
	return 0;
}
