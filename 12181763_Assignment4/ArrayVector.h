// 과제3에서 구현한 ArrayVector

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
	void modify(int, const Elem&);				// 과제4에서 추가한 public 멤버 함수, ArrayVector의 특정 위치 수정, 매개변수로 index와 원소값을 int형과 Elem을 const reference형으로 받음
	void copy(ArrayVector&, int, int);				// 과제4에서 추가한 public 멤버 함수, 특정 ArrayVector를 다른 ArrayVector로 복사, 매개변수로 복사할 ArrayVector와 위치를 ArrayVector의 reference형과 int형 2개를 받음
	void printAll() const;				// 과제4에서 추가한 public 멤버 함수, ArrayVector의 모든 원소를 출력, const 멤버 함수로 수정 불가능
	int index(Elem&) const;				// 과제4에서 추가한 public 멤버 함수, ArrayVector 특정 원소의 index값을 출력, const 멤버 함수로 수정 불가능
private:
	int capacity;
	int n;
	Elem* A;
};