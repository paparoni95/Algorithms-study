#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    for (int i = 0; i < phone_book.size() - 1; i++) {
        string previous = phone_book[i];
        string current = phone_book[i + 1].substr(0, previous.size());
        if (previous == current)
            return false;
    }
    return true;
}