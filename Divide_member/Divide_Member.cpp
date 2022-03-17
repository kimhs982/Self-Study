// ������ : ������
// ���� ������ŭ ������� �����ϰ� ��ġ, ������ ���� ��&�� ������ ����, �� �ο����� ���� ������ ��Ȯ�ϰ� ������ �������� ��쿡�� ����
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
	cout << "����[���] : ";
	cin >> m_num;
	cout << "����[���] : ";
	cin >> w_num;
	total_num = m_num + w_num;

	vector<string> man;
	vector<string> woman;

	cout << "\n<����>" << endl;
	cout << "�̸�(space�� �����Ͽ� �Է�) : ";
	for (int i = 0; i < m_num; i++)
	{
		cin >> name;
		man.emplace_back(name);
	}

	cout << "\n<����>" << endl;
	cout << "�̸�(space�� �����Ͽ� �Է�) : ";
	for (int i = 0; i < w_num; i++)
	{
		cin >> name;
		woman.emplace_back(name);
	}

	cout << "\n��[��] : ";
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

	cout << "\n<����>" << endl;
	for (int i = 0; i < team_num; i++)
	{
		cout << i + 1 << "�� : ";
		for (int j = 0; j < member_T_num; j++)
			cout << team[i][j] << " ";
		cout << endl;
	}

	for (int i = 0; i < team_num; i++)
		delete[] team[i];
	delete[] team;

	return 0;
}