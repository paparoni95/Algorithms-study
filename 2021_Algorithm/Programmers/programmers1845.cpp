#include <vector>
#include <set>
using namespace std;
// ÆùÄÏ¸ó
int solution(vector<int> nums)
{
    int answer = 0;
    int choice = nums.size() / 2;
    set<int> s;
    for (int i = 0; i < nums.size(); i++) {
        s.insert(nums[i]);
    }

    if (choice < s.size()) return choice;
    else return s.size();
}