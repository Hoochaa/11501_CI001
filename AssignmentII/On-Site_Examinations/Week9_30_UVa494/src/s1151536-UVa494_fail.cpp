#include <bits/stdc++.h>
using namespace std;
int main(){
	string s="";
	while(getline(cin, s)){
		stringstream ss(s);
		long long i=0;
		string voc="";
		while(ss >> voc){
			long long notAlp=0, alp=0;
			bool check=true;
			for (int i=0; i<voc.size(); i++){
				if((int('a')<=int(voc[i]) && int('z')>=int(voc[i])) || (int('A')<=int(voc[i]) && int('Z')>=int(voc[i]))){
					continue;
				}else{
					if(i!=voc.size()-1){
						check = false;
						break;
					}
				}
			}
			if(check)i++;
		}
		cout << i << endl;
	}
	return 0;
}
