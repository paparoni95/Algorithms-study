#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#define MAX_SIZE 10001
using namespace std;

int n, k;
long long maxValue;
vector<int> v(MAX_SIZE);

void solve(long long left, long long right){
	long long cnt = 0;
	if(left<=right){
		long long mid = (left+right)/2;
		//랜선의 개수 구하기 
		for(int i = 0; i < v.size(); i++)
			cnt+=v[i]/mid;
		//cout<<mid<<' '<<cnt<<endl;
		if(cnt >= n) //랜선의 개수가 같을때, 더 긴 길이를 구하기 위해
			maxValue = max(maxValue, mid);
		if(cnt<n)
			solve(left,mid-1);
		else
			solve(mid+1,right);
	}
}

int main(){
	cin>>k>>n;
	for(int i = 0; i < k; i++){
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	
	int left = 1;
    int right = INT_MAX;
    
	solve(left,right);
	cout<<maxValue;
	return 0;
}
