#include <bits/stdc++.h>
using namespace std;

void radixSort(vector<int>& v) {

	int maxValue = *max_element(v.begin(), v.end());

	// 각 자릿수에 대해 정렬
	for (int digit = 1; digit <= maxValue; digit *= 10) {
		vector<int> output(v.size());
		vector<int> bucket(10, 0);

		cout << digit << "자릿수\n";
		// 각 자리수를 버킷에 저장
		for (int i = 0; i < v.size(); i++) {
			bucket[(v[i] / digit) % 10]++;
		}
		for (int i = 1; i < 10; i++) {
			bucket[i] += bucket[i - 1];
		}
		// 자리수가 같은 수에 대해 순서 유지를 위해 뒤에서부터 저장
		for (int i = v.size() - 1; i > -1; i--) {
			int k = (v[i] / digit) % 10;
			output[bucket[k] - 1] = v[i];
			bucket[k]--;
		}
		for (int i = 0; i < v.size(); i++) {
			v[i] = output[i];
		}
	}
}

int main() {
	vector<int> arr = { 152,73,69,41,28,1247,2,33,674,388 };
	radixSort(arr);
	for (auto n : arr) {
		cout << n << ' ';
	}
	return 0;
}