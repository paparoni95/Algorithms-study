#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> m;
    for (auto v : clothes) {
        m[v[1]]++;
    }

    int answer = 1;
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        answer *= (iter->second + 1);
    }
    return answer - 1;
}