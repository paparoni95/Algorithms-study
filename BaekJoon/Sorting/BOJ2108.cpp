#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX = 4000;

pair<int, int> frequencies[MAX * 2 + 1]; // (등장 횟수, 실제 값)

// 최빈값을 구하는 조건이 까다롭기 때문에 Compare 사용자 정의를 해준다.
bool Compare(const pair<int, int> a, const pair<int, int> b) {
	if (a.first < b.first)
		return true;
	else if (a.first == b.first && a.second > b.second) 
		return true;
	else
		return false;
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < MAX * 2 + 1; ++i) { // -4000 ~ 4000 까지 잡아준다.
		frequencies[i].second = i - MAX;
	}

	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		sum += v[i];
		frequencies[v[i] + MAX].first++;
	}

	sort(v.begin(), v.end());
	sort(frequencies, frequencies + (MAX * 2 + 1), Compare);

	for (int i = 0; i < MAX * 2 + 1; ++i) {
		if (frequencies[i].first > 0)
			cout << frequencies[i].first << " " << frequencies[i].second << endl;
	}
	
	cout << round(sum / (double)n) << "\n";
	cout << v[n / 2] << "\n";

	int result = frequencies[MAX * 2].first == frequencies[MAX * 2 - 1].first ? frequencies[MAX * 2 - 1].second : frequencies[MAX * 2].second;
		
	cout << result << "\n";
	cout << v[v.size() - 1] - v[0] << "\n";
	return 0;
}