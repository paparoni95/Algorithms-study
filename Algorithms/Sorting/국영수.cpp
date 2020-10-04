#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	string name;
	int kor;
	int eng;
	int math;
	Node(string name, int kor, int eng, int math)
		:name(name), kor(kor), eng(eng), math(math) { }

	bool operator<(const Node& ref) {
		if (kor == ref.kor && eng == ref.eng && math == ref.math) return name < ref.name;
		else if (kor == ref.kor && eng == ref.eng) return math > ref.math;
		else if (kor == ref.kor) return eng < ref.eng;
		else return kor > ref.kor;
	}
};

int n;
vector<Node> v;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string name;
		int kor, eng, math;
		cin >> name >> kor >> eng >> math;
		v.push_back(Node(name, kor, eng, math));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].name << '\n';
	}
	return 0;
}