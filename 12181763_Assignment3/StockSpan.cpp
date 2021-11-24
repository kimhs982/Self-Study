#include "ArrVecStack.h"

int main()
{
	ArrVecStack<int> myArrVecStack;				// ArrVecStack Ŭ������ ��ü myArrVecStack, Elem�� int�� �����Ͽ� ��ü ����(��ũ, ��Ʈ)
	bool done;
	int dayCount, h;

	cout << "�ֽ� �ü�ǥ�� �ϼ��� �Է��ϼ��� : ";
	cin >> dayCount;
	int* stockPa = new int[dayCount];				// �ְ��� �����ϴ� ������ �迭, dayCount��ŭ int�� �迭�� �����Ҵ�
	int* spanPa = new int[dayCount];				// Span�� �����ϴ� ������ �迪, dayCount��ū int�� �迭�� �����Ҵ�

	cout << "�ֽ� �ü�ǥ�� �ְ��� ���ʴ�� �Է��ϼ���" << endl;
	for (int i = 0; i < dayCount; i++)				// for�ݺ���, i=0~i=dayCount-1���� i�� 1�� ������Ű�鼭 �ݺ�
	{
		cout << i << "�� : ";
		cin >> stockPa[i];
	}

	try {				// ����ó�� ����
		for (int j = 0; j < dayCount; j++)				// for�ݺ���, j=0~j=dayCount-1���ڤ� j�� 1�� ������Ű�鼭 �ݺ�
		{
			done = false;				// �ϼ��� �Ѿ �� ���� done�� false�� ����
			while (!(myArrVecStack.empty() || done))				// while�ݺ���, myArrVecStack�� done�� ��� false�� ���
			{
				if (stockPa[myArrVecStack.top()] <= stockPa[j])				// stockPa[myArrVecStack�� top] <= stock[j]�� ���
					myArrVecStack.pop();				// myArrVecStack���� pop
				else
					done = true;				// �� �̿��� ��� done�� true�� ����
			}

			if (myArrVecStack.empty())				// myArrVecStack�� empty�� ���
				h = -1;				// int�� ���� h�� 1�� ����
			else
				h = myArrVecStack.top();				// �� �̿��� ��� h�� myArrVecStack�� top���� ����

			spanPa[j] = j - h;				// spanPa[j]�� j-h�� ����
			myArrVecStack.push(j);				// myArrVecStack�� j�� push
		}
	}
	catch (const StackEmptyException& ex1)				// StackEmptyException�� ��ȯ�� ���
	{
		cout << ex1.getMessage() << endl;				// ���� ���� ���
	}

	for (int k = 0; k < dayCount; k++)				// for�ݺ���, k=0~k=dayCount-1���� k�� 1�� ������Ű�鼭 �ݺ�
		cout << k + 1 << "���� �ְ� : " << stockPa[k] << ", Span : " << spanPa[k] << endl;				// �ְ��� span ���� ���

	delete[] stockPa;				// �ְ��� �����ϰ� �ִ� stockPa�� �޸� ����
	delete[] spanPa;				// Span�� �����ϰ� �ִ� spanPa�� �޸� ����

	return 0;
}