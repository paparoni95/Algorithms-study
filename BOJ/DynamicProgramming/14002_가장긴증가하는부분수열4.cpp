#include <iostream>
using namespace std;

int a[1001]; // 기존의 수를 담을 배열
int d[1001]; // d[i] : i번째를 마지막 원소로 가지는 lis의 길이
int v[1001]; // a[i]의 앞에 와야 하는 수의 인덱스

// lis의 부분 수열 출력
void recursive(int p)
{
	if (p == -1) return;
	recursive(v[p]);
	cout << a[p] << ' ';
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		v[i] = -1;
	}
		
	int max_idx = 0, max = 0;
	for (int i = 0; i < n; i++)
	{
		d[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (a[i] > a[j] && d[j] + 1 > d[i])
			{
				d[i] = d[j] + 1;
				v[i] = j;
			}
		}

		if (d[i] > max)
		{
			max = d[i];
			max_idx = i;
		}
			
	}
	cout << max << '\n';
	recursive(max_idx);
	return 0;
}