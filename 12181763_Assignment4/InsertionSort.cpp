#include "SortAlgorithm.h"

// 함수 오버로딩, key만처리
void insertionSort(int n, ArrayVector& S)				// insertionSort함수, 매개변수로 size와 ArrayVector를 int형과 ArrayVector reference형으로 받음, key만 정렬
{
	int j = 0;				// 특정 위치 index를 저장할 int형 변수
	Elem key;				// key를 저장할 Elem(int)형 변수

	for (int i = 1; i < n; i++)				// for문, i=1부터 i=n-1까지 i를 1씩 증가시키면서 반복, 처음 원소는 정렬된 것이라고 간주
	{
		key = S[i];				// key에 S[i](=A[i])를 저장
		j = i - 1;				// j가 i-1을 가리키도록 함
		while (j >= 0 && S[j] > key)				// j가 0보다 크거나 같고 S[j](=A[j])가 key보다 클때까지 반복
		{
			S[j + 1] = S[j];				// S[j+1](=A[j+1])에 S[j](=A[j])를 대입
			j--;				// j를 1만큼 감소시킴
		}
		S[j + 1] = key;				// S[j+1](=A[j+1])에 key를 대입
	}
}

// 함수 오버로딩, <key, data>처리
void insertionSort(int n, DataSet& S)				// insertionSort함수, 매개변수로 size와 DataSet을 int형과 DataSet reference형으로 받음, key와 data를 정렬
{
	int j = 0;				// 특정 위치 index를 저장할 int형 변수
	Elem key;				// key를 저장할 Elem(int)형 변수
	string data;				// data를 저장할 string형 변수

	for (int i = 1; i < n; i++)				// for문, i=1부터 i=n-1까지 i를 1씩 증가시키면서 반복, 처음 원소는 정렬된 것이라고 간주
	{
		key = S.key[i];				// key에 S.key[i](=A[i])를 저장
		data = S.data[i];				// data에 S.data[i]를 저장
		j = i - 1;				// j가 i-1을 가리키도록 함
		while (j >= 0 && S.key[j] > key)				// j가 0보다 크거나 같고 S[j](=A[j])가 key보다 클때까지 반복
		{
			S.key[j + 1] = S.key[j];				// S.key[j+1](=A[j+1])에 S.key[j](=A[j])를 대입
			S.data[j + 1] = S.data[j];				// S.data[j+1]에 S.data[j]를 저장
			j--;				// j를 1만큼 감소시킴
		}
		S.key[j + 1] = key;				// S.key[j+1](=A[j+1])에 key를 대입
		S.data[j + 1] = data;				// S.data[j+1]에 data를 대입
	}
}