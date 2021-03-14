#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> arr[10001];
vector<string> reverse_arr[10001];

int countByRange(const vector<string>& v, const string& left, const string& right) {
    return upper_bound(v.begin(), v.end(), right) - lower_bound(v.begin(), v.end(), left);
}

// 문자열 내에서 특정한 문자열을 다른 문자열로 모두 치환하는 함수
string replaceAll(string& str, const string& from, const string& to) {
    string res = str;
    int pos = 0;
    while ((pos = res.find(from, pos)) != string::npos) {
        res.replace(pos, from.size(), to);
        pos += to.size();
    }
    return res;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;

    for (int i = 0; i < words.size(); i++) {
        string word = words[i];
        arr[word.size()].push_back(word);
        reverse(word.begin(), word.end());
        reverse_arr[word.size()].push_back(word);
    }

    for (int i = 0; i < 10001; i++) {
        sort(arr[i].begin(), arr[i].end());
        sort(reverse_arr[i].begin(), reverse_arr[i].end());
    }

    for (int i = 0; i < queries.size(); i++) {
        string q = queries[i];
        int res = 0;
        if (q[0] != '?') {
            res = countByRange(arr[q.size()], replaceAll(q, "?", "a"), replaceAll(q, "?", "z"));
        }
        else {
            reverse(q.begin(), q.end());
            res = countByRange(reverse_arr[q.size()], replaceAll(q, "?", "a"), replaceAll(q, "?", "z"));
        }

        answer.push_back(res);
    }
    return answer;
}