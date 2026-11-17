#include <bits/stdc++.h>
using namespace std;
int main(){
	string t="";
	while(getline(cin, t)){
		if(t=="0:00"){
			break;
		}
		int a, b, c, d;
		if(t.size()==5){
			a=int(t[0]); b=int(t[1]); c=int(t[3]); d=int(t[4]);	
		}else{
			a=48; b=int(t[0]); c=int(t[2]); d=int(t[3]);
		}
		a-=48; b-=48; c-=48; d-=48;
		int h=a*10+b, m=c*10+d;
		float h_ang=h*30+m*0.5;
		float m_ang=m*6;
		float ang1=max(h_ang, m_ang);
		float ang2=min(h_ang, m_ang);
		float ans = min(ang1-ang2, 360-ang1+ang2);
		cout << fixed << setprecision(3) << ans << endl;
	}
	return 0;
}
