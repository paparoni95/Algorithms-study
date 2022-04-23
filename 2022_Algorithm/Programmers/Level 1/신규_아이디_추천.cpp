#include <string>
#include <vector>
using namespace std;

string solution(string new_id) {
    string id = new_id;
    
    for(int i = 0; i < id.size(); i++)
        id[i] = tolower(id[i]);
    
    string temp;
    for(int i = 0; i < id.size(); i++) {
        if (isalpha(id[i])) temp += id[i];
        else if (isdigit(id[i])) temp += id[i];
        else if ('-' == id[i] || '_' == id[i] || '.' == id[i]) temp += id[i];
    }
    id = temp;
    temp = "";
    
    // 2번 이상 연속된 부분을 하나의 마침표로 치환하자.
    new_id = "";
    for(int i = 0; i < id.size(); i++) {
        if (id[i] == '.') {
            if (temp.empty()) {
                temp = ".";
            }
        }
        else {
            new_id += temp;
            new_id += id[i];
            temp = "";
        } 
    }
    id = new_id;
    
    if (id.front() == '.') id = id.substr(1);
    if (id.back() == '.') id = id.substr(0, id.size() - 1);
    
    if (id.empty()) id = "a";
    if (id.size() >= 16) id = id.substr(0, 15);
    if (id.back() == '.') id = id.substr(0, id.size() - 1);
    
    if (id.size() <= 2) {
        char last = id.back();
        while(id.size() != 3) {
            id += last;
        }
    }
    return id;
}
