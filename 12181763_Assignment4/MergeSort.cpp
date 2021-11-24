#include "SortAlgorithm.h"

// �Լ� �����ε�, key��ó��
void merge(int inputH, int inputM, ArrayVector& inputU, ArrayVector& inputV, ArrayVector& inputS)				// merge�Լ�, �Ű������� size�� ArrayVector�� int�� 2���� ArrayVector reference 3���� ����, key�� merge
{
	int i = 0, j = 0, k = 0;				// Ư�� ��ġ index�� ������ 3���� int�� ����
	while (i < inputH && j < inputM)				// i�� inputH���� �۰� j�� inputM���� ���� ���
	{
		if (inputU[i] <= inputV[j])				// inputU[i](=A[i])�� inputV[j](=A[j])���� �۰ų� ���� ���
		{
			inputS[k] = inputU[i];				// inputS[k](=A[k])�� inputU[i](=A[i])�� ����
			i++;				// i�� 1��ŭ ������Ŵ
		}
		else
		{
			inputS[k] = inputV[j];				// inputS[k](=A[k])�� inputV[j](=A[j])�� ����
			j++;				// j�� 1��ŭ ������Ŵ
		}
		k++;				// k�� 1��ŭ ������Ŵ
	}
	if (i >= inputH)				// i�� inputH���� ũ�ų� ������
		inputS.copy(inputV, j, k);				// ArrayVector inputS�� inputV�� ������ �κ��� ����
	else
		inputS.copy(inputU, i, k);				// ArrayVector inputS�� inputU�� ������ �κ��� ����
}

void mergeSort(int n, ArrayVector& S)				// mergeSort�Լ�, �Ű������� size�� ArrayVector�� int���� ArrayVector reference������ ����, key�� ����
{
	const int h = n / 2, m = n - h;				// h�� n/2�� ����(�Ҽ��� ����, int�� ����), m�� n-h�� ����, const int�� ����, �� ���� �Ұ�
	ArrayVector U, V;				// ���ο� �������, ArrayVector U, V

	if (n > 1)				// n�� 1���� ū ���
	{
		U.copy(S, 0, h);				// ���ο� ArrayVector U�� ArrayVector S�� ����(index�� 0���� h-1����) ����
		V.copy(S, h, n);				// ���ο� ArrayVector V�� ArrayVector S�� ����(index�� h���� n-1����) ����
		mergeSort(h, U);				// ���ȣ��, size���� h�� ArrayVector U�� �μ��� �Ѱ���
		mergeSort(m, V);				// ���ȣ��, size���� m�� ArrayVector V�� �μ��� �Ѱ���
		merge(h, m, U, V, S);				// merge�Լ� ȣ��, size���� h,m�� ArrayVector U, V, S�� �μ��� �Ѱ���
	}
}

// �Լ� �����ε�, <key, data>ó��
void merge(int inputH, int inputM, DataSet& inputU, DataSet& inputV, DataSet& inputS)				// merge�Լ�, �Ű������� size�� ArrayVector�� int�� 2���� ArrayVector reference 3���� ����, key�� data�� merge
{
	int i = 0, j = 0, k = 0;				// Ư�� ��ġ index�� ������ 3���� int�� ����
	while (i < inputH && j < inputM)				// i�� inputH���� �۰� j�� inputM���� ���� ���
	{
		if (inputU.key[i] <= inputV.key[j])				// inputU.key[i](=A[i])�� inputV.key[j](=A[j])���� �۰ų� ���� ���
		{
			inputS.key[k] = inputU.key[i];				// inputS.key[k](=A[k])�� inputU.key[i](=A[i])�� ����
			inputS.data[k] = inputU.data[i];				// inputS.data[k]�� inputU.data[i]�� ����
			i++;				// i�� 1��ŭ ������Ŵ
		}
		else
		{
			inputS.key[k] = inputV.key[j];				// inputS.key[k](=A[k])�� inputV.key[j](=A[j])�� ����
			inputS.data[k] = inputV.data[j];				// inputS.data[k]�� inputV.data[j]�� ����
			j++;				// j�� 1��ŭ ������Ŵ
		}
		k++;				// k�� 1��ŭ ������Ŵ
	}
	if (i >= inputH)				// i�� inputH���� ũ�ų� ������
		inputS.copy(inputV, j, k);				// ArrayVector inputS�� inputV�� ������ �κ��� ����
	else
		inputS.copy(inputU, i, k);				// ArrayVector inputS�� inputU�� ������ �κ��� ����
}

void mergeSort(int n, DataSet& S)
{
	const int h = n / 2, m = n - h;				// h�� n/2�� ����(�Ҽ��� ����, int�� ����), m�� n-h�� ����, const int�� ����, �� ���� �Ұ�
	ArrayVector U, V;				// ���ο� �������, ArrayVector U, V
	DataSet u(U, h), v(V, m);				// key�� data�� ������ ���ο� �������, DataSet u, v

	if (n > 1)
	{
		u.copy(S, 0, h);				// ���ο� DataSet u�� DataSet S�� ����(index�� 0���� h-1����) ����
		v.copy(S, h, n);				// ���ο� DataSet v�� DataSet S�� ����(index�� h���� n-1����) ����
		mergeSort(h, u);				// ���ȣ��, size���� h�� DataSet u�� �μ��� �Ѱ���
		mergeSort(m, v);				// ���ȣ��, size���� m�� DataSet v�� �μ��� �Ѱ���
		merge(h, m, u, v, S);				// merge�Լ� ȣ��, size���� h,m�� DataSet u, v, S�� �μ��� �Ѱ���
	}
}