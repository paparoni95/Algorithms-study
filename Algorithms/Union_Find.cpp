#include <iostream>
using namespace std;

// 합집합(Union-Find)를 구현해보자.
// 여러 개의 노드가 존재할 때, 두 개의 노드를 선택해서
// 현재 두개의 노드가 서로 같은 그래프에 속해있는지 판별하는 알고리즘

// 부모 노드를 찾는 함수
int getParent(int parent[], int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

// 두 부모 노드를 합치는 함수 (Union)
void unionParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	// 두 부모 노드를 합칠 때는 더 작은 값으로 합친다.
	// 루트 노드가 작은 노드여야 한다. (일반적으로)
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

// 같은 부모를 가지는지 확인 (Find)
// (같은 그래프에 두 노드가 속해있는지)
bool findParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) return true;
	else return false;
}

int main() {
	int parent[11];
	// 처음에는 모든 노드들은 자기 자신을 가리키도록 만든다.
	for (int i = 1; i <= 10; i++) {
		parent[i] = i;
	}
	
	// 그래프들이 어떻게 연결되어 있는지 union으로 연결성을 표시.
	unionParent(parent, 1, 2);
	unionParent(parent, 2, 3);
	unionParent(parent, 3, 4);
	unionParent(parent, 5, 6);
	unionParent(parent, 6, 7);
	unionParent(parent, 7, 8);

	// 두 노드가 같은 그래프에 속해있는지 find로 확인해본다.
	cout << "1과 5는 연결되어 있나요? : ";
	if (findParent(parent, 1, 5)) {
		cout << "네" << '\n';
	}
	else {
		cout << "아니요" << '\n';
	}

	cout << "1과 5를 연결해줍니다." << '\n';
	unionParent(parent, 1, 5);

	cout << "1과 5는 연결되어 있나요? : ";
	if (findParent(parent, 1, 5)) {
		cout << "네" << '\n';
	}
	else {
		cout << "아니요" << '\n';
	}

	cout << "2과 8는 연결되어 있나요? : ";
	if (findParent(parent, 2, 8)) {
		cout << "네" << '\n';
	}
	else {
		cout << "아니요" << '\n';
	}
	return 0;
}