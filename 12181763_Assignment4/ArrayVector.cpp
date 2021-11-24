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
	A[i] = e;				// A[i]에 특정 원소값을 대입
}

void ArrayVector::copy(ArrayVector& inAR, int num1, int num2)
{
	if (n == 0)				// 복사될 ArrayVector의 size가 0일때
	{
		int count = 0;				// int형 변수, 특정 위치를 표현하기 위한 index로 사용
		for (int i = num1; i < num2; i++)				// for문, i=num1부터 i=num2-1까지 i를 1씩 증가시키면서 반복
		{
			insert(count, inAR[i]);					// 복사될 ArrayVector의 count위치에 복사할 ArrayVector inAR[i](=A[i])를 삽입, inAR[num1]~inAR[num2-1]까지를 복사
			count++;				// count를 1만큼 증가시킴
		}
	}
	else
	{
		int count = num1;				// int형 변수, 특정 위치를 표현하기 위한 index로 사용
		for (int i = num2; i < n; i++)				// for문, i=num2부터 i=n-1까지 i를 1씩 증가시키면서 반복
		{
			modify(i, inAR[count]);				// 복사될 ArrayVector의 i위치를 ArrayVector inAR[count](=A[count])로 수정
			count++;				// count를 1만큼 증가시킴
		}
	}
}

void ArrayVector::printAll() const
{
	for (int i = 0; i < n; i++)				// for문, i=0부터 i=n-1까지 i를 1씩 증가시키면서 반복
	{
		cout << A[i];				// A[i]를 출력
		if ((i != n - 1) && (i + 1) % 10 != 0)				// 마지막 & 10의 배수번째 자료가 아닐경우 
			cout << " ";				// " "를 출력
		if ((i + 1) % 10 == 0)				// 10의 배수번째 자료일 경우
			cout << "\n";				// 개행문자 "\n" 출력
	}
}

int ArrayVector::index(Elem& checkIndex) const
{
	return (&checkIndex - A);				// ArrayVector의 특정 원소의 주소에서 ArrayVector의 원소들의 시작주소를 가리키는 A의 주소를 뺌, index값을 반환
}