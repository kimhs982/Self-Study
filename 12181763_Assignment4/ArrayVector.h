// ����3���� ������ ArrayVector

#pragma once
#include <string>
using std::string;

typedef int Elem;

class IndexOutOfBounds
{
public:
	IndexOutOfBounds(const string&);
	void printMsg() const;
private:
	string msg;
};

class ArrayVector
{
public:
	ArrayVector();
	int size() const;
	bool empty() const;
	Elem& operator[](int);
	Elem& at(int) throw(IndexOutOfBounds);
	void erase(int);
	void insert(int, const Elem&);
	void reserve(int);
	void modify(int, const Elem&);				// ����4���� �߰��� public ��� �Լ�, ArrayVector�� Ư�� ��ġ ����, �Ű������� index�� ���Ұ��� int���� Elem�� const reference������ ����
	void copy(ArrayVector&, int, int);				// ����4���� �߰��� public ��� �Լ�, Ư�� ArrayVector�� �ٸ� ArrayVector�� ����, �Ű������� ������ ArrayVector�� ��ġ�� ArrayVector�� reference���� int�� 2���� ����
	void printAll() const;				// ����4���� �߰��� public ��� �Լ�, ArrayVector�� ��� ���Ҹ� ���, const ��� �Լ��� ���� �Ұ���
	int index(Elem&) const;				// ����4���� �߰��� public ��� �Լ�, ArrayVector Ư�� ������ index���� ���, const ��� �Լ��� ���� �Ұ���
private:
	int capacity;
	int n;
	Elem* A;
};