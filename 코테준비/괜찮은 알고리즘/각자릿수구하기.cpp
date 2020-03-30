#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// 숫자의 각 자리수 구하기 알고리즘

int main()
{
	int num = 123456789;

	// 이렇게 쪼개는 방법
	printf("case 1 : ");
	while (num)
	{
		printf("%d ", num % 10);
		num /= 10;
	}
	printf("\n");
	// 결과 9 8 7 6 5 4 3 2 1


	// 배열에 저장한다음 이용하는 방법
	num = 123456789;
	vector<int> v1;
	while (num)
	{
		v1.push_back(num % 10);
		num /= 10;
	}
	printf("case 2 : ");
	for (int i = 0; i < v1.size(); i++)
		printf("%d ", v1[i]);
	printf("\n");

	// 역순으로 출력해보자. (algorithm 헤더파일에 있다)
	printf("case 3 : ");
	reverse(v1.begin(), v1.end());
	for (int i = 0; i < v1.size(); i++)
		printf("%d ", v1[i]);
	printf("\n");

	// 스택을 이용해서 역순으로 출력 가능
	printf("case 4 : ");
	stack<int> s;
	for (int i = 0; i < v1.size(); i++)
		s.push(v1[i]); // o(1)
	while (!s.empty()) 
	{
		printf("%d ", s.top()); // o(1)
		s.pop(); // o(1)
	}
	return 0;
}