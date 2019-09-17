#include <iostream>
#include <algorithm>
using namespace std;

// 데이터를 묶어서 정렬하는 방법
class Student {
public:
	string name;
	int score;
	Student(string name, int score) {
		this->name = name;
		this->score = score;
	}

	// 정렬 기준은 '점수가 작은 순서'
	bool operator <(Student& student) {
		return this->score < student.score;
	}
};

int main() {
	Student students[] = {
		Student("김도현", 90),
		Student("박성태", 70),
		Student("이한울", 35),
		Student("박다솜", 75),
		Student("한다은", 99)
	};
	sort(students, students + 5);
	for (int i = 0; i < 5; i++) {
		cout << students[i].name << ' ';
	}
	return 0;
}