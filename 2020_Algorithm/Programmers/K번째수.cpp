#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int FindValue(vector<int>& array, vector<int>& index)
{
    int start = index[0];
    int end = index[1];
    int k = index[2];

    vector<int> vec;
    for (int i = start - 1; i <= end - 1; ++i)
    {
        vec.push_back(array[i]);
    }

    sort(vec.begin(), vec.end());

    return vec[k - 1];
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int i = 0; i < commands.size(); ++i)
    {
        vector<int> temp = commands[i];
        int number = FindValue(array, temp);

        answer.push_back(number);
    }

    return answer;
}