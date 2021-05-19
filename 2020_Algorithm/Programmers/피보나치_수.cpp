#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    const int MOD = 1234567;
    vector<int> v(n + 1, 0);

    v[0] = 0;
    v[1] = 1;
    for (int i = 2; i <= n; ++i) {
        v[i] = (v[i - 1] + v[i - 2]) % MOD;
    }
    return v[n];
}