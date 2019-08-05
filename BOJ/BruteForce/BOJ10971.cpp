#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define SIZE 10
using namespace std;

int way[SIZE][SIZE];

//주어진 노선을 갈 수 있는 경로인지 파악
bool RouteIsRight(vector<int>& v) {
	for (int i = 1; i < v.size(); ++i) {
		if (way[v[i - 1]][v[i]] <= 0)
			return false;
	}

	if (way[v[v.size() - 1]][v[0]] <= 0)
		return false;
	return true;
}

//주어진 도시를 순회했을 때, 그 비용을 계산해서 리턴
int CalcCost(vector<int>& v) {

	int cost = 0; //순회했을 때 드는 비용을 저장할 변수

	for (int i = 1; i < v.size(); ++i) {
		//way[i][j] => i -> j로 가는 비용을 의미
		cost += way[v[i-1]][v[i]];
	}
	//마지막 도시에서 다시 출발한 도시로 돌아오는 비용도 더해줘야한다.
	cost += way[v[v.size() - 1]][v[0]];
	return cost;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	//도시의 번호 0부터 하기로 정하면, (인덱스 0부터 시작)
	vector<int> city(n);
	for (int i = 0; i < n; ++i) {
		city[i] = i;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> way[i][j];
		}
	}

	int ans = INT_MAX; //나올 수 없는 가장 큰 수를 집어넣는다.

	do {
		if (RouteIsRight(city)) { //갈 수 있는 길인지 판단 후
			ans = min(ans, CalcCost(city)); //적은 비용을 갱신한다.
		}
	} while (next_permutation(city.begin(), city.end()));

	cout << ans;
	return 0;
}