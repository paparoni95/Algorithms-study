#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<pair<int,int>> v;
	v.resize(n);
	for(int i=0; i<n; ++i){
		scanf("%d %d", &v[i].first, &v[i].second);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		printf("%d %d\n", v[i].first, v[i].second);
	}
	return 0;
}