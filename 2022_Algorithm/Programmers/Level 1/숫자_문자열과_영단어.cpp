#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, string> tbl;

void init()
{
    tbl["zero"] = "0";
    tbl["one"] = "1"; tbl["two"] = "2"; tbl["three"] = "3";
    tbl["four"] = "4"; tbl["five"] = "5"; tbl["six"] = "6";
    tbl["seven"] = "7"; tbl["eight"] = "8"; tbl["nine"] = "9";
}
// 원래 숫자를 찾아줘~
// 숫자면 문자열에 더하고, 아니라면 num 에 더한다.
// num 이 숫자를 뜻하는 영단어라면? 문자열에 더해주고 아니라면 누적하기
int solution(string s)
{
    init();
    string num = "";
    string answer = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
        {
            answer += s[i];
        }
        else
        {
            num += s[i];
            if (tbl.find(num) != tbl.end())
            {
                answer += tbl[num];
                num = "";
            }
        }
    }

    return stoi(answer);
}
