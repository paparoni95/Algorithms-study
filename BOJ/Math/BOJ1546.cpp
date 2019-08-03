#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<double> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	double M = *max_element(v.begin(), v.end());
	
	double sum = 0;
	for (int i = 0; i < n; ++i) {
		v[i] = v[i] / M * 100;
		sum += v[i];
	}
	printf("%f", sum / n);
	return 0;
}