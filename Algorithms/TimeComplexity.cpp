#include <iostream>
#include <vector>
using namespace std;

// 참고 https://baactree.tistory.com/29
// 공간 복잡도는 프로그램의 메모리 사용량을 분석하는 것이다.
// 사용한 배열의 크기 * (해당 자료형의 크기)
// 보통 기타 지역변수나 헤더파일, 함수 등을 생각해서 5~10MB정도는
// 여유로 빼고 시작한다.

// 시간 복잡도는 프로그램 수행시간을 분석
// 반복문에 크게 영향을 받는다.
// 빅오 표기법에서 입력의 크기가 n일 때
// 주어진 프로그램의 수행시간이 5n^4-7n^3+n^2+4의 식을 가진다면
// 시간복잡도는 O(N^4)와 같이 표기.
// PS에서는 보통 1억을 1초로 잡고 계산한다.

// 주어진 입력의 크기가 n이라고 하였을 때,
// 주어진 순서대로 위에서 아래로갈 때 (빠름 -> 느림) 순이다.

// O(logN)
while (n) {
	n /= 2;
}

// O(sqrt(N))
for (int i = 0; i * i <= n; i++);

// O(N)
for (int i = 0; i < n; i++);

// O(NlogN)
for (int i = 0; i < n; i++)
	for (int j = i; j; j /= 2);

// O(Nsqrt(N))
for (int i = 0; i < n; i++)
	for (int j = 0; j * j <= i; j++);

// O(N^2)
for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++);

// O(N^3)
for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		for (int k = 0; k < n; k++);

// O(2^N)
int function(int n) {
	if (n == 0 || n == 1)
		return 1;
	return function(n - 1) + function(n - 2);
}

// O(N!)
// N개의 데이터를 나열하는 방법의 수
void function(int x, vector<int> pick, vector<bool> picked) {
	if (x == n) {
		for (int i = 0; i < pick.size(); i++) {
			cout << pick[i] << '\n';
		}
		return;
	}
	for (int i = 0; i < n; i++) {
		if (picked[i])
			continue;
		pick.push_back(i);
		picked[i] = true;
		function(x + 1, pick, picked);
		pick.push_back();
		picked[i] = false;
	}
	return;
}
