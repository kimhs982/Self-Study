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
	cout << "처음, 중간, 끝의 이름을 입력하세요!" << endl;

	getline(cin, from);
	getline(cin, temp);
	getline(cin, to);

	int disk_num;
	cout << "하노이 탑의 원반 갯수를 입력하세요!" << endl;
	cin >> disk_num;

	moveHanoi(from, temp, to, disk_num);

	return 0;
}

void moveHanoi(string from, string temp, string to, int n) {
	if (n == 1) {
		++cnt;
		cout << cnt << ":말뚝 " << from << "에서 말뚝 " << to << "로 원반 1을 이동" << endl;
	}
	else {
		moveHanoi(from, to, temp, n - 1);
		++cnt;
		cout << cnt << ":말뚝 " << from << "에서 말뚝 " << to << "로 원반 " << n << "을 이동" << endl;

		moveHanoi(temp, from, to, n - 1);
	}
}