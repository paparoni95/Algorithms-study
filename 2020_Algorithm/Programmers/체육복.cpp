#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	vector<int> vec(n, 1);

	// 여분의 체육복을 가지고 있으면 +1 증가
	for (int i = 0; i < reserve.size(); ++i) {
		int idx = reserve[i] - 1;
		++vec[idx];
	}

	// 도난당한 학생의 체육복 -1 감소
	for (int i = 0; i < lost.size(); ++i) {
		int idx = lost[i] - 1;
		--vec[idx];
	}

	// 전체 학생을 살펴보면서, 해당 학생이 체육복이 없다면?
	// 앞의 학생과 뒤의 학생 중에서 더 많이 체육복을 가지고 있다면, 그 사람한테 빌린다.
	for (int i = 0; i < vec.size(); ++i) {
		if (vec[i] == 0) {
			if (vec[i - 1] >= 2 && i >= 0) {
				--vec[i - 1];
				++vec[i];
			}

			else if (vec[i + 1] >= 2 && i + 1 < n) {
				--vec[i + 1];
				++vec[i];
			}
		}
	}

	// 전체 학생을 살펴보면서, 해당 학생이 체육복을 가지고 있다면 정답 카운트
	for (int i = 0; i < vec.size(); ++i)
		if (vec[i]) ++answer;

	return answer;

}