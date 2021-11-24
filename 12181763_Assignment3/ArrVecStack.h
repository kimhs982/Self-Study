// "ArrayVector.h"�� ArrayVector Ŭ������ ����
// ArrayVector Ŭ������ ���� �ٸ��� template Ŭ���� ���

#pragma once
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

#include <algorithm>				// max�Լ� ����
using std::max;

class IndexOutOfBounds				// ����ó�� Ŭ����
{
public:
	IndexOutOfBounds(const string& inputMsg) : msg(inputMsg) {}				// ������, �Ű������� const string reference, member initializer�� private ������ ��� msg �ʱ�ȭ
	string getMessage() const				// private ������ ��� msg�� ��ȯ
	{
		return msg;
	}
private:
	string msg;				// private ������ ���
};

class StackEmptyException				// ����ó�� Ŭ����
{
public:
	StackEmptyException(const string& err) : errMsg(err) {}				// ������, �Ű������� const string reference, member initializer�� private ������ ��� errMsg �ʱ�ȭ
	string getMessage() const				// private ������ ��� errMsg�� ��ȯ
	{
		return errMsg;
	}
private:
	string errMsg;				// private ������ ���
};

template <typename Elem>
class ArrVecStack				// ArrVecStack Ŭ����(template class)
{
public:
	ArrVecStack();				// �⺻ ������
	int size() const;				// ArrayVector�� size ��ȯ
	bool empty() const;				// ArrayVector�� empty���� ��ȯ
	Elem& operator[](int i);				// ������ �����ε�, ��ü[����] ���·� ��� ����
	Elem& at(int i) throw(IndexOutOfBounds);				// ArrayVector�� Ư�� ��ġ������ ���� ��ȯ, ����ó��(IndexOutOfBounds)
	void erase(int i);				// ArrayVector�� Ư�� ��ġ������ ���� ����
	void insert(int i, const Elem& e);				// ArrayVector�� Ư�� ��ġ�� ���� ����
	void reserve(int N);				// ArrayVector�� capacity�� �ʰ��� ���� �ԷµǾ��� �� ũ�⸦ 2�� ������Ű�� ���� �״�� ���� �̵�, StackFullException ���� ó�� �����
	const Elem& top() const throw(StackEmptyException);				// ArrVecStack�� �� ���� ���� ��ȯ, ����ó��(StackEmptyException)
	void push(const Elem&);				// ArrayVector�� insert�Լ��� ����Ͽ� ArrVecStack�� push�� ����, ArrVecStack�� �� ���� ���� ����
	Elem pop() throw(StackEmptyException);				// ArrayVector�� erase�Լ��� ����Ͽ� ArrVecStack�� pop�� ����, ArrVecStack�� �� ���� ���� ����
private:
	int capacity;				// ArrayVector�� private ������ ���, int��
	int n;				// ArrayVector�� private ������ ���, int��
	Elem* A;				// ArrayVector�� private ������ ���, template pointer��
};

template <typename Elem>
ArrVecStack<Elem>::ArrVecStack() : capacity(0), n(0), A(NULL) {}				// member initializer�� private ������ ��� capacity, n, A�� ��� �ʱ�ȭ

template <typename Elem>
int ArrVecStack<Elem>::size() const				// template ����Լ�
{
	return n;
}

template <typename Elem>
bool ArrVecStack<Elem>::empty() const				// template ����Լ�
{
	return size() == 0;				// size�� 0�϶��� true, 1�϶��� false�� ��ȯ
}

template <typename Elem>
Elem& ArrVecStack<Elem>::operator[](int i)				// template ����Լ�
{
	return A[i];				// ArrVecStack ��ü[����] == A[����]
}

template <typename Elem>
Elem& ArrVecStack<Elem>::at(int i) throw(IndexOutOfBounds)				// template ����Լ�
{
	if (i < 0 || i >= n)
		throw IndexOutOfBounds("illegal index in function at()");				// ������ index ������ �ʰ��ϸ� ����ó��(IndexOutOfBounds)
	return A[i];
}

template <typename Elem>
void ArrVecStack<Elem>::reserve(int N)				// template ����Լ�
{
	if (capacity >= N) return;				// capacity >= N�� ��� �Լ� ����
	Elem* B = new Elem[N];				// Nũ�� ��ŭ ���ο� �迭 ���� �Ҵ�
	for (int j = 0; j < n; j++)				// ���ο� �迭�� ���� �̵�
		B[j] = A[j];
	if (A != NULL) delete[] A;				// ���� �迭�� �޸� ���� ����
	A = B;				// ���� �迭 �����Ϳ� ���� ������� �迭�� �ּҸ� ����
	capacity = N;				// capacity�� N���� ����
}

template <typename Elem>
void ArrVecStack<Elem>::insert(int i, const Elem& e)				// template ����Լ�
{
	if (n >= capacity)				// n >= capacity�� ���
		reserve(max(1, 2 * capacity));				// 1�� 2 * capacity�� ū ���� argument�� reserve()�Լ��� ����
	for (int j = n - 1; j >= i; j--)
		A[j + 1] = A[j];
	A[i] = e;
	n++;
}

template <typename Elem>
void ArrVecStack<Elem>::erase(int i)				// template ����Լ�
{
	for (int j = i + 1; j < n; j++)
		A[j - 1] = A[j];
	n--;
}

template <typename Elem>
const Elem& ArrVecStack<Elem>::top() const throw(StackEmptyException)					// template ����Լ�
{
	if (empty())				// ArrayVector�� empty�� ���
		throw StackEmptyException("Top of empty stack");				// ����ó��(StackEmptyException)
	return A[n-1];				// ArrVecStack�� �� ���� ���� ��ȯ
}

template <typename Elem>
void ArrVecStack<Elem>::push(const Elem& e)				// template ����Լ�
{
	insert(n, e);
}

template <typename Elem>
Elem ArrVecStack<Elem>::pop() throw(StackEmptyException)				// template ����Լ�
{
	if (empty())				// ArrayVector�� empty�� ���
		throw StackEmptyException("Pop from empty stack");				// ����ó��(StackEmptyException)
	erase(n-1);
	return A[n];				// ArrVecStack�� ���ŵ� �� ��ȯ
}