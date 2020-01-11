#include <string>
#include <iostream>
using namespace std;

void Swap(string& s) {
	char temp = s[0];
	s[0] = s[2];
	s[2] = temp;
}

int main() {
	int a, b;
	cin >> a >> b;

	string s1 = to_string(a);
	string s2 = to_string(b);
	Swap(s1);
	Swap(s2);

	a = stoi(s1);
	b = stoi(s2);

	if (a < b) 
		cout << b;
	else
		cout << a;
	return 0;
}