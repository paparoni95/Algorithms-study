#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int p_cnt = 0, y_cnt = 0;

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == 'p' || s[i] == 'P') ++p_cnt;
        if (s[i] == 'y' || s[i] == 'Y') ++y_cnt;
    }

    if (p_cnt == 0 && y_cnt == 0) return true;
    else if (p_cnt == y_cnt)      return true;
    else                         return false;
}