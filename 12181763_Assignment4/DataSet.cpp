#include "DataSet.h"

DataSet::DataSet(ArrayVector& inKey, int n) : key(inKey), size(n)				// member initializer로 private data member인 key와 size를 초기화
{
	data = new string[size];				// private data member인 data에 새로운 공간 할당, 동적할당
}

DataSet::~DataSet()
{
	delete[] data;				// 동적할당된 data의 메모리 공간 회수
}

void DataSet::copy(DataSet& inDS, int num1, int num2)
{
	if (key.size()== 0)				// 복사될 ArrayVector의 size가 0일때
	{
		int count = 0;				// int형 변수, 특정 위치를 표현하기 위한 index로 사용
		for (int i = num1; i < num2; i++)				// for문, i=num1부터 i=num2-1까지 i를 1씩 증가시키면서 반복
		{
			key.insert(count, inDS.key[i]);				// 복사될 ArrayVector의 count위치에 복사할 ArrayVector inDS.key[i](=A[i])를 삽입, inDS.key[num1]~inAR.key[num2-1]까지를 복사
			data[count] = inDS.data[i];				// 복사될 data의 count위치에 복사할 ArrayVector inDS.data[i]를 삽입, inDS.data[num1]~inDS.data[num2-1]까지를 복사
			count++;				// count를 1만큼 증가시킴
		}
	}
	else
	{
		int count = num1;				// int형 변수, 특정 위치를 표현하기 위한 index로 사용
		for (int i = num2; i < key.size(); i++)				// for문, i=num2부터 i=n-1까지 i를 1씩 증가시키면서 반복
		{
			key.modify(i, inDS.key[count]);				// 복사될 ArrayVector의 i위치를 ArrayVector inDS.key[count](=A[count])로 수정
			data[i] = inDS.data[count];				// 복사될 data의 count위치에 복사할 ArrayVector inDS.data[count]로 수정
			count++;				// count를 1만큼 증가시킴
		}
	}
}

istream& operator>>(istream& input, DataSet& set)				// cin>>DataSet객체
{
	Elem inputKey;				// 원소값을 입력받을 Elem(int)형 변수
	for (int i = 0; i < set.size; i++)				// for문, i=0부터 i=set의 size-1까지 i를 1씩 증가시키면서 반복
	{
		cout << "DS[" << i << "] : ";				// "DS[i] : " 형식으로 출력
		input >> inputKey >> set.data[i];				// key와 data값을 연속으로 받음
		set.key.insert(i, inputKey);				// ArrayVector인 set.key에 입력받은 inputKey를 삽입
	}
	return input;				// input(cin)을 반환
}

ostream& operator<<(ostream& output, const DataSet& set)				// cout<<DataSet객체
{
	for (int i = 0; i < set.size; i++)				// for문, i=0부터 i=set의 size-1까지 i를 1씩 증가시키면서 반복
	{
		output << "<" << set.key[i] << ", " << set.data[i] << ">";				// set에 저장된 key와 data값을 <key, data>형식으로 출력
		if ((i != set.size - 1) && (i + 1) % 10 != 0)				// 마지막 & 10의 배수번째 자료가 아닐경우 
			output << ", ";				// ", "를 출력
		if ((i + 1) % 10 == 0)				// 10의 배수번째 자료일 경우
			output << "\n";				// 개행문자 "\n" 출력
	}
	return output;				// output(cout)을 받환
}