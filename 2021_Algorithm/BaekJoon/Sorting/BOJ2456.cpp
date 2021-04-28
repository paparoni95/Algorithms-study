#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Student
{
public:
	int idx;
	int total;
	int point3;
	int point2;

	Student() : idx(0), total(0), point3(0), point2(0) {}
	Student(int idx, int a, int b, int c) : idx(idx), total(a), point3(b), point2(c) {}
	bool operator<(const Student& other)
	{
		if (total == other.total)
		{
			if (point3 == other.point3)
			{
				return point2 > other.point2;
			}
			return point3 > other.point3;
		}
		return total > other.total;
	}

	bool operator==(const Student& other)
	{
		if (total == other.total && point3 == other.point3 && point2 == other.point2)
			return true;
		else
			return false;
	}
};

void addPoint(vector<Student>& v, int idx, int point)
{
	if (point == 3)
		v[idx].point3++;
	else if (point == 2)
		v[idx].point2++;

	v[idx].total += point;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<Student> v(3);

	for (int i = 0; i < 3; i++)
		v[i].idx = i + 1;

	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		addPoint(v, 0, a);
		addPoint(v, 1, b);
		addPoint(v, 2, c);
	}

	sort(v.begin(), v.end());

	if (v[0] == v[1])
		cout << 0 << ' ' << v[0].total << '\n';
	else
		cout << v[0].idx << ' ' << v[0].total << '\n';
	return 0;
}