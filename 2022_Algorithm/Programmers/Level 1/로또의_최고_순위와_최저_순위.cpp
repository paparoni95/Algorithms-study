#include <string>
#include <vector>
using namespace std;

// 로또의 숫자는 1~45 (중복없이)
// 순서와 상관없이 일치하는 번호가 있다면 맞힌 것
// 최고점
// 최저점

int getPoint(int point)
{
    switch (point)
    {
    case 6:
        return 1;
    case 5:
        return 2;
    case 4:
        return 3;
    case 3:
        return 4;
    case 2:
        return 5;
    default:
        return 6;
    }
}
vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;

    int hit = 0;
    int miss = 0;
    for (int i = 0; i < lottos.size(); i++)
    {
        for (int j = 0; j < win_nums.size(); j++)
        {
            if (lottos[i] == 0)
            {
                ++miss;
                break;
            }
            else if (lottos[i] == win_nums[j])
            {
                ++hit;
                break;
            }
        }
    }
    answer.push_back(getPoint(hit + miss));
    answer.push_back(getPoint(hit));
    return answer;
}
