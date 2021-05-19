#include <iostream>
using namespace std;

int memo[200 + 1];
int fibo(int k)
{
    // 이미 구한 값이 있다면 반환
    if(memo[k] > 0) return memo[k] % 10009;
    // 없다면 값을 구해 넣어준다.
    memo[k] = (fibo(k - 1) + fibo(k - 2))  % 10009;
    return memo[k];
}

int main()
{
    int n;
    cin >> n;
    memo[1] = memo[2] = 1;
    cout << fibo(n) << endl;
    return 0;
}
