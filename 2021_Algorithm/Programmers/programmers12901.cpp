#include <string>
#include <vector>
using namespace std;
// 2016³â(±¸Çö)
vector<int> days = { 31,29,31,30,31,30,31,31,30,31,30,31 };
vector<string> name = { "THU","FRI","SAT","SUN","MON","TUE","WED" };

string solution(int a, int b) {
    int total_day = b;
    for (int i = 0; i < a - 1; i++) {
        total_day += days[i];
    }

    return name[total_day % 7];
}