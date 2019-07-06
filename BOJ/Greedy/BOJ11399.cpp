#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> timeLine;
	for (int i = 0; i < N; i++) {
		int time;
		cin >> time;
		timeLine.push_back(time);
	}
	sort(timeLine.begin(), timeLine.end()); //오름차순으로 정렬하고
	
	int total = 0, sum = 0;
	for (int i = 0; i < timeLine.size(); i++) {
		sum += timeLine[i];
		total += sum;
	}
	
	cout << total;
	return 0;
}