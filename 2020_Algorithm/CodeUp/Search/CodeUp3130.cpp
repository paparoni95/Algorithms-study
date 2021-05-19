#include <iostream>
#include <stack>
using namespace std;

int n, h;
long long ans;
stack<int> s;

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> n;
    // 자신을 볼 수 있는 소가 몇 마리인지 파악하는 것
    // stack을 사용하면 O(N)으로 해결가능
    // s.pop() 과 s.push() 는 O(1)이기 때문
    for (int i = 0; i < n; i++)
    {
        cin >> h;

        while (!s.empty() && s.top() <= h) s.pop();
        s.push(h);
        if (s.size() >= 1) ans += s.size() - 1;
    }

    cout << ans << '\n';
    return 0;
}