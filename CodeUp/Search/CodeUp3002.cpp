#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> v1;
vector<int> v2;

void input()
{
    cin >> n;
    v1.resize(n);
    for (int i = 0; i < n; i++) cin >> v1[i];

    cin >> m;
    v2.resize(m);
    for (int i = 0; i < m; i++) cin >> v2[i];
}

int binarySearch(int left, int right, int target)
{
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (v1[mid] == target) return mid + 1;
        else if (v1[mid] > target) right = mid - 1;
        else left = mid + 1;
    }

    return -1; // 못 찾으면
}

void solve()
{
    input();

    for (int i = 0; i < m; i++)
    {
        cout << binarySearch(0, n - 1, v2[i]) << ' ';
    }
}

int main()
{
    solve();

    return 0;
}