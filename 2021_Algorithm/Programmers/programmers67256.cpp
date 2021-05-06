#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <iostream>
using namespace std;

map<char, pair<int, int>> m;

void init() {
    m['1'] = pair<int, int>(0, 0);
    m['2'] = pair<int, int>(0, 1);
    m['3'] = pair<int, int>(0, 2);
    m['4'] = pair<int, int>(1, 0);
    m['5'] = pair<int, int>(1, 1);
    m['6'] = pair<int, int>(1, 2);
    m['7'] = pair<int, int>(2, 0);
    m['8'] = pair<int, int>(2, 1);
    m['9'] = pair<int, int>(2, 2);
    m['*'] = pair<int, int>(3, 0);
    m['0'] = pair<int, int>(3, 1);
    m['#'] = pair<int, int>(3, 2);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";

    char left = '*';
    char right = '#';
    init();

    for (int i = 0; i < numbers.size(); i++) {
        int n = numbers[i];

        if (n == 1 || n == 4 || n == 7) answer += "L";
        else if (n == 3 || n == 6 || n == 9) answer += "R";
        else {
            int left_distance = abs(m[left].first - m[n + '0'].first) + abs(m[left].second - m[n + '0'].second);
            int right_distance = abs(m[right].first - m[n + '0'].first) + abs(m[right].second - m[n + '0'].second);
            if (left_distance == right_distance) {
                if (hand == "left")
                    answer += "L";
                else
                    answer += "R";
            }
            else if (left_distance < right_distance) answer += "L";
            else answer += "R";
        }

        if (answer.back() == 'R')
            right = n + '0';
        else
            left = n + '0';
    }

    return answer;
}