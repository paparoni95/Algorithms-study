#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string new_id) {
    string answer = "";

    for (int i = 0; i < new_id.size(); i++) {
        new_id[i] = tolower(new_id[i]);
    }

    for (int i = 0; i < new_id.size(); i++) {
        char c = new_id[i];
        if (c != '-' && c != '_' && c != '.' && !islower(c) && !isdigit(c))
            continue;
        answer.push_back(c);
    }


    string temp;
    for (int i = 0; i < answer.size(); i++) {
        if (answer[i] == '.') {
            temp += answer[i];
            while (i < answer.size() && answer[i] == '.') i++;
            i--;
        }
        else
            temp += answer[i];
    }

    answer = temp;

    if (answer.front() == '.') answer = answer.substr(1);
    if (answer.back() == '.') answer = answer.substr(0, answer.size() - 1);
    if (answer.empty()) answer = "a";
    if (answer.size() > 15) answer = answer.substr(0, 15);
    if (answer.back() == '.') answer = answer.substr(0, answer.size() - 1);
    while (answer.size() <= 2) {
        answer += answer.back();
    }
    return answer;
}
