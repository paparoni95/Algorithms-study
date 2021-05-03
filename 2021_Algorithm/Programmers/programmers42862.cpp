#include <string>
#include <vector>
using namespace std;
// 체육복(그리디)
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    vector<int> student(n, 1);
    for (int i = 0; i < lost.size(); i++) {
        student[lost[i] - 1]--;
    }

    for (int i = 0; i < reserve.size(); i++) {
        student[reserve[i] - 1]++;
    }

    for (int i = 0; i < student.size(); i++) {
        if (student[i] > 1) {
            if (student[i - 1] == 0 && i - 1 >= 0) {
                student[i - 1] = 1;
                student[i]--;
            }
            else if (student[i + 1] == 0 && i + 1 < student.size()) {
                student[i + 1] = 1;
                student[i]--;
            }
        }
    }

    for (int i = 0; i < student.size(); i++) {
        if (student[i] >= 1) answer++;
    }

    return answer;
}