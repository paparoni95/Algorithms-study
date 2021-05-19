#include <string>
#include <vector>

using namespace std;


// 1월 7일 (목) 0
// 1월 1일 (금) 1
// 1월 2일 (토) 2  
// 1월 3일 (일) 3
// 1월 4일 (월) 4
// 1월 5일 (화) 5
// 1월 6일 (수) 6

// 5월 24일
// 1 ~ 4월 합 : 31 + 29 + 31 + 30 = 121
// 총 일수 : 121 + 24 = 145
// 145 % 7 = 5 => 화요일
string solution(int a, int b) {
    // 윤년이면 2월은 29일까지
    int days[] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    string str[] = { "THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED" };

    int total_days = b;
    for (int i = 1; i < a; ++i)
        total_days += days[i];

    return str[total_days % 7];
}