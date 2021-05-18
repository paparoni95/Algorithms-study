#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> record) {
    map<string, string> m;
    vector<pair<string, string>> msg; // (type, uid)
    for (int i = 0; i < record.size(); i++) {
        istringstream ss(record[i]);
        vector<string> v;
        string buffer;
        while (getline(ss, buffer, ' ')) v.push_back(buffer);

        // v[0] : Enter, Leave, Change
        // v[1] : uid
        // v[2] : name
        if (v[0][0] == 'E') {
            m[v[1]] = v[2];
            msg.push_back({ v[0], v[1] });
        }
        else if (v[0][0] == 'L') {
            msg.push_back({ v[0], v[1] });
        }
        else {
            m[v[1]] = v[2];
        }
    }

    vector<string> answer;
    for (int i = 0; i < msg.size(); i++) {
        if (msg[i].first == "Enter") answer.push_back(m[msg[i].second] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
        else answer.push_back(m[msg[i].second] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.");
    }
    return answer;
}