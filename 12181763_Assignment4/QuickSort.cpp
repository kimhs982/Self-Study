#include <cstdlib>
using std::rand;
using std::srand;

#include <ctime>
using std::time;

#include "SortAlgorithm.h"

Elem& mid(Elem& first, Elem& second, Elem& third)				// mid�Լ�, �Ű������� Elem(int)�� 3���� ����, �߰����� ��ȯ
{
	if (first >= second)				// first�� second���� ũ�ų� �������
		return (second >= third ? second : (first >= third ? third : first));				// second�� third���� ũ�ų� ������ second�� ��ȯ, �׷��� ���� ��� frist�� third���� ũ�ų� ������ third�� ��ȯ, �׷��� ������ first�� ��ȯ
	else
		return (third >= second ? second : (third >= first ? third : first));				// third�� second���� ũ�ų� ������ second�� ��ȯ, �׷��� ���� ��� third�� frist���� ũ�ų� ������ third�� ��ȯ, �׷��� ������ first�� ��ȯ
}

template <typename T>
void swap(T& num1, T& num2)				// template�Լ�, �Ű������� T reference�� 2���� ����
{
	T temp = num1;				// T�� ���� temp�� num1 ���� �ӽ�����
	num1 = num2;				// num1�� num2 ���� ����
	num2 = temp;				// num2�� num1�� �����Ͽ��� temp ���� ����
}

// �Լ� �����ε�, key��ó��
Elem& selectPivot(ArrayVector& inS, int inA, int inB)				// selectPivot�Լ�, �Ű������� ArrayVector�� size�� ArrayVector reference�� int�� 2���� ����, pivot�� ����
{
	int size = inB - inA + 1;				// ������ ��Ÿ���� inA�� inB�� �̿��Ͽ� size�� ����, int�� ����
	int num1, num2, num3;				// index ���� ���� ������ ���ڸ� ������ 3���� int�� ����
	srand(static_cast<unsigned>(time(0)));				// time()�Լ��� �̿��Ͽ� ���� �ð��� ��ȯ, seed(unsigned int)�� srand�� ���� �Է���

	while (1)				// while �ݺ���, while�� ������ break�� ����Ǹ� ����
	{
		num1 = inA + (rand() % size);				// inA(scailing factor) + 0~size-1 ������ ���� ���� ����
		num2 = inA + (rand() % size);				// inA(scailing factor) + 0~size-1 ������ ���� ���� ����
		num3 = inA + (rand() % size);				// inA(scailing factor) + 0~size-1 ������ ���� ���� ����
		if ((num1 == num2) || (num1 == num3))				// num1�� num2�� ���ų� num1�� num3�� ���� ���
			continue;				// continue, �ݺ��� ���� �Ʒ� �κ��� �������� �ʰ� ���� Ȯ�� �κ����� ���ư�
		else if (num2 == num3)				// �� �̿ܿ� num2�� num3�� ���� ���
			continue;				// continue, �ݺ��� ���� �Ʒ� �κ��� �������� �ʰ� ���� Ȯ�� �κ����� ���ư�
		else
			break;				// �ݺ����� ������
	}

	return mid(inS[num1], inS[num2], inS[num3]);				// mid �Լ��� �̿��Ͽ� ins[num1](=A[num1]), ins[num2](=A[num2]), ins[num3](=A[num3])�� �߰��� ���Ͽ� ��ȯ
}

void inPlaceQuickSort(ArrayVector& S, int a, int b)				// inPlaceQuickSort�Լ�, �Ű������� ArrayVector�� index������ ArrayVector reference�� int�� 2���� ����, key�� ����
{
	if (a >= b) return;				// a�� b���� ũ�ų� ������ �Լ� ����
	int size = b - a + 1;				// ������ ��Ÿ���� a�� b�� �̿��Ͽ� size�� ����, int�� ����
	int pivotNum;				// pivot�� index�� ������ int�� ����
	if (size >= 3)				// size�� 3���� ū ���
	{
		pivotNum = S.index(selectPivot(S, a, b));				// pivotNum�� selectPivot()�Լ��� index()�Լ��� ���� pivot�� index ���� ����
		swap(S[pivotNum], S[a]);				// S[pivotNum](=A[pivotNum])�� S[a](=A[a])�� ��ȯ
	}
	const Elem& p = S[a];				// const Elem(int) referenc�� ���� p�� S[a]�� ����Ŵ(����)
	int l = a + 1;				// l�� a+1�� index ���� ����
	int r = b;				// r�� b�� index ���� ����

	while (l < r)				// while �ݺ���, l�� r���� ���� ��� �ݺ�
	{
		while ((l <= r) && (S[l] <= p))				// while �ݺ���, l�� r���� �۰ų� ���� s[l](=A[l])�� p���� �۰ų� ������� �ݺ�
			l++;				// l�� 1��ŭ ������Ŵ
		while ((l <= r) && (S[r] >= p))				// while �ݺ���, l�� r���� �۰ų� ���� s[r](=A[r])�� p���� ũ�ų� ������� �ݺ�
			r--;				// r�� 1��ŭ ���ҽ�Ŵ
		if (l < r)				// l�� r���� ���� ���
			swap(S[l], S[r]);				// S[l](=A[l])�� S[r](=A[r])�� ��ȯ
	}
	if (S[a] > S[r])				// S[a](=A[a])�� S[r](=A[r])���� ū ���
		swap(S[r], S[a]);				// S[r](=A[r])�� S[a](=A[a])�� ��ȯ
	inPlaceQuickSort(S, a, r - 1);				// ���ȣ��, ArrayVector S�� index���� a�� r-1�� �μ��� �Ѱ���
	inPlaceQuickSort(S, r + 1, b);				// ���ȣ��, ArrayVector S�� index���� r+1�� b�� �μ��� �Ѱ���
}

