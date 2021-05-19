#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    int number = arr[0];
    for (int i = 1; i < arr.size(); ++i)
    {
        if (number != arr[i])
        {
            answer.push_back(number);
            number = arr[i];
        }
    }

    answer.push_back(number);

    return answer;
}