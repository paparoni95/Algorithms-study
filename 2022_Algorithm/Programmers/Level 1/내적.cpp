#include <string>
#include <vector>
using namespace std;

// 단순히 내적 공식을 이용해서 풀면 끝.
int solution(vector<int> a, vector<int> b) {
    int answer = 0;
    for (int i = 0; i < a.size(); i++)
    {
        answer += a[i] * b[i];
    }
    return answer;
}
