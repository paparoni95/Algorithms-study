#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(int n) {

    if (n == 1 || n == 2) return to_string(n);
    if (n == 3) return "4";

    string answer = "";

    while (n)
    {
        if (n % 3 == 0)
        {
            n /= 3;
            --n;
            answer += "4";
        }

        else
        {
            answer += to_string(n % 3);
            n /= 3;
        }
    }

    // 역순으로
    reverse(answer.begin(), answer.end());

    return answer;
}