#include "SortAlgorithm.h"

// �Լ� �����ε�, key��ó��
void insertionSort(int n, ArrayVector& S)				// insertionSort�Լ�, �Ű������� size�� ArrayVector�� int���� ArrayVector reference������ ����, key�� ����
{
	int j = 0;				// Ư�� ��ġ index�� ������ int�� ����
	Elem key;				// key�� ������ Elem(int)�� ����

	for (int i = 1; i < n; i++)				// for��, i=1���� i=n-1���� i�� 1�� ������Ű�鼭 �ݺ�, ó�� ���Ҵ� ���ĵ� ���̶�� ����
	{
		key = S[i];				// key�� S[i](=A[i])�� ����
		j = i - 1;				// j�� i-1�� ����Ű���� ��
		while (j >= 0 && S[j] > key)				// j�� 0���� ũ�ų� ���� S[j](=A[j])�� key���� Ŭ������ �ݺ�
		{
			S[j + 1] = S[j];				// S[j+1](=A[j+1])�� S[j](=A[j])�� ����
			j--;				// j�� 1��ŭ ���ҽ�Ŵ
		}
		S[j + 1] = key;				// S[j+1](=A[j+1])�� key�� ����
	}
}

// �Լ� �����ε�, <key, data>ó��
void insertionSort(int n, DataSet& S)				// insertionSort�Լ�, �Ű������� size�� DataSet�� int���� DataSet reference������ ����, key�� data�� ����
{
	int j = 0;				// Ư�� ��ġ index�� ������ int�� ����
	Elem key;				// key�� ������ Elem(int)�� ����
	string data;				// data�� ������ string�� ����

	for (int i = 1; i < n; i++)				// for��, i=1���� i=n-1���� i�� 1�� ������Ű�鼭 �ݺ�, ó�� ���Ҵ� ���ĵ� ���̶�� ����
	{
		key = S.key[i];				// key�� S.key[i](=A[i])�� ����
		data = S.data[i];				// data�� S.data[i]�� ����
		j = i - 1;				// j�� i-1�� ����Ű���� ��
		while (j >= 0 && S.key[j] > key)				// j�� 0���� ũ�ų� ���� S[j](=A[j])�� key���� Ŭ������ �ݺ�
		{
			S.key[j + 1] = S.key[j];				// S.key[j+1](=A[j+1])�� S.key[j](=A[j])�� ����
			S.data[j + 1] = S.data[j];				// S.data[j+1]�� S.data[j]�� ����
			j--;				// j�� 1��ŭ ���ҽ�Ŵ
		}
		S.key[j + 1] = key;				// S.key[j+1](=A[j+1])�� key�� ����
		S.data[j + 1] = data;				// S.data[j+1]�� data�� ����
	}
}