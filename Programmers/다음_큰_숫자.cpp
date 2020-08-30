#include <string>
#include <vector>
using namespace std;

// 숫자를 2진수로 변환하고, 거기서 1이 몇개인지 카운트
int BinaryNumber(int n) {
    int cnt = 0;
    while (n != 1) {
        if (n % 2 == 1) ++cnt;
        n /= 2;
    }

    return cnt;
}

int solution(int n) {
    int a_one_num = BinaryNumber(n);
    int b_one_num = 0;
    while (true) {
        b_one_num = BinaryNumber(++n);
        if (a_one_num == b_one_num) {
            return n;
        }
    }
}