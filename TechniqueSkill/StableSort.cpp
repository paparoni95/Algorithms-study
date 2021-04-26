#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct Employee
{
	int age;
	string name;
};

bool operator<(const Employee& a, const Employee& b)
{
	return a.age < b.age;
}

int main()
{
	vector<Employee> v =
	{
		{27, "Uade"},
		{19, "Dopa"},
		{27, "Papa"}
	};

	// 안정 정렬
	stable_sort(v.begin(), v.end());

	for (const Employee& e : v)
		cout << e.age << ' ' << e.name << '\n';
	return 0;
}