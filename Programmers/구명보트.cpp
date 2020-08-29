#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    // 보통 탐욕법은 정렬을 한 상태에서 문제를 해결하자.
    sort(people.begin(), people.end());
    int l = 0, r = people.size() - 1;
    int answer = 0;
    while (l <= r) {
        // 가장 무거운 사람을 먼저 태운다.
        int total = limit - people[r--];

        // 무게 제한 - 태운 사람 = 남은 무게
        // 남은 무게에서 가벼운 사람을 태울 수 있는지 확인
        if (total >= people[l]) {
            ++l;
        }

        ++answer;
    }

    return answer;
}