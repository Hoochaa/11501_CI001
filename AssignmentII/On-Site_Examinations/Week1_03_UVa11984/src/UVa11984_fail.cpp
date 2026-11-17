#include<iostream>
using namespace std;
int main(){
	int c=0;
  	cin >> c;
  	long long C=0, F=0;
    float D=0;
  	for (int i=0; i<c; i++){
        cin >> C >> F;
    	float ans=0;
        D = C/5*9+32;
        D += F;
        D = (D-32)/9*5;
        int a = D*100;
        if(D-a>=0.5){
            a += 1;
        }
        ans = a *0.01;
      	cout << "Case " << i+1 << ": " << ans << endl;
    }
  return 0;
}
