#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// K¹øÂ°¼ö
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int i = 0; i < commands.size(); i++) {
        vector<int> ret(array.begin() + commands[i][0] - 1, array.begin() + commands[i][1]);
        sort(ret.begin(), ret.end());
        answer.push_back(ret[commands[i][2] - 1]);
    }
    return answer;
}