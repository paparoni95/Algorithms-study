#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string str1, string str2) {
    vector<string> a;
    vector<string> b;
    for (int i = 0; i < str1.size() - 1; i++) {
        string s = str1.substr(i, 2);
        if (isalpha(s[0]) && isalpha(s[1])) {
            s[0] = tolower(s[0]);
            s[1] = tolower(s[1]);
            a.push_back(s);
        }
    }

    for (int i = 0; i < str2.size() - 1; i++) {
        string s = str2.substr(i, 2);
        if (isalpha(s[0]) && isalpha(s[1])) {
            s[0] = tolower(s[0]);
            s[1] = tolower(s[1]);
            b.push_back(s);
        }
    }

    int t1 = 0, t2 = 0;
    vector<bool> a_check(a.size(), false);
    vector<bool> b_check(b.size(), false);
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (a[i] == b[j] && !a_check[i] && !b_check[j]) {
                a_check[i] = true;
                b_check[j] = true;
                t1++;
            }
        }
    }

    t2 = a.size() + b.size() - t1;
    if (a.size() == 0 && b.size() == 0) return 65536;
    return (int)((double)t1 / t2 * 65536);
}