#include <string>
#include <vector>
using namespace std;

// 나머지가 1이 남으려면 n - 1로 나누면 된다.
// n - 1 만약 배수라면? 나눠지는 수가 가장 작은 자연수
// 나눠지지 않는다면? 그게 정답

int solution(int n) {
    --n;
    for(int i = 2; i <= 1000000; i++) {
        if (noPrime[i]) continue;
        if (n % i == 0)
            return i;
    }
    return n;
}
