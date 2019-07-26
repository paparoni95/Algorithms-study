#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<pair<int,int> > v;
	vector<int> ans;
	for(int i=0; i<n; i++){
		int height, weight;
		cin>>height>>weight;
		v.push_back(make_pair(height, weight));
	}
	
	int h, w, cnt = 0;
	for(int i=0; i<n; i++){
		cnt = 0;
		h = v[i].first;
		w = v[i].second;
		for(int j=0; j<n; j++){
			if(i == j) continue;
			if(h < v[j].first && w < v[j].second)
				cnt++;
		}
		ans.push_back(cnt+1);
	}
	
	for(int i=0; i<n; i++)
		cout<<ans[i]<<' ';
	return 0;
}
