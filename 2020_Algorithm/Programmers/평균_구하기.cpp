#include <string>
#include <vector>
#include <iostream>
using namespace std;

double solution(vector<int> arr) {

    int len = arr.size();
    int sum = 0;
    for (int i = 0; i < arr.size(); ++i)
        sum += arr[i];


    return sum / (double)len;
}