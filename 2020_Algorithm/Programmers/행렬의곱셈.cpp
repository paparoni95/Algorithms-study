#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    vector<int> make;
    for (int i = 0; i < arr1.size(); ++i) {
        make.clear();
        // 한 행을 뽑아오고,
        vector<int> row = arr1[i];

        for (int j = 0; j < arr2[0].size(); ++j) {  // 열
            // 한 열을 뽑아와서,
            vector<int> col;
            for (int k = 0; k < arr2.size(); ++k) { // 행
                col.push_back(arr2[k][j]);
            }

            int sum = 0;
            for (int k = 0; k < arr2.size(); ++k) {
                sum += row[k] * col[k];
            }

            make.push_back(sum);
        }

        answer.push_back(make);
    }

    return answer;
}