#include <iostream>
#include <deque>
using namespace std;

int N, L;
int arr[5000001];

// ������ ���� L�� �����Ǿ� ���� ���� �����̵� ������ ����� �̿��Ѵ�.
// �ٸ� �� ������ �� �������� �ּҰ��� �����ؾ� �Ǳ� ������
// ������ ������ ���� ������ �ִ� ���Ұ����� ũ�ٸ�?
// �տ� �����ϰ� ���´�.

// => â�� ����� �̿��ϸ鼭 ���� ������ �����ϴ� ����� �߰��� ����
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> L;
	for (int i = 0; i < N; i++) cin >> arr[i];

	deque<pair<int, int> > dq;
	for (int i = 0; i < N; i++)
	{
		// ���� Ž�� ������ �ƴ� ���ҵ��� ����
		if (!dq.empty() && dq.front().second + L == i)
		{
			dq.pop_front();
		}

		// ���������� �����ϱ� ���ؼ� ������ ���Һ��� ū ���Ұ� �ڸ���� �ִٸ�, ���ֱ�
		while (!dq.empty() && dq.back().first > arr[i])
		{
			dq.pop_back();
		}

		dq.push_back({ arr[i], i });
		cout << dq.front().first << ' ';
	}

	return 0;
}