#include <string>
#include <vector>

using namespace std;

bool prime[1000001];

// 소수를 대량으로 빠르고 정확하게 구하는 알고리즘
int Eratosthenes(int n)
{
    // 1은 소수가 아님.
    prime[1] = true;

    for (int i = 2; i <= n; ++i)
    {
        if (prime[i] == false)
        {
            // 그 수의 배수들을 모두 지운다.
            for (int j = i + i; j <= n; j += i)
                prime[j] = true;
        }
    }

    int cnt = 0;
    for (int i = 2; i <= n; ++i)
    {
        if (prime[i] == false)
            ++cnt;
    }

    return cnt;
}

int solution(int n) {
    int answer = Eratosthenes(n);
    return answer;
}