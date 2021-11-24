// "ArrayVector.h"의 ArrayVector 클래스의 변형
// ArrayVector 클래스의 경우와 다르게 template 클래스 사용

#pragma once
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

#include <algorithm>				// max함수 정의
using std::max;

class IndexOutOfBounds				// 예외처리 클래스
{
public:
	IndexOutOfBounds(const string& inputMsg) : msg(inputMsg) {}				// 생성자, 매개변수로 const string reference, member initializer로 private 데이터 멤버 msg 초기화
	string getMessage() const				// private 데이터 멤버 msg를 반환
	{
		return msg;
	}
private:
	string msg;				// private 데이터 멤버
};

class StackEmptyException				// 예외처리 클래스
{
public:
	StackEmptyException(const string& err) : errMsg(err) {}				// 생성자, 매개변수로 const string reference, member initializer로 private 데이터 멤버 errMsg 초기화
	string getMessage() const				// private 데이터 멤버 errMsg를 반환
	{
		return errMsg;
	}
private:
	string errMsg;				// private 데이터 멤버
};

template <typename Elem>
class ArrVecStack				// ArrVecStack 클래스(template class)
{
public:
	ArrVecStack();				// 기본 생성자
	int size() const;				// ArrayVector의 size 반환
	bool empty() const;				// ArrayVector의 empty여부 반환
	Elem& operator[](int i);				// 연산자 오버로딩, 객체[정수] 형태로 사용 가능
	Elem& at(int i) throw(IndexOutOfBounds);				// ArrayVector의 특정 위치에서의 값을 반환, 예외처리(IndexOutOfBounds)
	void erase(int i);				// ArrayVector의 특정 위치에서의 값을 삭제
	void insert(int i, const Elem& e);				// ArrayVector의 특정 위치에 값을 삽입
	void reserve(int N);				// ArrayVector의 capacity를 초과한 값이 입력되었을 때 크기를 2배 증가시키고 값을 그대로 복사 이동, StackFullException 예외 처리 사라짐
	const Elem& top() const throw(StackEmptyException);				// ArrVecStack의 맨 위의 값을 반환, 예외처리(StackEmptyException)
	void push(const Elem&);				// ArrayVector의 insert함수를 사용하여 ArrVecStack의 push을 구현, ArrVecStack의 맨 위에 값을 삽입
	Elem pop() throw(StackEmptyException);				// ArrayVector의 erase함수를 사용하여 ArrVecStack의 pop을 구현, ArrVecStack의 맨 위에 값을 삭제
private:
	int capacity;				// ArrayVector의 private 데이터 멤버, int형
	int n;				// ArrayVector의 private 데이터 멤버, int형
	Elem* A;				// ArrayVector의 private 데이터 멤버, template pointer형
};

template <typename Elem>
ArrVecStack<Elem>::ArrVecStack() : capacity(0), n(0), A(NULL) {}				// member initializer로 private 데이터 멤버 capacity, n, A를 모두 초기화

template <typename Elem>
int ArrVecStack<Elem>::size() const				// template 멤버함수
{
	return n;
}

template <typename Elem>
bool ArrVecStack<Elem>::empty() const				// template 멤버함수
{
	return size() == 0;				// size가 0일때는 true, 1일때는 false를 반환
}

template <typename Elem>
Elem& ArrVecStack<Elem>::operator[](int i)				// template 멤버함수
{
	return A[i];				// ArrVecStack 객체[정수] == A[정수]
}

template <typename Elem>
Elem& ArrVecStack<Elem>::at(int i) throw(IndexOutOfBounds)				// template 멤버함수
{
	if (i < 0 || i >= n)
		throw IndexOutOfBounds("illegal index in function at()");				// 정해진 index 범위를 초과하면 예외처리(IndexOutOfBounds)
	return A[i];
}

template <typename Elem>
void ArrVecStack<Elem>::reserve(int N)				// template 멤버함수
{
	if (capacity >= N) return;				// capacity >= N인 경우 함수 종료
	Elem* B = new Elem[N];				// N크기 만큼 새로운 배열 동적 할당
	for (int j = 0; j < n; j++)				// 새로운 배열로 복사 이동
		B[j] = A[j];
	if (A != NULL) delete[] A;				// 원래 배열의 메모리 공간 해제
	A = B;				// 원래 배열 포인터에 새로 만들어진 배열의 주소를 전달
	capacity = N;				// capacity가 N으로 변경
}

template <typename Elem>
void ArrVecStack<Elem>::insert(int i, const Elem& e)				// template 멤버함수
{
	if (n >= capacity)				// n >= capacity인 경우
		reserve(max(1, 2 * capacity));				// 1과 2 * capacity중 큰 값을 argument로 reserve()함수에 전달
	for (int j = n - 1; j >= i; j--)
		A[j + 1] = A[j];
	A[i] = e;
	n++;
}

template <typename Elem>
void ArrVecStack<Elem>::erase(int i)				// template 멤버함수
{
	for (int j = i + 1; j < n; j++)
		A[j - 1] = A[j];
	n--;
}

template <typename Elem>
const Elem& ArrVecStack<Elem>::top() const throw(StackEmptyException)					// template 멤버함수
{
	if (empty())				// ArrayVector가 empty인 경우
		throw StackEmptyException("Top of empty stack");				// 예외처리(StackEmptyException)
	return A[n-1];				// ArrVecStack의 맨 위의 값을 반환
}

template <typename Elem>
void ArrVecStack<Elem>::push(const Elem& e)				// template 멤버함수
{
	insert(n, e);
}

template <typename Elem>
Elem ArrVecStack<Elem>::pop() throw(StackEmptyException)				// template 멤버함수
{
	if (empty())				// ArrayVector가 empty인 경우
		throw StackEmptyException("Pop from empty stack");				// 예외처리(StackEmptyException)
	erase(n-1);
	return A[n];				// ArrVecStack의 제거된 값 반환
}