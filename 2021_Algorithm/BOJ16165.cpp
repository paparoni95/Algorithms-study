#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N, M;

class Team
{
public:
	string name;
	vector<string> members;

	void sortTeam()
	{
		sort(members.begin(), members.end());
	}
};

vector<Team> girlGroup;

int findGirlName(string name)
{
	for (int i = 0; i < girlGroup.size(); i++)
	{
		for (int j = 0; j < girlGroup[i].members.size(); j++)
		{
			if (name == girlGroup[i].members[j])
				return i;
		}
	}
	return -1;
}

int findTeamName(string name)
{
	for (int i = 0; i < girlGroup.size(); i++)
	{
		if (name == girlGroup[i].name)
			return i;
	}
	return -1;
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		// 팀이름
		// 인원 수
		// 멤버의 이름
		Team team;
		int num;
		string name;

		cin >> team.name >> num;

		for (int j = 0; j < num; j++)
		{
			cin >> name;
			team.members.push_back(name);
		}

		girlGroup.push_back(team);
	}
	for (int i = 0; i < M; i++)
	{
		// 팀의 이름이나 멤버의 이름
		// 퀴즈의 종류 (0이면 팀의 이름, 1이면 멤버의 이름)
		// 0이면 해당 팀에 속한 멤버의 이름을 사전순으로 출력
		// 1이면 해당 멤버가 속한 팀의 이름을 출력
		string question;
		int questType, idx;
		cin >> question >> questType;

		if (questType)
		{
			idx = findGirlName(question);
			cout << girlGroup[idx].name << '\n';
		}
		else 
		{
			idx = findTeamName(question);
			girlGroup[idx].sortTeam();
			for (int j = 0; j < girlGroup[idx].members.size(); j++)
				cout << girlGroup[idx].members[j] << '\n';
		}
	}
	return 0;
}