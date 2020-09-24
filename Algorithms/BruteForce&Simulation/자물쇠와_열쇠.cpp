#include <bits/stdc++.h>
using namespace std;

// 2차원 리스트 90도 회전하기
vector<vector<int> > rotate(vector<vector<int> > a) {
	int n = a.size();    // 행 길이 계산
	int m = a[0].size(); // 열 길이 계산
	vector<vector<int> > result(n, vector<int>(m)); // 결과 리스트
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			result[j][n - 1 - i] = a[i][j];
		}
	}
	return result;
}

// 자물쇠의 중간 부분이 모두 1인지 확인
bool check(vector<vector<int> > newlock) {
	int lock_length = newlock.size() / 3;
	for (int i = lock_length; i < lock_length * 2; i++) {
		for (int j = lock_length; j < lock_length * 2; j++) {
			if (newlock[i][j] != 1) {
				return false;
			}
		}
	}
	return true;
}

bool solution(vector<vector<int> > key, vector<vector<int> > lock) {
	int n = lock.size();
	int m = key.size();
	// 자물쇠의 크기를 기존의 3배로 변환
	vector<vector<int> > newlock(n * 3, vector<int>(n * 3));
	// 새로운 자물쇠의 중앙 부분에 기존의 자물쇠 넣기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			newlock[i + n][j + n] = lock[i][j];
		}
	}

	// 4가지 방향에 대해서 확인
	for (int rotation = 0; rotation < 4; rotation++) {
		key = rotate(key); // 열쇠 회전
		for (int x = 1; x < n * 2; x++) {
			for (int y = 1; y < n * 2; y++) {
				// 예를 들어서 3 x 3 형태에서 확인하면,
				// 위의 2중 포문은 시작 지점을 어디서 할 지 (1,1) ~ (5,5) 정한 다음에
				// 그 위치부터 열쇠를 끼워 넣어서 자물쇠를 풀 수 있는지 확인한다.
				// 쉽게 생각해서 자물쇠에 열쇠를 이리저리 넣어본다.
				for (int i = 0; i < m; i++) {
					for (int j = 0; j < m; j++) { 
						newlock[x + i][y + j] += key[i][j];
					}
				}
				// 새로운 자물쇠에 열쇠가 정확히 들어 맞는지 검사
				if (check(newlock)) return true;
				// 자물쇠에서 열쇠를 다시 빼기
				for (int i = 0; i < m; i++) {
					for (int j = 0; j < m; j++) {
						newlock[x + i][y + j] -= key[i][j];
					}
				}
			}
		}
	}
	return false;
}