#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "DoublyLinkedList.h"

void addRemove(DLinkedList&, const int, const int);				// add Ȥ�� remove ������ ���� ó���ϴ� �Լ� prototype

int main()
{
	DLinkedList myDL;				// DLinkedList Ŭ������ ��ü myDL����, �⺻ ������

	enum { ADD = 1, REMOVE = 2 };				// enumeration�� �̿��Ͽ� ADD=1, REMOVE=1�� ����

	int numCount1, numCount2;
	cout << "������ ���� ���� : ";
	cin >> numCount1;

	addRemove(myDL, ADD, numCount1);				// ���� ����(ADD), DLinkedList ��ü myDL, ������ numCount1�� �μ��� ����


	while (1)				// while �ݺ���
	{
		cout << "������ ���� ���� : ";
		cin >> numCount2;

		if (numCount1 >= numCount2)				// ���� ���� Ƚ�� >= ���� ���� Ƚ���� ���
		{
			addRemove(myDL, REMOVE, numCount2);				// ���� ����(REMOVE), DLinkedList ��ü myDL, ������ numCount2�� �μ��� ����
			break;
		}
		else
			cout << "���� ���� Ƚ���� ���� ���� Ƚ������ Ŭ �� �����ϴ�!" << endl;				// ���� ���� Ƚ�� < ���� ���� Ƚ���� ���
	}

	return 0;
}

void addRemove(DLinkedList& inputMyDL, const int type, const int count)				// �Լ� definition
{
	int typeSpecific, data;
	switch (type)
	{
	case 1:				// ���� ����
		for (int i = 0; i < count; i++)
		{
			cout << "���� ���(Front=1, Back=2) : ";
			cin >> typeSpecific;
			cout << "�Է� ������ : ";
			cin >> data;
			if (typeSpecific == 1) inputMyDL.addFront(data);				// addFront()�Լ� ����
			else if (typeSpecific == 2) inputMyDL.addBack(data);				// addBack()�Լ� ����
			else cout << "�߸��� ���� �����Դϴ�!" << endl;

			cout << "\nDoubly Linked List�� ���Ұ� ���" << endl;
			inputMyDL.printAll();				// DLinkedList�� ���Ұ� ��� ���
		}
		break;
	case 2:				// ���� ����
		for (int i = 0; i < count; i++)
		{
			cout << "���� ���(Front=1, Back=2) : ";
			cin >> typeSpecific;
			if (typeSpecific == 1) inputMyDL.removeFront();				// removeFront()�Լ� ����
			else if (typeSpecific == 2) inputMyDL.removeBack();				// removeBack()�Լ� ����
			else cout << "�߸��� ���� �����Դϴ�!" << endl;

			cout << "\nDoubly Linked List�� ���Ұ� ���" << endl;
			inputMyDL.printAll();				// DLinkedList�� ���Ұ� ��� ���
		}
		break;
	default:				// �� �̿��� ���
		cout << "�߸��� �����Դϴ�!" << endl;
		break;
	}

}