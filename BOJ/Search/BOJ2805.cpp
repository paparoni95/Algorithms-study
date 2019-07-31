#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n,m;
vector<int> tree;
long long sum, ans;

void cutting(long long left, long long right){
	if(left<=right){
		long long mid = (left+right)/2;
		sum = 0;
		int cycle = tree.size();
		for(int i=0; i<cycle; i++){
			if(tree[i]-mid < 0) continue;
			sum+=(tree[i]-mid);	
		}
	
		if(sum >= m){
		    ans = mid;
			cutting(mid+1, right);	
		}
		else{
			cutting(left, mid-1);
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		tree.push_back(temp);
	}
	
	sort(tree.begin(),tree.end());
	cutting(0, INT_MAX);
	cout<<ans;
	return 0;
}
