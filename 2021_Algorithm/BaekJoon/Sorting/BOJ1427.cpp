#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string s;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	sort(s.begin(), s.end(), greater<char>());
	for (char c : s)
		cout << c;
	cout << '\n';
	return 0;
}