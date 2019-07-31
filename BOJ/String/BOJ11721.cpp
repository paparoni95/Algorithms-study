#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;

	int cnt = 0;
	for (int i = 0; i < str.length(); i++) {
		cnt++;
		if (cnt == 10) {
			cnt = 0;
			cout << str[i] << endl;
		}
		else {
			cout << str[i];
		}
	}
	return 0;
}
