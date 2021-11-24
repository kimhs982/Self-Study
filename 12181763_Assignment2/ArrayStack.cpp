#include <iostream>
#include "ArrayStack.h"

using namespace std;

int main(void)				// main�Լ�
{
	ArrayStack <int> mystack;				// ArrayStack ��ü mystack, �ڷ����� ũ��<int>

	try {				// ���� ó�� ����
		cout << mystack.size() << endl;				// mystack�� ���� size ���

		mystack.push(1);				// mystack�� 1�� push
		mystack.push(2);				// mystack�� 2�� push

		cout << mystack.top() << endl;				// mtstack�� ���� �� �κ� ���� ���
		mystack.pop();				// mystack���� ���� �� �κ��� pop

		cout << mystack.top() << endl;				// mtstack�� ���� �� �κ� ���� ���
		cout << mystack.size() << endl;				// mystack�� ���� size ���
	}
	catch (const StackEmptyException& ex1)				// StackEmptyException�� throw�� ��� ���� ó��
	{
		cout << ex1 << endl;				// ������(<<) �����ε�, cout<<e.getMessage();�� ��ȯ
	}
	catch (const StackFullException& ex2)				// StackFullException�� throw�� ��� ���� ó��
	{
		cout << ex2 << endl;				// ������(<<) �����ε�, cout<<e.getMessage();�� ��ȯ
	}

	// ���� mystack���� 1���� ���� �������
	try {				// ���� ó�� ����
		for (int i = 0; i < 10; i++)				// �ݺ��� for, i�� 0���� 9���� 1�� �����ϸ鼭 10�� �ݺ�
		{
			mystack.push(i + 1);				// mystack�� i+1�� push
		}
	}
	catch (const StackEmptyException& ex1)				// StackEmptyException�� throw�� ��� ���� ó��
	{
		cout << ex1 << endl;				// ������(<<) �����ε�, cout<<e.getMessage();�� ��ȯ
	}
	catch (const StackFullException& ex2)				// StackFullException�� throw�� ��� ���� ó��
	{
		cout << ex2 << endl;				// ������(<<) �����ε�, cout<<e.getMessage();�� ��ȯ
	}

	try {				// ���� ó�� ����
		for (int j = 0; j < 11; j++)				// �ݺ��� for, j�� 0���� 9���� 1�� �����ϸ鼭 11�� �ݺ�
		{
			mystack.pop();				// mystack���� ���� �� �κ��� pop
		}
	}
	catch (const StackEmptyException& ex1)				// StackEmptyException�� throw�� ��� ���� ó��
	{
		cout << ex1 << endl;				// ������(<<) �����ε�, cout<<e.getMessage();�� ��ȯ
	}
	catch (const StackFullException& ex2)				// StackFullException�� throw�� ��� ���� ó��
	{
		cout << ex2 << endl;				// ������(<<) �����ε�, cout<<e.getMessage();�� ��ȯ
	}

	return 0;				// main�Լ� ����
}