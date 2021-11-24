#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "DoublyLinkedList.h"

void addRemove(DLinkedList&, const int, const int);				// add 혹은 remove 연산을 통합 처리하는 함수 prototype

int main()
{
	DLinkedList myDL;				// DLinkedList 클래스의 객체 myDL생성, 기본 생성자

	enum { ADD = 1, REMOVE = 2 };				// enumeration을 이용하여 ADD=1, REMOVE=1로 정의

	int numCount1, numCount2;
	cout << "삽입할 원소 개수 : ";
	cin >> numCount1;

	addRemove(myDL, ADD, numCount1);				// 삽입 연산(ADD), DLinkedList 객체 myDL, 정수형 numCount1을 인수로 전달


	while (1)				// while 반복문
	{
		cout << "삭제할 원소 개수 : ";
		cin >> numCount2;

		if (numCount1 >= numCount2)				// 삽입 연산 횟수 >= 삭제 연산 횟수인 경우
		{
			addRemove(myDL, REMOVE, numCount2);				// 삭제 연산(REMOVE), DLinkedList 객체 myDL, 정수형 numCount2를 인수로 전달
			break;
		}
		else
			cout << "삭제 연산 횟수는 삽입 연산 횟수보다 클 수 없습니다!" << endl;				// 삽입 연산 횟수 < 삭제 연산 횟수인 경우
	}

	return 0;
}

void addRemove(DLinkedList& inputMyDL, const int type, const int count)				// 함수 definition
{
	int typeSpecific, data;
	switch (type)
	{
	case 1:				// 삽입 연산
		for (int i = 0; i < count; i++)
		{
			cout << "삽입 방식(Front=1, Back=2) : ";
			cin >> typeSpecific;
			cout << "입력 데이터 : ";
			cin >> data;
			if (typeSpecific == 1) inputMyDL.addFront(data);				// addFront()함수 실행
			else if (typeSpecific == 2) inputMyDL.addBack(data);				// addBack()함수 실행
			else cout << "잘못된 삽입 연산입니다!" << endl;

			cout << "\nDoubly Linked List의 원소값 출력" << endl;
			inputMyDL.printAll();				// DLinkedList의 원소값 모두 출력
		}
		break;
	case 2:				// 삭제 연산
		for (int i = 0; i < count; i++)
		{
			cout << "삭제 방식(Front=1, Back=2) : ";
			cin >> typeSpecific;
			if (typeSpecific == 1) inputMyDL.removeFront();				// removeFront()함수 실행
			else if (typeSpecific == 2) inputMyDL.removeBack();				// removeBack()함수 실행
			else cout << "잘못된 삭제 연산입니다!" << endl;

			cout << "\nDoubly Linked List의 원소값 출력" << endl;
			inputMyDL.printAll();				// DLinkedList의 원소값 모두 출력
		}
		break;
	default:				// 그 이외의 경우
		cout << "잘못된 연산입니다!" << endl;
		break;
	}

}