#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int tc;
	cin >> tc;

	int student_number; // 학생수
	int average;        // 평균 점수
	int pass_student_number; // 평균 점수보다 높은 학생
	float answer;
	for (int test_case = 0; test_case < tc; test_case++) {
		cin >> student_number;
		average = 0, pass_student_number = 0;
		answer = 0;
		
		vector<int> points(student_number);
		for (int i = 0; i < student_number; i++) {
			cin >> points[i];
			average += points[i];
		}
		// 평균 점수
		average = (int)(average / student_number);
		// 평균 점수보다 높은 사람의 수
		for (int i = 0; i < student_number; i++) {
			if (average < points[i])
				pass_student_number++;
		}
		// 답 (소수 셋째 자리까지 출력, 단 반올림)
		answer = ((double)pass_student_number / student_number) * 100;
		cout.precision(3);
		cout << fixed << answer << "%" << '\n';
	}
}