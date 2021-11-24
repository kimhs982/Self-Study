// ArrVecStack 클래스를 구성
// typedef로 Elem이라는 이름으로 int형 사용

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