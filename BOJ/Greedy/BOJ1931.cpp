#include <iostream>
#include <algorithm>
using namespace std;

typedef struct time {
	int start;
	int end;
}Time;

bool cmp(Time a, Time b) {
	if (a.end == b.end) {
		return a.start < b.start;
	}
	else {
		return a.end < b.end;
	}
}

Time arr[100001];

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].start >> arr[i].end;
	}

	sort(arr, arr + N, cmp);

	int nowTime = 0, cnt = 0;
	for (int i = 0; i < N; i++) {
		if (nowTime <= arr[i].start) {
			nowTime = arr[i].end;  //현재시간을 마감시간으로 갱신
			cnt++;   //회의실 수 1증가
		}
	}
	cout << cnt;
	return 0;
}