#include <iostream>
#include <string>
#include <algorithm> // reverse()
using namespace std;

int main()
{
	string x, y;
	cin >> x >> y;
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());
	string sum = to_string(stoi(x) + stoi(y));
	reverse(sum.begin(), sum.end());
	cout << stoi(sum) << '\n';
	return 0;
}