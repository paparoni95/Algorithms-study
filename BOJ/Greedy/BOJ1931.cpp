#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct time {
	int start;
	int end;
}Time;

bool cmp(const Time &a, const Time &b) {
	if (a.end == b.end) { //만약에 끝나는 시간이 같으면
		return a.start < b.start; //시작 시간을 기준으로 정렬한다.
	}
	else {
		return a.end < b.end;
	}
}

int main() {
	int N;
	cin >> N;
        vector<Time> a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i].start >> a[i].end;
	}

	sort(a.begin(), a.end(), cmp);

	int nowTime = 0, cnt = 0;
	for (int i = 0; i < N; i++) { //정렬된 회의 시간을 차례로 보면
		if (nowTime <= a[i].start) { //현재시간보다 같거나 이후시간의 회의라면
			nowTime = a[i].end;  //현재시간을 마감시간으로 갱신
			cnt++;   //회의실 수 1증가(회의를 끝냈으므로)
		}
	}
	cout << cnt;
	return 0;
}
