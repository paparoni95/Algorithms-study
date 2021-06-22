#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> m1;
map<int, string> m2;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		string name;
		cin >> name;

		m1[name] = i;
		m2[i] = name;
	}

	for (int i = 0; i < n; i++) {
		string query;
		cin >> query;

		if (isalpha(query[0]))
			cout << m1[query] << '\n';
		else
			cout << m2[stoi(query)] << '\n';
	}
	return 0;
}