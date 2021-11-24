// ArrVecStack Ŭ������ ����
// typedef�� Elem�̶�� �̸����� int�� ���

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
	Elem& operator[](int i);
	Elem& at(int i) throw(IndexOutOfBounds);
	void erase(int i);
	void insert(int i, const Elem& e);
	void reserve(int N);
private:
	int capacity;
	int n;
	Elem* A;
};