#include <iostream> 
#include <tuple> // std::tuple, std::get, std::tie, std::ignore
using namespace std;

/*
	#tuple이 도입된 배경
	함수를 만들 때 간혹 2개 이상의 값을 한번에 리턴하고 싶을 때가 있다.
	이럴때 기존에는 구조체를 정의하고 구조체 변수를 하나 선언한 후 값을 넣고 리턴해야했다.
	단지 리턴값을 여러개 받고 싶을 뿐인데 구조체를 정의해야 한다는 것이 좀 부담이 있다.

	C++11에서는 이런 불편함을 없애기 위해 tuple을 도입했다.
	tuple을 사용하면 2개 이상의 변수를 한번에 묶어서 리턴할 수 있다.

	보통은 인자 3개이상부터 사용하고, 2개일 때는 pair를 쓴다.
*/

int main()
{
	tuple<int, char> foo(10, 'x');
	auto bar = make_tuple("test", 3.1, 14, 'y');

	get<2>(bar) = 100; // access element

	int myint; char mychar;

	tie(myint, mychar) = foo; // unpack elements, 이렇게 뽑아올 수 있다.
	cout << "myint : " << myint << endl;
	cout << "mychar : " << mychar << endl;

	tie(std::ignore, std::ignore, myint, mychar) = bar; // unpack with ignore, ignore는 무시한다.
	cout << "myint : " << myint << endl;
	cout << "mychar : " << mychar << endl;

	mychar = get<3>(bar);

	get<0>(foo) = get<2>(bar);
	get<1>(foo) = mychar;

	cout << "foo contains: ";
	cout << std::get<0>(foo) << ' ';
	cout << std::get<1>(foo) << '\n';

	return 0;
}