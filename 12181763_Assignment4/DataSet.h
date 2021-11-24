#pragma once
#include <iostream>
using std::cout;
using std::ostream;
using std::istream;

#include "ArrayVector.h"

class DataSet
{
	// friend ����
	friend istream& operator>>(istream&, DataSet&);				// istream (>>)������ �����ε�, �����Լ�, istream reference������ ��ȯ, cin>>DataSet��ü
	friend ostream& operator<<(ostream&, const DataSet&);				// ostream (<<)������ �����ε�, �����Լ�, ostream reference������ ��ȯ, cout<<DataSet��ü
	friend void insertionSort(int, DataSet&);				// insertionSort�Լ�, �Ű������� size�� DataSet��ü�� int���� DataSet reference������ ����
	friend void selectionSort(int, DataSet&);				// selectionSort�Լ�, �Ű������� size�� DataSet��ü�� int���� DataSet reference������ ����
	friend void mergeSort(int, DataSet&);				// mergeSort�Լ�, �Ű������� size�� DataSet��ü�� int���� DataSet reference������ ����
	friend void merge(int, int, DataSet&, DataSet&, DataSet&);				// mergeSort�Լ��� ����� merge�Լ�, �Ű������� size�� DataSet ��ü�� int�� 1���� DataSet reference�� 3���� ����
	friend void inPlaceQuickSort(DataSet&, int, int);				// inPlaceQuicSort�Լ�, �Ű������� DataSet��ü�� size�� DataSet reference�� 1���� int�� 2���� ����
	friend Elem& selectPivot(DataSet&, int, int);				// inPlaceQuickSort�Լ��� ����� selectPivot�Լ�, DataSet��ü�� ������ DataSet referece���� int�� 2���� ����
public:
	DataSet(ArrayVector&, int);				// ������, �Ű������� ArrayVector��ü�� ArrayVector�� size�� ArrayVector reference���� int������ ����
	~DataSet();				// �Ҹ���, heap�� data�� ����� ������ �޸𸮸� ����
	void copy(DataSet&, int, int);				// Ư�� DataSet�� ArrayVector�� data�� ���Ұ��� �ٸ� DataSet�� ArrayVector�� data�� ����, �Ű������� DataSet�� ��ü�� ��ġ�� DataSet referenc���� int�� 2���� ����
private:
	ArrayVector& key;				// private data member, DataSet�� ���õ� ArrayVector ����Ŵ(����), Has-a ����
	string* data;				// private data member, data�� ������ ������ ����Ŵ, string�� ������
	int size;				// private data member, size�� ����, int�� ����
};