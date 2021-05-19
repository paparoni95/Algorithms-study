#include <vector>
#include <set>
using namespace std;

// 문제의 요약
// 폰켓몬을 고르는 최대의 수는 N/2이며,
// 이왕이면 다양하게 골라야한다.
// 예시 2번을 보면, [3,3,3,2,2,4] 에서 최대 고르는 수는 6/2 = 3번
// 폰켓몬의 종류는 2,3,4 이므로 다양하게 고르면 총 3번이다. 그래서 3을 리턴
// 예시 3번을 보면, [3,3,3,2,2,2] 에서 최대 고르는 수는 6/2 = 3번
// 폰켓몬의 종류는 2,3 이므로 다양하게 골라봤자 총 2번이다. 그래서 2를 리턴

int solution(vector<int> nums)
{
    set<int> s;
    for (int i = 0; i < nums.size(); ++i) {
        s.insert(nums[i]);
    }

    if (s.size() > nums.size() / 2)
        return nums.size() / 2;
    else
        return s.size();
}