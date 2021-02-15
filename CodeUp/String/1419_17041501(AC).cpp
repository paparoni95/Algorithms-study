#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);

    int loveCount = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'l')
        {
            if (s.substr(i, 4) == "love")
                loveCount++;
        }
    }

    cout << loveCount << endl;
    return 0;
}
