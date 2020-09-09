#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<string, pair<int, int>> a, pair<string, pair<int, int>> b) {
	// 성적이 동일하다면 나이가 더 어린 학생이 더 높게
	if (a.second.first == b.second.first) {
		return a.second.second > b.second.second;
	}
	else { // 성적이 높은 순서대로
		return a.second.first > b.second.first;
	}
}

int main() {
	vector<pair<string, pair<int, int>>> v;
	v.push_back(pair<string, pair<int, int>>("김도현", pair<int, int>(90, 19950208)));
	v.push_back(pair<string, pair<int, int>>("이태일", pair<int, int>(87, 19980411)));
	v.push_back(pair<string, pair<int, int>>("박한울", pair<int, int>(59, 19970218)));
	v.push_back(pair<string, pair<int, int>>("이상욱", pair<int, int>(93, 19930508)));
	v.push_back(pair<string, pair<int, int>>("강종구", pair<int, int>(90, 19960411)));

	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << ' ';
	}
	return 0;
}