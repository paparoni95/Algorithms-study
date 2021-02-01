#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> tmp;
    for (auto n : numbers)
        tmp.push_back(to_string(n));
    sort(tmp.begin(), tmp.end(), compare);
    if (tmp.at(0) == "0")
        return "0";
    for (auto s : tmp)
        answer += s;
    return answer;
}