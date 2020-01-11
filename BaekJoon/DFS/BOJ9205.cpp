#include <iostream>
#include <cstdlib>
#include <vector>
#define MAX_SIZE 105
using namespace std;

vector<int> mp[MAX_SIZE];
bool visit[MAX_SIZE];

//맨해튼 거리 계산
int diffStreet(vector<pair<int, int>> street, int u, int v) {
	return abs(street[u].first - street[v].first) + abs(street[u].second - street[v].second);
}

//dfs탐색하면서 방문을 한다.
void runStreet(int node) {
	visit[node] = true;
	for (int i = 0; i < mp[node].size(); i++) {
		int nextNode = mp[node][i];
		if (visit[nextNode] == false) {
			runStreet(nextNode);
		}
	}
}

bool solve(vector<pair<int, int>> street, int size) {
	//A지역에서 B지역으로 갈 때, 최대로 갈 수 있는 경로는 1000까지
	//따라서 1000이내의 모든 지역을 연결을 표시한다.
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			int range = diffStreet(street, i, j);
			if (range <= 1000) { //A지역과 B지역이 1000거리 이내이면 둘은 갈 수 있는 범위.
				mp[i].push_back(j);
				mp[j].push_back(i);
			}
		}
	}

	runStreet(0); //출발지점부터 시작
	if (visit[size - 1] == false) { //도착못했으면
		return false;
	}
	else { //했다면
		return true;
	}
}

void init() {
	for (int i = 0; i < MAX_SIZE; i++) {
		visit[i] = false;
		mp[i].clear();
	}
}

int main() {
	int t;
	cin >> t;
	for (int testCase = 1; testCase <= t; testCase++) {
		init();       //초기화
		int area = 2; //상근이집 + 페스티벌
		int shop;     //편의점 수
		cin >> shop;
		area += shop;
		vector<pair<int, int>> street(MAX_SIZE);
		for (int i = 0; i < area; i++) { //(x, y)좌표
			cin >> street[i].first >> street[i].second;
		}

		bool ret = solve(street, area);
		if (ret == false)
			cout << "sad" << '\n';
		else
			cout << "happy" << '\n';
	}
	return 0;
}