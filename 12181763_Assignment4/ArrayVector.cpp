#include <iostream>
using std::cout;
using std::endl;

#include <algorithm>
using std::max;

#include "ArrayVector.h"

ArrayVector::ArrayVector() : capacity(0), n(0), A(NULL) {}

int ArrayVector::size() const
{
	return n;
}

bool ArrayVector::empty() const
{
	return size() == 0;
}

Elem& ArrayVector::operator[](int i)
{
	return A[i];
}

Elem& ArrayVector::at(int i) throw(IndexOutOfBounds)
{
	if (i < 0 || i >= n)
		throw IndexOutOfBounds("illegal index in function at()");
	return A[i];
}

void ArrayVector::reserve(int N)
{
	if (capacity >= N) return;
	Elem* B = new Elem[N];
	for (int j = 0; j < n; j++)
		B[j] = A[j];
	if (A != NULL) delete[] A;
	A = B;
	capacity = N;
}

void ArrayVector::insert(int i, const Elem& e)
{
	if (n >= capacity)
		reserve(max(1, 2 * capacity));
	for (int j = n - 1; j >= i; j--)
		A[j + 1] = A[j];
	A[i] = e;
	n++;
}

void ArrayVector::erase(int i)
{
	for (int j = i + 1; j < n; j++)
		A[j - 1] = A[j];
	n--;
}

IndexOutOfBounds::IndexOutOfBounds(const string& inputMsg) : msg(inputMsg) {}

void IndexOutOfBounds::printMsg() const
{
	cout << msg << endl;
}

void ArrayVector::modify(int i, const Elem& e)
{
	A[i] = e;				// A[i]�� Ư�� ���Ұ��� ����
}

void ArrayVector::copy(ArrayVector& inAR, int num1, int num2)
{
	if (n == 0)				// ����� ArrayVector�� size�� 0�϶�
	{
		int count = 0;				// int�� ����, Ư�� ��ġ�� ǥ���ϱ� ���� index�� ���
		for (int i = num1; i < num2; i++)				// for��, i=num1���� i=num2-1���� i�� 1�� ������Ű�鼭 �ݺ�
		{
			insert(count, inAR[i]);					// ����� ArrayVector�� count��ġ�� ������ ArrayVector inAR[i](=A[i])�� ����, inAR[num1]~inAR[num2-1]������ ����
			count++;				// count�� 1��ŭ ������Ŵ
		}
	}
	else
	{
		int count = num1;				// int�� ����, Ư�� ��ġ�� ǥ���ϱ� ���� index�� ���
		for (int i = num2; i < n; i++)				// for��, i=num2���� i=n-1���� i�� 1�� ������Ű�鼭 �ݺ�
		{
			modify(i, inAR[count]);				// ����� ArrayVector�� i��ġ�� ArrayVector inAR[count](=A[count])�� ����
			count++;				// count�� 1��ŭ ������Ŵ
		}
	}
}

void ArrayVector::printAll() const
{
	for (int i = 0; i < n; i++)				// for��, i=0���� i=n-1���� i�� 1�� ������Ű�鼭 �ݺ�
	{
		cout << A[i];				// A[i]�� ���
		if ((i != n - 1) && (i + 1) % 10 != 0)				// ������ & 10�� �����° �ڷᰡ �ƴҰ�� 
			cout << " ";				// " "�� ���
		if ((i + 1) % 10 == 0)				// 10�� �����° �ڷ��� ���
			cout << "\n";				// ���๮�� "\n" ���
	}
}

int ArrayVector::index(Elem& checkIndex) const
{
	return (&checkIndex - A);				// ArrayVector�� Ư�� ������ �ּҿ��� ArrayVector�� ���ҵ��� �����ּҸ� ����Ű�� A�� �ּҸ� ��, index���� ��ȯ
}