#include <iostream>
using namespace std;

// HeapSort를 이용해서 정렬해보자.
int a[] = { 230, 10, 60, 550, 40, 220, 20 };
int heap_size = 7;

// HeapSort를 하기 위해서는 아래와 같은 과정이 필요하다.
// 1. 주어진 입력을 힙 구조로 만든다. (Heapify)
// 2. 힙에서 가장 큰 값을 가장 마지막 값과 swap하면서 heap-size를 줄인다. (Extract-Max)
// 3. 정렬된 배열을 출력한다.

// 결과물은 max_heap구조로 만드는 것이며, 데이터를 오름차순으로 정렬한다.

void max_heapify(int node) {
	int parent_node = node;
	int left_child = node * 2 + 1;
	int right_child = node * 2 + 2;
	int largest = 0; // 가장 큰 값을 가진 노드의 인덱스

	// 루트 노드와 왼쪽 자식 노드를 비교
	if (left_child < heap_size && a[left_child] > a[parent_node]) {
		largest = left_child;
	}
	else {
		largest = parent_node;
	}

	// 가장 큰 값과 오른쪽 자식 노드를 비교
	if (right_child < heap_size && a[right_child] > a[largest]) {
		largest = right_child;
	}

	// 제일 큰 값이 부모 노드가 아니라면
	// 스왑한다.
	if (largest != parent_node) {
		int temp = a[largest];
		a[largest] = a[parent_node];
		a[parent_node] = temp;

		// 자식이 없을 때까지 계속해서 내려가면서 heapify를 수행
		max_heapify(largest); 
	}
}

void build_max_heap() {
	// 힙 구조를 만드는 방법은 전체 노드 중에서 1/2개 만큼만 보면 된다.
	for (int i = heap_size / 2 - 1; i >= 0; i--) {
		max_heapify(i);
	}
}

void extract_max() {
	
	for (int i = heap_size - 1; i >= 1; i--) {
		// 루트 노드와 마지막 원소의 값을 스왑한다.
		int temp = a[0];
		a[0] = a[i];
		a[i] = temp;

		heap_size--;    // 힙 사이즈 하나 줄이기
		max_heapify(0); // 다시 힙 구조로 만들기
	}
}

void print_sorted(int len) {
	for (int i = 0; i < len; i++)
		cout << a[i] << ' ';
	cout << '\n';
}

void heap_sort() {
	build_max_heap(); // 주어진 데이터를 max 힙 구조로 만든다.
	extract_max();    // max값을 추출해서 정렬한다.
	print_sorted(sizeof(a)/sizeof(int)); // 정렬된 데이터를 출력한다.
}

int main() {
	heap_sort();
	return 0;
}