// �Լ� �����ε�, <key, data>ó��
Elem& selectPivot(DataSet& inS, int inA, int inB)				// selectPivot�Լ�, �Ű������� DataSet�� size�� ArrayVector reference�� int�� 2���� ����, pivot�� ����
{
	int size = inB - inA + 1;				// ������ ��Ÿ���� inA�� inB�� �̿��Ͽ� size�� ����, int�� ����
	int num1, num2, num3;				// index ���� ���� ������ ���ڸ� ������ 3���� int�� ����
	srand(static_cast<unsigned>(time(0)));				// time()�Լ��� �̿��Ͽ� ���� �ð��� ��ȯ, seed(unsigned int)�� srand�� ���� �Է���

	while (1)				// while �ݺ���, while�� ������ break�� ����Ǹ� ����
	{
		num1 = inA + (rand() % size);				// inA(scailing factor) + 0~size-1 ������ ���� ���� ����
		num2 = inA + (rand() % size);				// inA(scailing factor) + 0~size-1 ������ ���� ���� ����
		num3 = inA + (rand() % size);				// inA(scailing factor) + 0~size-1 ������ ���� ���� ����
		if ((num1 == num2) || (num1 == num3))				// num1�� num2�� ���ų� num1�� num3�� ���� ���
			continue;				// continue, �ݺ��� ���� �Ʒ� �κ��� �������� �ʰ� ���� Ȯ�� �κ����� ���ư�
		else if (num2 == num3)				// �� �̿ܿ� num2�� num3�� ���� ���
			continue;				// continue, �ݺ��� ���� �Ʒ� �κ��� �������� �ʰ� ���� Ȯ�� �κ����� ���ư�
		else
			break;				// �ݺ����� ������
	}

	return mid(inS.key[num1], inS.key[num2], inS.key[num3]);				// mid �Լ��� �̿��Ͽ� ins.key[num1](=A[num1]), ins,key[num2](=A[num2]), ins,key[num3](=A[num3])�� �߰��� ���Ͽ� ��ȯ
}

void inPlaceQuickSort(DataSet& S, int a, int b)				// inPlaceQuickSort�Լ�, �Ű������� DataSet�� index������ ArrayVector reference�� int�� 2���� ����, key�� data�� ����
{
	if (a >= b) return;				// a�� b���� ũ�ų� ������ �Լ� ����
	int size = b - a + 1;				// ������ ��Ÿ���� a�� b�� �̿��Ͽ� size�� ����, int�� ����	
	int pivotNum;				// pivot�� index�� ������ int�� ����
	if (size >= 3)				// size�� 3���� ū ���
	{
		pivotNum = S.key.index(selectPivot(S, a, b));				// pivotNum�� selectPivot()�Լ��� index()�Լ��� ���� pivot�� index ���� ����
		swap(S.key[pivotNum], S.key[a]);				// S.key[pivotNum](=A[pivotNum])�� S.key[a](=A[a])�� ��ȯ
		swap(S.data[pivotNum], S.data[a]);				// S.data[pivotNum]�� S.data[a]�� ��ȯ
	}
	const Elem& p = S.key[a];				// const Elem(int) referenc�� ���� p�� S[a]�� ����Ŵ(����)
	int l = a + 1;				// l�� a+1�� index ���� ����
	int r = b;				// r�� b�� index ���� ����

	while (l < r)				// while �ݺ���, l�� r���� ���� ��� �ݺ�
	{
		while ((l <= r) && (S.key[l] <= p))				// while �ݺ���, l�� r���� �۰ų� ���� s[l](=A[l])�� p���� �۰ų� ������� �ݺ�
			l++;				// l�� 1��ŭ ������Ŵ
		while ((l <= r) && (S.key[r] >= p))				// while �ݺ���, l�� r���� �۰ų� ���� s[r](=A[r])�� p���� ũ�ų� ������� �ݺ�
			r--;				// r�� 1��ŭ ���ҽ�Ŵ
		if (l < r)				// l�� r���� ���� ���
		{
			swap(S.key[l], S.key[r]);				// S.key[l](=A[l])�� S.key[r](=A[r])�� ��ȯ
			swap(S.data[l], S.data[r]);				// S.data[l]�� S.data[r]�� ��ȯ
		}
	}
	if (S.key[a] > S.key[r])				// S[a](=A[a])�� S[r](=A[r])���� ū ���
	{
		swap(S.key[r], S.key[a]);				// S.key[r](=A[r])�� S.key[a](=A[a])�� ��ȯ
		swap(S.data[r], S.data[a]);				// S.data[r]�� S.data[a]�� ��ȯ
	}
	inPlaceQuickSort(S, a, r - 1);				// ���ȣ��, ArrayVector S�� index���� a�� r-1�� �μ��� �Ѱ���
	inPlaceQuickSort(S, r + 1, b);				// ���ȣ��, ArrayVector S�� index���� r+1�� b�� �μ��� �Ѱ���
}