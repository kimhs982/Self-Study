#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <cstdlib>
using std::rand;
using std::srand;

#include <time.h>
using std::time;
using std::clock_t;

#include "SortAlgorithm.h"

enum { INS, SEL, MER, QUI };				// ������(enumeration), INS(0), SEL(1), MER(2), QUI(3)�� �ǹ���

int main()
{
	ArrayVector myKey1, myKey2, myKey3, myKey4;				// ArrayVector Ŭ������ ��ü myKey, copyMyKey, �⺻ ������
	int size, value;				// int�� ����, size�� �����ϰ� ������ ���� �����ϴ� value
	clock_t start, end;				// ���� �ð��� ������ �ð��� �����ϴ� start, end

	srand(static_cast<unsigned int>(time(NULL)));

	cout << "Data Set�� ũ�⸦ �Է��ϼ��� : ";
	cin >> size;

	for (int i = 0; i < size; i++)				// for�ݺ���, i=0���� i=size-1���� i�� 1�� ������Ű�鼭 �ݺ�
	{
		value = rand() % size;
		myKey1.insert(i, value);				// ArrayVector�� ��ü myKey�� �Է¹��� key���� ����
		myKey2.insert(i, value);				// ArrayVector�� ��ü myKey�� �Է¹��� key���� ����
		myKey3.insert(i, value);				// ArrayVector�� ��ü myKey�� �Է¹��� key���� ����
		myKey4.insert(i, value);				// ArrayVector�� ��ü myKey�� �Է¹��� key���� ����
	}

	start = clock();				// ���� �ð� ���� ����
	insertionSort(myKey1.size(), myKey1);				// insertionSort
	end = clock();				// ���� �ð� ���� ����
	cout << "\n<<Insertion Sort>>" << endl;
	cout << "Insertion Sort ���� �ð� : " << (end - start) << "ms" << endl;				// Insertion Sort ���� �ð� ���
	cout << "Insertion Sort ���� �ð� : " << (static_cast<double>(end - start)) / CLOCKS_PER_SEC << "s" << endl;				// Insertion Sort ���� �ð� ���

	start = clock();				// ���� �ð� ���� ����
	selectionSort(myKey2.size(), myKey2);				// selectionSort
	end = clock();
	cout << "\n<<Selection Sort>>" << endl;
	cout << "Selection Sort ���� �ð� : " << (end - start) << "ms" << endl;				// Selection Sort ���� �ð� ���
	cout << "Selection Sort ���� �ð� : " << (static_cast<double>(end - start)) / CLOCKS_PER_SEC << "s" << endl;				// Selection Sort ���� �ð� ���

	start = clock();				// ���� �ð� ���� ����
	mergeSort(myKey3.size(), myKey3);				//mergeSort
	end = clock();				// ���� �ð� ���� ����
	cout << "\n<<Merge Sort>>" << endl;
	cout << "Merge Sort ���� �ð� : " << (end - start) << "ms" << endl;				// Merge Sort ���� �ð� ���
	cout << "Merge Sort ���� �ð� : " << (static_cast<double>(end - start)) / CLOCKS_PER_SEC << "s" << endl;				// Merge Sort ���� �ð� ���

	start = clock();				// ���� �ð� ���� ����
	inPlaceQuickSort(myKey4, 0, myKey4.size() - 1);				// quickSort
	end = clock();				// ���� �ð� ���� ����
	cout << "\n<<Quick Sort>>" << endl;
	cout << "Quick Sort ���� �ð� : " << (end - start) << "ms" << endl;				// Quick Sort ���� �ð� ���
	cout << "Quick Sort ���� �ð� : " << (static_cast<double>(end - start)) / CLOCKS_PER_SEC << "s" << endl;				// Quick Sort ���� �ð� ���

	return 0;				// main�Լ� ����
}