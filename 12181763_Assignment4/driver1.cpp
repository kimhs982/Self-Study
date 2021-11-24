#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "SortAlgorithm.h"

enum { INS, SEL, MER, QUI };				// ������(enumeration), INS(0), SEL(1), MER(2), QUI(3)�� �ǹ���

int main()
{
	ArrayVector myKey;				// ArrayVector Ŭ������ ��ü myKey, �⺻ ������
	Elem inputKey;				// Elem(int)�� ����, �Է¹��� key�� �ӽ�����
	int size, method;				// int�� ����, size�� ���� �˰����� ����
	cout << "Data Set�� ũ�⸦ �Է��ϼ��� : ";
	cin >> size;

	cout << "Data Set�� key���� �Է��ϼ���" << endl;
	for (int i = 0; i < size; i++)				// for�ݺ���, i=0���� i=size-1���� i�� 1�� ������Ű�鼭 �ݺ�
	{
		cout << "KEY[" << i << "] : ";
		cin >> inputKey;				// key���� �Է�
		myKey.insert(i, inputKey);				// ArrayVector�� ��ü myKey�� �Է¹��� key���� ����
	}

	cout << "\n<<Unsorted Data Set>>" << endl;
	myKey.printAll();				// �����ϱ� �� �������� ���¸� ���

	cout << "\n\n(Insertion(0), Selection(1), Merge(2), Quick(3))\n"
		<< "���� �˰����� �����ϼ��� : ";
	cin >> method;				// 0, 1, 2, 3 �߿� �ϳ��� �Է��Ͽ� ���� �˰����� ����

	switch (method)				// switch��, method�� ���ڷ� ����
	{
	case INS:				// method==INS(0)�� ���
		insertionSort(myKey.size(), myKey);				// insertionSort
		cout << "\n<<Insertion Sort>>" << endl;
		myKey.printAll();				// ���� �� �������� ���¸� ���
		break;
	case SEL:				// method==SEL(1)�� ���
		selectionSort(myKey.size(), myKey);				// selectionSort
		cout << "\n<<Selection Sort>>" << endl;
		myKey.printAll();				// ���� �� �������� ���¸� ���
		break;
	case MER:				// method==MER(2)�� ���
		mergeSort(myKey.size(), myKey);				//mergeSort
		cout << "\n<<Merge Sort>>" << endl;
		myKey.printAll();				// ���� �� �������� ���¸� ���
		break;
	case QUI:				// method==QUI(3)�� ���
		inPlaceQuickSort(myKey, 0, myKey.size() - 1);				// quickSort
		cout << "\n<<Quick Sort>>" << endl;
		myKey.printAll();				// ���� �� �������� ���¸� ���
		break;
	default:				// method�� 0, 1, 2, 3�� ��찡 �ƴ� ���
		cout << "�߸��� �����Դϴ�!" << endl;				// ���� �޼��� ���
	}

	return 0;				// main�Լ� ����
}