#include "DataSet.h"

DataSet::DataSet(ArrayVector& inKey, int n) : key(inKey), size(n)				// member initializer�� private data member�� key�� size�� �ʱ�ȭ
{
	data = new string[size];				// private data member�� data�� ���ο� ���� �Ҵ�, �����Ҵ�
}

DataSet::~DataSet()
{
	delete[] data;				// �����Ҵ�� data�� �޸� ���� ȸ��
}

void DataSet::copy(DataSet& inDS, int num1, int num2)
{
	if (key.size()== 0)				// ����� ArrayVector�� size�� 0�϶�
	{
		int count = 0;				// int�� ����, Ư�� ��ġ�� ǥ���ϱ� ���� index�� ���
		for (int i = num1; i < num2; i++)				// for��, i=num1���� i=num2-1���� i�� 1�� ������Ű�鼭 �ݺ�
		{
			key.insert(count, inDS.key[i]);				// ����� ArrayVector�� count��ġ�� ������ ArrayVector inDS.key[i](=A[i])�� ����, inDS.key[num1]~inAR.key[num2-1]������ ����
			data[count] = inDS.data[i];				// ����� data�� count��ġ�� ������ ArrayVector inDS.data[i]�� ����, inDS.data[num1]~inDS.data[num2-1]������ ����
			count++;				// count�� 1��ŭ ������Ŵ
		}
	}
	else
	{
		int count = num1;				// int�� ����, Ư�� ��ġ�� ǥ���ϱ� ���� index�� ���
		for (int i = num2; i < key.size(); i++)				// for��, i=num2���� i=n-1���� i�� 1�� ������Ű�鼭 �ݺ�
		{
			key.modify(i, inDS.key[count]);				// ����� ArrayVector�� i��ġ�� ArrayVector inDS.key[count](=A[count])�� ����
			data[i] = inDS.data[count];				// ����� data�� count��ġ�� ������ ArrayVector inDS.data[count]�� ����
			count++;				// count�� 1��ŭ ������Ŵ
		}
	}
}

istream& operator>>(istream& input, DataSet& set)				// cin>>DataSet��ü
{
	Elem inputKey;				// ���Ұ��� �Է¹��� Elem(int)�� ����
	for (int i = 0; i < set.size; i++)				// for��, i=0���� i=set�� size-1���� i�� 1�� ������Ű�鼭 �ݺ�
	{
		cout << "DS[" << i << "] : ";				// "DS[i] : " �������� ���
		input >> inputKey >> set.data[i];				// key�� data���� �������� ����
		set.key.insert(i, inputKey);				// ArrayVector�� set.key�� �Է¹��� inputKey�� ����
	}
	return input;				// input(cin)�� ��ȯ
}

ostream& operator<<(ostream& output, const DataSet& set)				// cout<<DataSet��ü
{
	for (int i = 0; i < set.size; i++)				// for��, i=0���� i=set�� size-1���� i�� 1�� ������Ű�鼭 �ݺ�
	{
		output << "<" << set.key[i] << ", " << set.data[i] << ">";				// set�� ����� key�� data���� <key, data>�������� ���
		if ((i != set.size - 1) && (i + 1) % 10 != 0)				// ������ & 10�� �����° �ڷᰡ �ƴҰ�� 
			output << ", ";				// ", "�� ���
		if ((i + 1) % 10 == 0)				// 10�� �����° �ڷ��� ���
			output << "\n";				// ���๮�� "\n" ���
	}
	return output;				// output(cout)�� ��ȯ
}