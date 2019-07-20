#include <iostream>
#include <stack>
using namespace std;

int main(){
	int k;
	stack<int> s;
	cin>>k;
	for(int i = 0; i < k; i++){
		int temp;
		cin>>temp;
		if(temp == 0 && !s.empty()){
			s.pop();
		}else
			s.push(temp);
	}
	
	int sum = 0;
	while(!s.empty()){
		sum+=s.top();
		s.pop();
	}
	
	cout<<sum;
	return 0;
}
