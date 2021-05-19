#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    // 처음으로 k 이상인 수가 등장하는 위치
    cout << lower_bound(v.begin(), v.end(), k) - v.begin() + 1 << endl;
    return 0;
}