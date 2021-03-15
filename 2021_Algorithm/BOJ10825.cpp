#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Student
{
public:
	string name;
	int kor;
	int eng;
	int math;

	Student(string name, int kor, int eng, int math)
		:name(name), kor(kor), eng(eng), math(math) {}

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

int n;
vector<Student> v;

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	v.reserve(n);
	for (int i = 0; i < n; i++)
	{
		string name;
		int kor, eng, math;
		cin >> name >> kor >> eng >> math;
		v.push_back(Student(name, kor, eng, math));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
	{
		cout << v[i].name << '\n';
	}

	return 0;
}