/*
	정수 배열이 주어지면 가장 큰 이어지는 원소들의 합을 구하시오.
	단, 시간복잡도는 O(N)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int>& v) {
	int max_sum = v[0];
	int current_sum = v[0];
	for (int i = 1; i < v.size(); i++) {
		current_sum = max(v[i], current_sum + v[i]);
		max_sum = max(current_sum, max_sum);
	}
	return max_sum;
}

int main() {
	vector<vector<int>> v;
	vector<int> temp;
	// 테스트 케이스, 답 7
	temp.push_back(-1);
	temp.push_back(3);
	temp.push_back(-1);
	temp.push_back(5);
	v.push_back(temp);
	temp.clear();
	// 테스트 케이스, 답 -1
	temp.push_back(-5);
	temp.push_back(-3);
	temp.push_back(-1);
	v.push_back(temp);
	temp.clear();
	// 테스트 케이스, 답 9
	temp.push_back(2);
	temp.push_back(4);
	temp.push_back(-2);
	temp.push_back(-3);
	temp.push_back(8);
	v.push_back(temp);

	for (int i = 0; i < v.size(); i++) {
		int result = solution(v[i]);
		cout << "#" << i + 1 << " " << result << '\n';
	}

	return 0;
}