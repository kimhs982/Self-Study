#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;
using std::getline;

void moveHanoi(string, string, string, int);
int cnt = 0;

int main() {
	string from, temp, to;
	cout << "ó��, �߰�, ���� �̸��� �Է��ϼ���!" << endl;

	getline(cin, from);
	getline(cin, temp);
	getline(cin, to);

	int disk_num;
	cout << "�ϳ��� ž�� ���� ������ �Է��ϼ���!" << endl;
	cin >> disk_num;

	moveHanoi(from, temp, to, disk_num);

	return 0;
}

void moveHanoi(string from, string temp, string to, int n) {
	if (n == 1) {
		++cnt;
		cout << cnt << ":���� " << from << "���� ���� " << to << "�� ���� 1�� �̵�" << endl;
	}
	else {
		moveHanoi(from, to, temp, n - 1);
		++cnt;
		cout << cnt << ":���� " << from << "���� ���� " << to << "�� ���� " << n << "�� �̵�" << endl;

		moveHanoi(temp, from, to, n - 1);
	}
}