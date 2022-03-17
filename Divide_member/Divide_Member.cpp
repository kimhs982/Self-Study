// 제작자 : 김형석
// 팀의 갯수만큼 사람들을 랜덤하게 배치, 각각의 팀의 남&여 비율을 맞춤, 총 인원수가 팀의 갯수로 정확하게 나누어 떨어지는 경우에만 가능
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand((unsigned int)time(NULL));
	int m_num, w_num, total_num, team_num, member_T_num, member_M_num;
	string name;
	cout << "남자[명수] : ";
	cin >> m_num;
	cout << "여자[명수] : ";
	cin >> w_num;
	total_num = m_num + w_num;

	vector<string> man;
	vector<string> woman;

	cout << "\n<남자>" << endl;
	cout << "이름(space로 구분하여 입력) : ";
	for (int i = 0; i < m_num; i++)
	{
		cin >> name;
		man.emplace_back(name);
	}

	cout << "\n<여자>" << endl;
	cout << "이름(space로 구분하여 입력) : ";
	for (int i = 0; i < w_num; i++)
	{
		cin >> name;
		woman.emplace_back(name);
	}

	cout << "\n팀[수] : ";
	cin >> team_num;
	member_T_num = total_num / team_num;
	member_M_num = m_num / team_num;

	string** team;
	team = new string * [team_num];
	for (int i = 0; i < team_num; i++)
		team[i] = new string[member_T_num];

	for (int i = 0; i < team_num; i++)
	{
		int j;
		for (j = 0; j < member_M_num; j++)
		{
			int m_index = rand() % m_num;
			m_num--;
			team[i][j] = man[m_index];
			man.erase(man.begin() + m_index);
		}
		for (; j < member_T_num; j++)
		{
			int w_index = rand() % w_num;
			w_num--;
			team[i][j] = woman[w_index];
			woman.erase(woman.begin() + w_index);
		}
	}

	cout << "\n<팀원>" << endl;
	for (int i = 0; i < team_num; i++)
	{
		cout << i + 1 << "팀 : ";
		for (int j = 0; j < member_T_num; j++)
			cout << team[i][j] << " ";
		cout << endl;
	}

	for (int i = 0; i < team_num; i++)
		delete[] team[i];
	delete[] team;

	return 0;
}