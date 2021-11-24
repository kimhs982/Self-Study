#include "SortAlgorithm.h"

template <typename T>
void exchange(T& num1, T& num2)				// exchange함수, template함수, 매개변수로 T reference형 2개를 받음
{
	T temp = num1;				// T형 변수, num1의 값을 임시저장
	num1 = num2;				// num1에 num2를 대입
	num2 = temp;				// num2에 num1을 임시저장한 temp를 대입
}

// 함수 오버로딩, key만처리
void selectionSort(int n, ArrayVector& S)				// selectionSort함수, 매개변수로 size와 ArrayVector를 int형과 ArrayVector reference형으로 받음, key만 정렬
{
	int smallest;				// 가장 작은 key의 index를 저장할 int형 변수

	for (int i = 0; i < n - 1; i++)				// for문, i=0부터 i=n-2까지 i를 1씩 증가시키면서 반복
	{
		smallest = i;				// smallest에 i를 저장, i를 가장 작은 key의 index로 가정
		for (int j = i + 1; j < n; j++)				// for문, j=i+1부터 j=n-1까지 j를 1씩 증가시키면서 반복
		{
			if (S[j] < S[smallest])				// S[j](=A[j])가 S[smallest](=A[smallest])보다 작은 경우
				smallest = j;					// smallest에 j를 저장, j를 가장 작은 key의 index로 간주
		}
		exchange(S[i], S[smallest]);				// S[i](=A[i])와 S[smallest](=A[smallest])를 교환
	}
}

// 함수 오버로딩, <key, data>처리
void selectionSort(int n, DataSet& S)				// selectionSort함수, 매개변수로 size와 ArrayVector를 int형과 ArrayVector reference형으로 받음, key와 data를 정렬
{
	int smallest;				// 가장 작은 key의 index를 저장할 int형 변수

	for (int i = 0; i < n - 1; i++)				// for문, i=0부터 i=n-2까지 i를 1씩 증가시키면서 반복
	{
		smallest = i;				// smallest에 i를 저장, i를 가장 작은 key의 index로 가정
		for (int j = i + 1; j < n; j++)				// for문, j=i+1부터 j=n-1까지 j를 1씩 증가시키면서 반복
		{
			if (S.key[j] < S.key[smallest])				// S.key[j](=A[j])가 S.key[smallest](=A[smallest])보다 작은 경우
				smallest = j;				// smallest에 j를 저장, j를 가장 작은 key의 index로 간주
		}
		exchange(S.key[i], S.key[smallest]);				// S.key[i](=A[i])와 S.key[smallest](=A[smallest])를 교환
		exchange(S.data[i], S.data[smallest]);				// S.data[i]와 S.data[smallest]를 교환
	}
}