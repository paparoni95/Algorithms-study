#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<long long, vector<long long>, greater<long long>> pq(scoville.begin(), scoville.end());
    bool ok = false;
    while (pq.size() > 1) {
        answer++;

        long long first = pq.top(); pq.pop();
        long long second = pq.top(); pq.pop();
        pq.push(first + second * 2);

        if (pq.top() >= K) {
            ok = true;
            break;
        }
    }

    return ok ? answer : -1;
}