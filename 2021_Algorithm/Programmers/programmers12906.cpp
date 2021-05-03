#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// 같은 숫자는 싫어(구현)
vector<int> solution(vector<int> arr)
{
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    return arr;
}