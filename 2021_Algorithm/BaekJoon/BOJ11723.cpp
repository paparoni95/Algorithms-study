#include <iostream>
#include <cstdio>
#include <set>
#include <string>
using namespace std;

int main() {

	int m;
	scanf("%d", &m);
	set<int> s;
	set<int> allSet = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	char str[7];
	int n;
	while (m--) {
		scanf("%s", str);
		if (str[1] == 'd') {
			scanf("%d", &n);
			s.insert(n);
		}
		else if (str[0] == 'c') {
			scanf("%d", &n);
			if (s.find(n) != s.end())
				printf("1\n");
			else
				printf("0\n");
		}
		else if (str[0] == 'r') {
			scanf("%d", &n);
			s.erase(n);
		}
		else if (str[0] == 't') {
			scanf("%d", &n);
			if (s.find(n) != s.end())
				s.erase(n);
			else
				s.insert(n);
		}
		else if (str[1] == 'l') {
			s = allSet;
		}
		else if (str[0] == 'e') {
			s.clear();
		}
	}
	return 0;
}