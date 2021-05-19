#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    int width = 0, height = 0; //가로, 세로
    int size = (int)sqrt(brown + red);
    int row, col, redBlock = 0;
    for(int row = 3; row <= size; row++){
        col = (brown + red) / row;
        redBlock = (col - 2) * (row - 2);
        if(redBlock == red){
            width = col;
            height = row;
            break;
        }
    }
    answer.push_back(width);
    answer.push_back(height);
    cout<<width<<" "<<height<<endl;
    return answer;
}
