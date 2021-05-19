#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown + yellow;

    // 문제의 접근 방법이 중요
    // 높이는 최소 3인 이유, 위아래가 갈색이고 가운데가 노란색이기 때문에
    // 3이 아니면 이를 만족할 수 있는 모양이 나오지 않기 때문이다.
    int height = 3, weight = 0;
    while (1) {
        if (sum % height == 0) {
            weight = sum / height;

            // (가로-2)*(세로-2) = 노란색 부분과 일치하면 정답이다.
            if ((weight - 2) * (height - 2) == yellow) {
                answer.push_back(weight);
                answer.push_back(height);
                break;
            }
        }

        ++height;
    }

    return answer;
}