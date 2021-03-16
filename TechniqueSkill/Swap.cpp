// C++11
#include <iostream>
#include <utility>

/*
    # 함수 원형
	template<class T> void swap(T& a, T& b)
	{
		T c(std::move(a)); a=std::move(b); b=std::move(c);
	}

	template<class T, size_t N> void swap(T& a[N], T& b[N])
	{
		for(size_t i = 0; i < N; ++i) swap(a[i], b[i]);
	}

	# 시간 복잡도
	배열 아닐 때, O(1)
	배열 일 때, O(N)
*/

int main()
{
	int x = 10, y = 20;            // x : 10, y : 20
	std::swap(x, y);               // x : 20, y : 10

	int foo[4];                    // foo: ? ? ? ?
	int bar[] = { 10,20,30,40 };   // foo: ? ? ? ?      bar: 10 20 30 40
	std::swap(foo, bar);           // foo: 10 20 30 40  bar: ? ? ? ?

	std::cout << "foo contains: ";
	for (int i : foo) std::cout << i << ' ';
	std::cout << '\n';
	return 0;
}