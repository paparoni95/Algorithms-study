#include <string>
#include <vector>
using namespace std;

int answer;
void go(int idx, int result, int target, vector<int>& numbers) {
    if (idx >= numbers.size()) {
        if (result == target) answer++;
        return;
    }

    go(idx + 1, result + numbers[idx], target, numbers);
    go(idx + 1, result - numbers[idx], target, numbers);
}

int solution(vector<int> numbers, int target) {
    go(0, 0, target, numbers);
    return answer;
}