#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, M;
int board[26] = { 3,2,1,2,4,3,1,3,1,1,3,1,3,2,1,2,2,2,1,2,1,1,1,2,2,1 };

int main()
{
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string A, B, C;
	cin >> N >> M >> A >> B;

	int minLen = N > M ? M : N;

	for (int i = 0; i < minLen; i++)
	{
		C += A[i];
		C += B[i];
	}
	
	if (A.size() > B.size())
	{
		C += A.substr(minLen);
	}
	else
	{
		C += B.substr(minLen);
	}

	vector<int> v(C.size(), 0);
	for (int i = 0; i < C.size(); i++)
	{
		v[i] = board[C[i] - 'A'];
	}

	while (v.size() >= 3)
	{
		vector<int> v2(v.size() - 1, 0);
		for (int i = 0; i < v.size() - 1; i++)
		{
			v2[i] = (v[i] + v[i + 1]) % 10;
		}
		v = v2;
	}

	if (v[0] == 0) 
		cout << v[1] << "%\n";
	else
		cout << v[0] << v[1] << "%\n";
	return 0;
}