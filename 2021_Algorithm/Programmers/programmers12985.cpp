#include <iostream>
#include <vector>
using namespace std;

int solution(int n, int a, int b)
{
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) v[i] = i + 1;
    int round = 0;
    while (n != 1) {
        vector<int> win;
        round++;
        for (int i = 1; i <= n; i += 2) {
            if ((v[i - 1] == a && v[i] == b) || (v[i - 1] == b && v[i] == a)) return round;
            else if (v[i - 1] == a || v[i - 1] == b) win.push_back(v[i - 1]);
            else if (v[i] == a || v[i] == b) win.push_back(v[i]);
            else win.push_back(v[i - 1]);
        }
        v = win;
        n /= 2;
    }
    return -1;
}