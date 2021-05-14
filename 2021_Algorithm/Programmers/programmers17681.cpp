#include <string>
#include <vector>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for (int i = 0; i < n; i++) {
        arr1[i] = arr1[i] | arr2[i];
        string make;
        for (int j = 0; j < n; j++) {
            if (arr1[i] % 2 == 0) make = " " + make;
            else make = "#" + make;
            arr1[i] = arr1[i] >> 1;
        }
        answer.push_back(make);
    }
    return answer;
}