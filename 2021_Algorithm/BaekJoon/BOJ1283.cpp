#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

// string, parsing
int n;
bool chk[26]; //대소문자를 구분x
vector<string> ans;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	(cin >> n).get();
	//옵션들이 들어오면
	for (int tc = 0; tc < n; tc++) {
		string str;
		getline(cin, str);

		//옵션을 단어들로 쪼개서 벡터에 넣어준다.
		istringstream ss(str);
		string buf;
		vector<string> v;
		while (getline(ss, buf, ' ')) {
			v.push_back(buf);
		}
		
		bool ok = false;

		//규칙1 적용
		//단어의 첫 글자가 단축키가 지정되었는지 확인
		string newStr;
		int idx = -1;
		for (int i = 0; i < v.size(); i++) {
			string word = v[i];
			
			//단어의 첫글자가 단축키가 아니라면 지정하기
			if (isupper(word[0]) && chk[word[0] - 'A'] == false) {
				chk[word[0] - 'A'] = true;

				if (i == 0)
					newStr += "[";
				else //첫 단어가 아닌 두번째 단어부터는 앞에 공백을 붙여주자.
					newStr += " [";

				newStr += word[0];
				newStr += "]";
				newStr += word.substr(1);
				ok = true;
				idx = i;
				break;
			}
			else if (islower(word[0]) && chk[word[0] - 'a'] == false) {
				chk[word[0] - 'a'] = true;

				if (i == 0)
					newStr += "[";
				else
					newStr += " [";

				newStr += word[0];
				newStr += "]";
				newStr += word.substr(1);
				ok = true;
				idx = i;
				break;
			}
			else {
				if (i == 0) 
					newStr = word;
				else 
					newStr += " " + word;
			}
		}

		if (ok) {
			//단축키를 지정한 뒤에 단어들은 이어서 붙여준다.
			for (int i = idx + 1; i < v.size(); i++) {
				newStr += " ";
				newStr += v[i];
			}
			ans.push_back(newStr);
			continue;
		}

		//규칙2 적용
		//앞에서부터 모든 단어 하나하나 살펴보면서 단축키가 지정되지 않았다면 지정해주기.
		newStr = "";
		for (int i = 0; i < str.size(); i++) {
			if (isupper(str[i]) && chk[str[i] - 'A'] == false) {
				chk[str[i] - 'A'] = true;
				newStr += "[";
				newStr += str[i];
				newStr += "]";
				newStr += str.substr(i + 1);
				ok = true;
				break;
			}
			else if (islower(str[i]) && chk[str[i] - 'a'] == false) {
				chk[str[i] - 'a'] = true;
				newStr += "[";
				newStr += str[i];
				newStr += "]";
				newStr += str.substr(i + 1);
				ok = true;
				break;
			}
			else
				newStr += str[i];
		}

		if (ok)
			ans.push_back(newStr);
			
		else
			ans.push_back(str);
	}

	for (string s : ans) {
		cout << s << '\n';
	}
	return 0;
}