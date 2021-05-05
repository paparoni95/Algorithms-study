#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i]) == false) return false;
    }

    return (s.length() == 6 || s.length() == 4) ? true : false;
}