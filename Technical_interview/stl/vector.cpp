#include <iostream>
#include <vector>
using namespace std;

typedef struct
{
	int data;
}Node;

// vector
// 동적배열
// 임의의 위치에 있는 원소 접근 O(1)
// 뒤에서 원소를 추가하는 연산은 O(1) 분할상환분석 보장

int main()
{
	// int 자료형을 저장하는 동적배열
	vector<int> vec1;
	// double 자료형을 저장하는 동적배열
	vector<double> vec2;
	// 사용자 정의 Node 구조체를 저장하는 동적배열
	vector<Node> vec3;
	// 벡터의 초기 크기를 5로 설정
	vector<int> vec4(5);
	// 벡터의 초기 크기를 5로 설정하고 1로 초기화
	vector<int> vec5(5, 1);
	// 크기가 5 * 6인 2차원 벡터를 선언하고 0으로 초기화
	vector<vector<int>> vec6(5, vector<int>(6, 0));
	for (int i = 0; i < vec6.size(); i++)
	{
		for (int j = 0; j < vec6[i].size(); j++)
		{
			cout << vec6[i][j];
		}
		cout << '\n';
	}

	// 벡터의 맨 뒤에 원소 5를 추가
	vec1.push_back(5);
	// 벡터의 맨 뒤 원소 삭제
	vec1.pop_back();
	// 벡터의 크기 출력
	cout << vec1.size() << '\n';
	// 벡터의 크기를 10으로 재설정
	vec1.resize(10);
	// 벡터의 모든 원소 삭제
	vec1.clear();
	// 벡터의 첫 원소의 주소, 마지막 원소의 다음 주소 리턴
	vec1.begin();
	vec1.end();
	// [a,b) 주소 구간에 해당하는 원소 삭제
	vec1.erase(vec1.begin(), vec1.end());
	// vec7은 vec1의 2번째 원소부터 마지막 원소까지 복사하여 생성
	vector<int> vec7 = vector<int>(vec1.begin() + 2, vec1.end());
	return 0;
}