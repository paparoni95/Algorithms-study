#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Student
{
public:
	string name;
	int kor;
	int eng;
	int math;

	Student() {}

	Student(string s, int k, int e, int m)
		:name(s), kor(k), eng(e), math(m) {}

	bool operator<(Student& other)
	{
		if (kor == other.kor)
		{
			if (eng == other.eng)
			{
				if (math == other.math)
				{
					return name < other.name;
				}
				return math > other.math;
			}
			return eng < other.eng;
		}
		return kor > other.kor;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<Student> v(n);
	for (int i = 0; i < n; i++)
	{
		string name;
		int kor, eng, math;
		cin >> name >> kor >> eng >> math;
		v.push_back(Student(name, kor, eng, math));
	}

	sort(v.begin(), v.end());

	for (auto ret : v)
		cout << ret.name << '\n';
	cout << '\n';
	return 0;
}