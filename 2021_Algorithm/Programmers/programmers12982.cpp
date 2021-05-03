#include <algorithm>
#include <string>
#include <vector>
using namespace std;
// 예산(정렬)
int solution(vector<int> d, int budget) {
    int answer = 0;

    sort(d.begin(), d.end());
    int cost = 0;
    for (int i = 0; i < d.size(); i++) {
        if (cost + d[i] <= budget) {
            cost += d[i];
            answer++;
        }
    }

    return answer;
}