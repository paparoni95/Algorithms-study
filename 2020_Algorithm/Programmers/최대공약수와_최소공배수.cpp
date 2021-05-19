#include <string>
#include <vector>
#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    while (b)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b, int g)
{
    return (a / g) * (b / g) * g;
}

vector<int> solution(int n, int m) {
    vector<int> answer(2, 0);

    answer[0] = gcd(n, m);
    answer[1] = lcm(n, m, answer[0]);
    return answer;
}