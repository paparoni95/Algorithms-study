// 출처 : https://baactree.tistory.com/26?category=732753
#include <iostream>
using namespace std;

// 복잡도 분석하기
// PS에서 사용되는 복잡도는 시간복잡도와 공간복잡도
// 시간복잡도(TimeComplexity) : 프로그램 수행시간을 분석하는 것
// 공간복잡도(SpaceComplexity) : 프로그램의 메모리 사용량을 분석하는 것

// 시간복잡도
// o(5n^4 + 3n^2) => o(n^4)
// 가장 크게 영향을 받는 항만 표기한다.

// 공간복잡도
// 배열의 크기 x 해당 자료형의 크기
// 보통 기타 지역변수나 헤더파일, 함수등을 생각해서 5 ~ 10MB 정도는 여유로 빼고 생각


int n;

// o(logN)
while (n)
	n /= 2;

// o(sqrt(N))
for (int i = 0; i * i <= n; i++);

// o(N)
for (int i = 0; i < n; i++);

// o(N * logN)
for (int i = 0; i < n; i++)
	for (int j = i; j < n; j /= 2);

// o(N * sqrt(N))
for (int i = 0; i < n; i++)
	for (int j = 0; j * j <= i; j++);

// o(N * N) = o(N^2)
for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++);

// o(N * N * N) = o(N^3)
for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		for (int k = 0; k < n; k++);

// o(2 ^ N)
// 하나의 함수 안에 두 개의 함수를 호출할 때
int function(int n)
{
	if (n == 0 || n == 1) return 1;
	else return function(n - 1) + function(n - 2);
}

// o(N!)
// N개의 데이터를 나열하는 방법의 수
// 순열 (permutation) 부분도 비슷
// 여기서는 i번째에서 선택을 하는 경우, 안하는 경우로 나눠서 출력하는 방법
void function(int x, vector<int>& pick, vector<bool>& picked)
{
	// 정답인 경우
	if (x == n)
	{
		for (int i = 0; i < pick.size(); i++)
			printf("%d\n", pick[i]);
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (picked[i]) continue; // 선택됬다면 패스
		pick.push_back(i);
		picked[i] = true;
		function(x + 1, pick, picked); // i를 pick했고 다음으로 넘어가기
		pick.pop_back();  // 없었던 일로하기
		picked[i] = false;
	}
	return;
}
