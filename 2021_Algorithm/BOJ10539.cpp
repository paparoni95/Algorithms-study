#include <iostream>
#include <vector>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//1000000000
	int N;
	cin >> N;
	vector<long long> B(N, 0);
	vector<long long> A(N, 0);
	for (int i = 0; i < N; i++)
		cin >> B[i];

	for (int i = 1; i <= N; i++)
	{
		B[i - 1] = B[i - 1] * i;
	}

	A[0] = B[0];
	for (int i = 1; i < N; i++)
		A[i] = B[i] - B[i - 1];

	for (int i = 0; i < N; i++)
		cout << A[i] << ' ';


	return 0;
}
