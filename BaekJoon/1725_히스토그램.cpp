// https://jaimemin.tistory.com/827
// 스택을 기반으로 푸는 문제
// 중요한 것은 다 살펴보기 전에, 무시할 수 있는 것은 무시하면서 푸는 것

// 높이를 오름차순으로 쌓되, 현재 stack.top이 들어온 막대보다 크거나 같다면 직사각형의 넓이를 계산함.
// 왼쪽으로부터 오른쪽 방향으로만 만들 수 있다고 생각하면서 보는 시각이 필요.
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N;

	vector<int> v(N + 1, 0);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	stack<int> st;

	int ans = 0;
	for (int i = 0; i < N + 1; i++)
	{
		while (!st.empty() && v[st.top()] >= v[i])
		{
			int height = v[st.top()];
			st.pop();

			int width;
			// 왼쪽에 히스토그램이 남아있지 않다면
			if (st.empty()) width = i;
			else width = i - st.top() - 1;

			ans = max(ans, height * width);
		}
		st.push(i);
	}

	cout << ans;
	return 0;
}