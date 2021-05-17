#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer(2, 0);
    vector<int> point = { 6, 6, 5, 4, 3, 2, 1 };
    int zero = 0;
    for (int i = 0; i < lottos.size(); i++) {
        if (lottos[i] == 0) zero++;
    }

    int cnt = 0;
    for (int i = 0; i < win_nums.size(); i++) {
        for (int j = 0; j < lottos.size(); j++) {
            if (win_nums[i] == lottos[j]) cnt++;
        }
    }

    answer[0] = point[cnt + zero];
    answer[1] = point[cnt];

    return answer;
}