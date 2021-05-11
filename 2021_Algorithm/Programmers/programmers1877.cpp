#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool solution(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++) {
        if (i + 1 != arr[i]) return false;
    }
    return true;
}