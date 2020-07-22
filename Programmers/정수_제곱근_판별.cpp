#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) {
    long long num = (int)sqrt(n);

    if (num * num == n)
    {
        ++num;
        return num * num;
    }
    else return -1;
}