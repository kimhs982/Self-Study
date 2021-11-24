#pragma once
#include <iostream>
using std::cout;
using std::ostream;
using std::istream;

#include "ArrayVector.h"

class DataSet
{
	// friend 선언
	friend istream& operator>>(istream&, DataSet&);				// istream (>>)연산자 오버로딩, 전역함수, istream reference형으로 반환, cin>>DataSet객체
	friend ostream& operator<<(ostream&, const DataSet&);				// ostream (<<)연산자 오버로딩, 전역함수, ostream reference형으로 반환, cout<<DataSet객체
	friend void insertionSort(int, DataSet&);				// insertionSort함수, 매개변수로 size와 DataSet객체를 int형과 DataSet reference형으로 받음
	friend void selectionSort(int, DataSet&);				// selectionSort함수, 매개변수로 size와 DataSet객체를 int형과 DataSet reference형으로 받음
	friend void mergeSort(int, DataSet&);				// mergeSort함수, 매개변수로 size와 DataSet객체를 int형과 DataSet reference형으로 받음
	friend void merge(int, int, DataSet&, DataSet&, DataSet&);				// mergeSort함수에 사용할 merge함수, 매개변수로 size와 DataSet 객체를 int형 1개와 DataSet reference형 3개를 받음
	friend void inPlaceQuickSort(DataSet&, int, int);				// inPlaceQuicSort함수, 매개변수로 DataSet객체와 size를 DataSet reference형 1개와 int형 2개로 받음
	friend Elem& selectPivot(DataSet&, int, int);				// inPlaceQuickSort함수에 사용할 selectPivot함수, DataSet객체와 범위를 DataSet referece형과 int형 2개로 받음
public:
	DataSet(ArrayVector&, int);				// 생성자, 매개변수로 ArrayVector객체와 ArrayVector의 size를 ArrayVector reference형과 int형으로 받음
	~DataSet();				// 소멸자, heap의 data가 저장된 공간의 메모리를 해제
	void copy(DataSet&, int, int);				// 특정 DataSet의 ArrayVector와 data의 원소값을 다른 DataSet의 ArrayVector와 data로 복사, 매개변수로 DataSet의 객체와 위치를 DataSet referenc형과 int형 2개를 받음
private:
	ArrayVector& key;				// private data member, DataSet과 관련된 ArrayVector 가리킴(별명), Has-a 관계
	string* data;				// private data member, data를 저장할 공간을 가리킴, string형 포인터
	int size;				// private data member, size를 저장, int형 변수
};