#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < scoville.size(); ++i)
        pq.push(scoville[i]);

    while (pq.top() < K && pq.size() > 1) {
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();
        pq.push(first + second * 2);
        ++answer;
    }

    if (pq.top() < K)
        answer = -1;

    return answer;
}