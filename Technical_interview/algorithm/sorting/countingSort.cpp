#include <bits/stdc++.h>
using namespace std;

int bucket[100];

vector<int> countingSort(vector<int>& v) {
	vector<int> result(v.size());
	// 등장하는 원소를 저장
	for (int i = 0; i < v.size(); i++) {
		bucket[v[i]]++;
	}
	// 누적합 계산
	for (int i = 1; i < v.size(); i++) {
		bucket[i] += bucket[i - 1];
	}
	// 누적합을 이용해 정렬
	for (int i = 0; i < v.size(); i++) {
		bucket[v[i]]--;
		result[bucket[v[i]]] = v[i];
	}
	return result;
}

int main() {
	vector<int> arr = { 3,2,3,1,1 };
	vector<int> result = countingSort(arr);
	for (auto n : result) {
		cout << n << ' ';
	}
	return 0;
}