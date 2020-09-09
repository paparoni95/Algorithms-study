#include <iostream>
using namespace std;

// https://blog.naver.com/ndb796/221228342808

int number = 9;
int heap[9] = { 7,6,5,8,3,5,9,1,6 };

int main() {
	// 먼저 전체 트리 구조를 최대 힙 구조로 바꾼다.
	for (int i = 1; i < number; i++) {
		int child = i;
		do {
			int root = (child - 1) / 2;
			if (heap[root] < heap[child]) { // 부모노드 < 자식노드
				int temp = heap[root];
				heap[root] = heap[child];
				heap[child] = temp;
			}
			child = root; // 상향식 구현
		} while (child != 0);
	}
	// 크기를 줄여가며 반복적으로 힙을 구성한다.
	for (int i = number - 1; i >= 0; i--) {
		// 루트노드와 가장 마지막의 노드의 값을 서로 swap하면서 정렬을 한다.
		int temp = heap[0]; // 루트 노드
		heap[0] = heap[i];
		heap[i] = temp;
		int root = 0;
		int child = 1;
		do {
			child = 2 * root + 1;
			// 자식 중에서 더 큰 값을 찾기
			if (heap[child] < heap[child + 1] && child < i - 1) {
				child++;
			}
			// 루트보다 자식이 더 크다면 교환
			if (heap[root] < heap[child] && child < i) {
				int temp = heap[root];
				heap[root] = heap[child];
				heap[child] = temp;
			}
			root = child;
		} while (child < i);
	}

	// 결과를 출력하기
	for (int i = 0; i < number; i++)
		cout << heap[i] << ' ';

	return 0;
}