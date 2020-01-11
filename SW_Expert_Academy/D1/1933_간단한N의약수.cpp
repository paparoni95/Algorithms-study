#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int n;
	cin >> n;
	vector<int> vec;
	for (int i = 1; i * i <= n; ++i)
	{
		if (n % i == 0)
		{
			vec.push_back(i);
			vec.push_back(n / i);
		}
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); ++i)
		cout << vec[i] << ' ';
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}