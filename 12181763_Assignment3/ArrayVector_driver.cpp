#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include "ArrayVector.h"

int main()
{
	ArrayVector myArrVec;				// ArrayVector Ŭ������ ��ü myArrVec ����, �⺻ ������ ȣ��
	cout << "���� ArrayVector�� ����" << endl;				// myArrVec�� �ʱ� ����
	cout << "Size : " << myArrVec.size() << endl;				// myArrVec�� size ���
	cout << "Empty : " << (myArrVec.empty() ? "Yes" : "No") << endl;				// myArrVec�� empty���� ���

	int numCount, inputNum;				// int�� ����
	cout << "\n������ ���� ���� : ";
	cin >> numCount;
	for (int i = 0; i < numCount; i++)				// for�ݺ���, i=0���� numCount - 1���� �ݺ�, i�� 1�� ����
	{
		cout << "A[" << i << "] = ";
		cin >> inputNum;
		myArrVec.insert(i, inputNum);				// insert()�� ���� 0���� numCount - 1���� �迭 ������ �����ϰ�, ������ ���� inputNum ������ �Է�
	}

	try {				// ����ó�� ����
		cout << "\nArrayVector�� �Էµ� ��" << endl;
		for (int j = 0; j < numCount; j++)				// for�ݺ���, j=0���� numCount - 1���� �ݺ�, j�� 1�� ����
			cout << myArrVec.at(j) << endl;				// at()�� ���� 0���� numCount -1���� �迭 ������ ���
	}
	catch (const IndexOutOfBounds& ex1)				//  IndexoutOfBounds�� ��ȯ�� ���
	{
		ex1.printMsg();				// ���� ���� ���
	}

	cout << "\n���� ArrayVector�� ����" << endl;				// myArrVec�� ����
	cout << "Size : " << myArrVec.size() << endl;				// myArrVec�� size ���
	cout << "Empty : " << (myArrVec.empty() ? "Yes" : "No") << endl;				// myArrVec�� empty���� ���

	return 0;
}