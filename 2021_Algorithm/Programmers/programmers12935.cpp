#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> arr) {
    int min_value = arr[0];
    int idx = 0;
    for (int i = 1; i < arr.size(); i++) {
        if (min_value > arr[i]) {
            min_value = arr[i];
            idx = i;
        }
    }

    arr.erase(arr.begin() + idx);
    return arr.size() == 0 ? vector<int>(1, -1) : arr;
}