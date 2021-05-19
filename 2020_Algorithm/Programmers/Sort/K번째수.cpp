#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i = 0; i < commands.size(); i++){
        vector<int> info; // i, j, k 담을 배열
        vector<int> temp; // array를 i ~ j사이로 커팅한 배열
        for(int j = 0; j < 3; j++)
            info.push_back(commands[i][j]);
        
        int s = info[0];
        int e = info[1];
        int k = info[2];
        for(int j = s - 1; j <= e - 1; j++)
            temp.push_back(array[j]);
        
        sort(temp.begin(), temp.end());
        answer.push_back(temp[k-1]);
    }
    return answer;
}
