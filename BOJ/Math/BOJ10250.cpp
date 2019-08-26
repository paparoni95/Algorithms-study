#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc;
	cin >> tc;
	for (int test_case = 0; test_case < tc; test_case++) {
		int h, w, n;
		cin >> h >> w >> n;
		// 호텔 앞자리 방번호, 뒷자리 방번호
		int first_room_number = 0, last_room_number = 0;

		// N번째 손님은 범위가 어디에 속하는지 (뒷자리)
		for (int i = 1; i <= w; i++) {
			if (i * h >= n) {
				last_room_number = i;
				break;
			}
		}
		// N번째 손님은 몇층에 지정됬는지 (앞자리)
		for (int i = 0; i < h; i++) {
			if (n == last_room_number * h - i) {
				first_room_number = h - i;
				break;
			}
		}
		
		// 뒷자리 번호가 10보다 작다면 0을 포함시켜서 출력
		if (last_room_number < 10) {
			cout << first_room_number << 0 << last_room_number << '\n';
		}
		else { // 아니라면 그냥 앞자리 + 뒷자리
			cout << first_room_number << last_room_number << '\n';
		}
	}
	return 0;
}