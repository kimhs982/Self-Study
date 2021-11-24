#include "SortAlgorithm.h"

template <typename T>
void exchange(T& num1, T& num2)				// exchange�Լ�, template�Լ�, �Ű������� T reference�� 2���� ����
{
	T temp = num1;				// T�� ����, num1�� ���� �ӽ�����
	num1 = num2;				// num1�� num2�� ����
	num2 = temp;				// num2�� num1�� �ӽ������� temp�� ����
}

// �Լ� �����ε�, key��ó��
void selectionSort(int n, ArrayVector& S)				// selectionSort�Լ�, �Ű������� size�� ArrayVector�� int���� ArrayVector reference������ ����, key�� ����
{
	int smallest;				// ���� ���� key�� index�� ������ int�� ����

	for (int i = 0; i < n - 1; i++)				// for��, i=0���� i=n-2���� i�� 1�� ������Ű�鼭 �ݺ�
	{
		smallest = i;				// smallest�� i�� ����, i�� ���� ���� key�� index�� ����
		for (int j = i + 1; j < n; j++)				// for��, j=i+1���� j=n-1���� j�� 1�� ������Ű�鼭 �ݺ�
		{
			if (S[j] < S[smallest])				// S[j](=A[j])�� S[smallest](=A[smallest])���� ���� ���
				smallest = j;					// smallest�� j�� ����, j�� ���� ���� key�� index�� ����
		}
		exchange(S[i], S[smallest]);				// S[i](=A[i])�� S[smallest](=A[smallest])�� ��ȯ
	}
}

// �Լ� �����ε�, <key, data>ó��
void selectionSort(int n, DataSet& S)				// selectionSort�Լ�, �Ű������� size�� ArrayVector�� int���� ArrayVector reference������ ����, key�� data�� ����
{
	int smallest;				// ���� ���� key�� index�� ������ int�� ����

	for (int i = 0; i < n - 1; i++)				// for��, i=0���� i=n-2���� i�� 1�� ������Ű�鼭 �ݺ�
	{
		smallest = i;				// smallest�� i�� ����, i�� ���� ���� key�� index�� ����
		for (int j = i + 1; j < n; j++)				// for��, j=i+1���� j=n-1���� j�� 1�� ������Ű�鼭 �ݺ�
		{
			if (S.key[j] < S.key[smallest])				// S.key[j](=A[j])�� S.key[smallest](=A[smallest])���� ���� ���
				smallest = j;				// smallest�� j�� ����, j�� ���� ���� key�� index�� ����
		}
		exchange(S.key[i], S.key[smallest]);				// S.key[i](=A[i])�� S.key[smallest](=A[smallest])�� ��ȯ
		exchange(S.data[i], S.data[smallest]);				// S.data[i]�� S.data[smallest]�� ��ȯ
	}
}