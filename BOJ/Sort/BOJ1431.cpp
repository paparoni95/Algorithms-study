#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b){
	int sizeOne = a.size();
	int sizeTwo = b.size();
	if(sizeOne != sizeTwo){ //a와 b의 길이가 다르면, 짧은 것이 먼저  
		return sizeOne < sizeTwo;
	}else{ //만약 서로 길이가 같다면 
		int sumOne = 0, sumTwo = 0;
		for(int i=0; i<sizeOne; i++)
			if('0'<= a[i] && a[i] <= '9') sumOne += (int)(a[i]-48);
		for(int i=0; i<sizeTwo; i++)
			if('0'<= b[i] && b[i] <= '9') sumTwo += (int)(b[i]-48);
			
		if(sumOne != sumTwo) return sumOne < sumTwo; //모든 자리수의 합에서 작은 합이 먼저
		else return a < b; //사전순으로 비교 
	}
}

int main(){
	int n;
	cin>>n;
	vector<string> v;
	for(int i=0; i<n; i++){
		string str;
		cin>>str;
		v.push_back(str);
	}
	sort(v.begin(), v.end(), compare);
	for(int i=0; i<n; i++)
		cout<<v[i]<<'\n';
	return 0;
}
