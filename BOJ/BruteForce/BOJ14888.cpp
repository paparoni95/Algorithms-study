#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_VALUE 1000000000
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> operators;
	
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	// + - * /
	// 0 1 2 3 으로 표현하면
	vector<int> temp;
	for (int i = 0; i < 4; ++i) {
		int cnt;
		cin >> cnt;
		temp.push_back(cnt);
	}

	//순열로 표현해준다.
	for (int i = 0; i < temp.size(); ++i) {
		if (temp[i] > 0) {
			for (int j = 0; j < temp[i]; ++j) {
				operators.push_back(i);
			}
		}
	}
	//사전순으로 정렬해주고
	sort(operators.begin(), operators.end());
	long long maxValue = -MAX_VALUE, minValue = MAX_VALUE;

	//순열을 돌리면서 최대와 최소를 갱신한다.
	do {
		int total = v[0];
		for (int i = 1; i < v.size(); ++i) {
			int sign = operators[i - 1];

			switch (sign) {
			case 0:
				total += v[i];
				break;
			case 1:
				total -= v[i];
				break;
			case 2:
				total *= v[i];
				break;
			case 3:
				total /= v[i];
				break;
			}
		}
		maxValue = total > maxValue ? total : maxValue;
		minValue = total < minValue ? total : minValue;
	} while (next_permutation(operators.begin(), operators.end()));

	cout << maxValue << '\n';
	cout << minValue;

	return 0;
}