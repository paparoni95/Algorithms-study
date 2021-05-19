#include <string>
#include <vector>

using namespace std;

int GCD(int a, int b)
{
    if (b == 0) return a;
    else return GCD(b, a % b);
}

int LCM(int a, int b)
{
    int g = GCD(a, b);
    return (a / g) * (b / g) * g;
}

int solution(vector<int> arr) {
    if (arr.size() == 1) return arr[0];
    int answer = LCM(arr[0], arr[1]);

    for (int i = 2; i < arr.size(); ++i)
    {
        answer = LCM(answer, arr[i]);
    }

    return answer;
}