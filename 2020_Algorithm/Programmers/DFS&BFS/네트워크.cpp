#include <string>
#include <vector>
#define SIZE 200

using namespace std;

vector<int> net[SIZE]; //네트워크 
bool visit[SIZE]; //방문 표시여부  

void dfs(vector<vector<int>> &copy, int node){
    visit[node] = true;
    for(int i = 0; i < copy[node].size(); i++){
        if(visit[i] == false && copy[node][i]){
            dfs(copy, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j && computers[i][j]){
                net[i].push_back(j);
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        if(visit[i] == false){
            answer++;
            dfs(computers, i);
        }
    }
    
    return answer;
}
