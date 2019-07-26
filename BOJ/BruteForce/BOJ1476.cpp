#include <iostream>
using namespace std;

int main(){
	int e = 1, s = 1, m = 1; //지구, 태양, 달
	int endE, endS, endM;    //도달해야하는 목표치
	cin>>endE>>endS>>endM; 
	int year = 1;
	
	if(endE == 1 && endS == 1 && endM == 1){
		cout<<1;
		return 0;
	}
	
	
	while(true){
		year++; //1년씩 증가할 때마다 
		e++, s++, m++; //각 행성의 주기도 증가한다. 
		if(e >= 16) e = 1; 
		if(s >= 29) s = 1;
		if(m >= 20) m = 1;
		if(endE == e && endS == s && endM == m) //목표치와 같다면 답 
			break;	
	} 
	cout<<year;
	return 0;
}
