#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string s) {
    vector<int> v;
    string num;
    int size;
    for (int i = 0; i < s.length(); ++i) {
        num = "";
        size = 0;
        if (s[i] >= '0' && s[i] <= '9') {
            num += s[i];
            ++size;
            for (int j = i + 1; j < s.length(); ++j) {
                if (s[j] >= '0' && s[j] <= '9')
                    num += s[j], ++size;
                else
                    break;
            }

            //cout<<num<<endl;

            if (i - 1 >= 0 && s[i - 1] == '-') {
                v.push_back(stoi(num) * -1);
            }
            else
                v.push_back(stoi(num));

            i += size;
        }
    }

    int max = *max_element(v.begin(), v.end());
    int min = *min_element(v.begin(), v.end());
    string answer = "";
    answer += to_string(min);
    answer += " ";
    answer += to_string(max);

    return answer;
}