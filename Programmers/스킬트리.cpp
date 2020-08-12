#include <string>
#include <vector>
#include <iostream>
using namespace std;

// origin과 str을 비교, 하나라도 틀리면 false 아니면 true
bool matching(string origin, string str)
{
    for (int i = 0; i < str.size(); ++i)
    {
        if (origin[i] != str[i])
            return false;
    }

    return true;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    vector<string> v;
    // 주어진 배열에서 해당 문자열과 skill의 문자가 같은 것만 골라낸다.
    for (int i = 0; i < skill_trees.size(); ++i)
    {
        string str = skill_trees[i];
        string make = "";
        for (int j = 0; j < str.size(); ++j)
        {
            for (int k = 0; k < skill.size(); ++k)
            {
                if (str[j] == skill[k])
                {
                    make += str[j];
                    break;
                }
            }
        }
        v.push_back(make);
    }

    for (int i = 0; i < v.size(); ++i)
    {
        // 선행스킬이 없다는 의미
        if (v[i] == "")
            ++answer;
        else
        {
            // 선행스킬이 들어있다면 비교해본다.
            if (matching(skill, v[i]))
                ++answer;
        }
    }

    return answer;
}