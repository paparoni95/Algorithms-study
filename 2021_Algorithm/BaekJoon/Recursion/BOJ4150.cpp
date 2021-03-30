#include <iostream>
#include <string>
#include <algorithm> // reverse()
using namespace std;

/* 
   문제 : int, long long으로도 감당이 안되는 오버플로우인 수가 들어오게 되면?
   해결 : string으로 해결하자.
*/

string a, b, result;
int n;

// BigInteger!
string sum(string a, string b)
{
	int carry = 0, num = 0;
	string ret;

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	while (a.length() < b.length()) a += '0';
	while (a.length() > b.length()) b += '0';

	for (int i = 0; i < a.length(); ++i)
	{
		num = (a[i] - '0' + b[i] - '0' + carry) % 10;
		ret += to_string(num);
		carry = (a[i] - '0' + b[i] - '0' + carry) / 10;
	}
	if (carry != 0) ret += to_string(carry);

	reverse(ret.begin(), ret.end());

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	a = "0", b = "1";
	if (n == 0) result = "0";
	else if (n == 1) result = "1";

	for (int i = 2; i <= n; ++i)
	{
		result = sum(a, b);
		a = b;
		b = result;
	}

	cout << result;
	return 0;
}