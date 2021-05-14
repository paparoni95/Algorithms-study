#include <string>
#include <sstream>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

int solution(string dartResult) {
    stringstream ss(dartResult);

    vector<int> sum(3, 0);
    vector<int> options(3, 1);
    for (int i = 0; i < 3; i++) {
        int score;
        char bonus;
        char option;

        ss >> score;
        bonus = ss.get();
        option = ss.get();

        if (option != '*' && option != '#') ss.unget();

        if (bonus == 'S') sum[i] += pow(score, 1);
        else if (bonus == 'D') sum[i] += pow(score, 2);
        else if (bonus == 'T') sum[i] += pow(score, 3);

        if (option == '*') {
            if (i > 0 && options[i - 1]) options[i - 1] *= 2;
            options[i] *= 2;
        }
        else if (option == '#') options[i] *= -1;
    }

    return sum[0] * options[0] + sum[1] * options[1] + sum[2] * options[2];
}