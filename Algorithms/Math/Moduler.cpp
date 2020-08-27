#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

// 나머지 연산 (= 모듈러 연산)

template<typename T>
void Print(const vector<T>& v)
{
	for (const auto& n : v)
		cout << n << " ";
	cout << endl;
}

int main()
{
	srand((unsigned int)time(NULL));
	// 기본적으로 mod m 이면, [0,m-1]까지 나온다.
	vector<int> v(10);
	for (int& n : v)
		n = rand();

	cout << "vector: ";
	Print<int>(v);

	int mod = 10;
	cout << "vector mod 10: ";
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] % mod << " ";
	cout << endl;

	int A = 6, B = 5;
	// (A + B) mod M = ((A mod M) + (B mod M)) mod M  (성립)
	cout << (A + B) % mod << " ";
	cout << ((A % mod) + (B % mod)) % mod << endl;
	// (A x B) mod M = ((A mod M) x (B mod M)) mod M  (성립)
	cout << (A * B) % mod << " ";
	cout << ((A % mod) * (B % mod)) % mod << endl;
	// (A - B) mod M = ((A mod M) - (B mod M) + mod) mod M (성립)
	cout << (A - B) % mod << " ";
	cout << ((A % mod) - (B % mod) + mod) % mod << endl;
}