#include <iostream>
#include <list>
#include <string>
using namespace std;

string input;
int m;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> input >> m;
	list<char> lt;
	for (auto c : input) lt.push_back(c);
	list<char>::iterator cursor = lt.end();
	while (m--) {
		string cmd;
		cin >> cmd;
		if (cmd == "P") {
			char ch;
			cin >> ch;
			lt.insert(cursor, ch);
		}
		else if (cmd == "L") {
			if (cursor == lt.begin()) continue;
			cursor--;
		}
		else if (cmd == "D") {
			if (cursor == lt.end()) continue;
			cursor++;
		}
		else if (cmd == "B") {
			if (cursor == lt.begin()) continue;
			cursor = lt.erase(--cursor);
		}
	}
	for (auto c : lt) {
		cout << c;
	}
	return 0;
}