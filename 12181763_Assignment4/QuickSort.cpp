#include <cstdlib>
using std::rand;
using std::srand;

#include <ctime>
using std::time;

#include "SortAlgorithm.h"

Elem& mid(Elem& first, Elem& second, Elem& third)				// mid함수, 매개변수로 Elem(int)형 3개를 받음, 중간값을 반환
{
	if (first >= second)				// first가 second보다 크거나 같은경우
		return (second >= third ? second : (first >= third ? third : first));				// second가 third보다 크거나 같으면 second를 반환, 그렇지 않은 경우 frist가 third보다 크거나 같으면 third를 반환, 그렇지 않으면 first를 반환
	else
		return (third >= second ? second : (third >= first ? third : first));				// third가 second보다 크거나 같으면 second를 반환, 그렇지 않은 경우 third가 frist보다 크거나 같으면 third를 반환, 그렇지 않으면 first를 반환
}

template <typename T>
void swap(T& num1, T& num2)				// template함수, 매개변수로 T reference형 2개를 받음
{
	T temp = num1;				// T형 변수 temp에 num1 값을 임시저장
	num1 = num2;				// num1에 num2 값을 저장
	num2 = temp;				// num2에 num1을 저장하였던 temp 값을 저장
}

// 함수 오버로딩, key만처리
Elem& selectPivot(ArrayVector& inS, int inA, int inB)				// selectPivot함수, 매개변수로 ArrayVector와 size를 ArrayVector reference와 int형 2개로 받음, pivot을 선정
{
	int size = inB - inA + 1;				// 범위를 나타내는 inA와 inB를 이용하여 size를 구함, int형 변수
	int num1, num2, num3;				// index 범위 내의 무작위 숫자를 저장할 3개의 int형 변수
	srand(static_cast<unsigned>(time(0)));				// time()함수를 이용하여 현재 시간을 반환, seed(unsigned int)를 srand를 통해 입력함

	while (1)				// while 반복문, while문 내에서 break가 실행되면 종료
	{
		num1 = inA + (rand() % size);				// inA(scailing factor) + 0~size-1 범위의 랜덤 숫자 생성
		num2 = inA + (rand() % size);				// inA(scailing factor) + 0~size-1 범위의 랜덤 숫자 생성
		num3 = inA + (rand() % size);				// inA(scailing factor) + 0~size-1 범위의 랜덤 숫자 생성
		if ((num1 == num2) || (num1 == num3))				// num1과 num2가 같거나 num1과 num3가 같은 경우
			continue;				// continue, 반복문 내의 아래 부분은 실행하지 않고 조건 확인 부분으로 돌아감
		else if (num2 == num3)				// 그 이외에 num2와 num3가 같은 경우
			continue;				// continue, 반복문 내의 아래 부분은 실행하지 않고 조건 확인 부분으로 돌아감
		else
			break;				// 반복문을 종료함
	}

	return mid(inS[num1], inS[num2], inS[num3]);				// mid 함수를 이용하여 ins[num1](=A[num1]), ins[num2](=A[num2]), ins[num3](=A[num3])중 중간값 구하여 반환
}

void inPlaceQuickSort(ArrayVector& S, int a, int b)				// inPlaceQuickSort함수, 매개변수로 ArrayVector와 index정보를 ArrayVector reference와 int형 2개를 받음, key만 정렬
{
	if (a >= b) return;				// a가 b보다 크거나 같으면 함수 종료
	int size = b - a + 1;				// 범위를 나타내는 a와 b를 이용하여 size를 구함, int형 변수
	int pivotNum;				// pivot의 index를 저장할 int형 변수
	if (size >= 3)				// size가 3보다 큰 경우
	{
		pivotNum = S.index(selectPivot(S, a, b));				// pivotNum에 selectPivot()함수와 index()함수로 구한 pivot의 index 값을 저장
		swap(S[pivotNum], S[a]);				// S[pivotNum](=A[pivotNum])과 S[a](=A[a])를 교환
	}
	const Elem& p = S[a];				// const Elem(int) referenc형 변수 p가 S[a]를 가리킴(별명)
	int l = a + 1;				// l이 a+1의 index 값을 저장
	int r = b;				// r이 b의 index 값을 저장

	while (l < r)				// while 반복문, l이 r보다 작을 경우 반복
	{
		while ((l <= r) && (S[l] <= p))				// while 반복문, l이 r보다 작거나 같고 s[l](=A[l])이 p보다 작거나 같을경우 반복
			l++;				// l을 1만큼 증가시킴
		while ((l <= r) && (S[r] >= p))				// while 반복문, l이 r보다 작거나 같고 s[r](=A[r])이 p보다 크거나 같을경우 반복
			r--;				// r을 1만큼 감소시킴
		if (l < r)				// l이 r보다 작을 경우
			swap(S[l], S[r]);				// S[l](=A[l])과 S[r](=A[r])을 교환
	}
	if (S[a] > S[r])				// S[a](=A[a])가 S[r](=A[r])보다 큰 경우
		swap(S[r], S[a]);				// S[r](=A[r])와 S[a](=A[a])을 교환
	inPlaceQuickSort(S, a, r - 1);				// 재귀호출, ArrayVector S와 index정보 a와 r-1을 인수로 넘겨줌
	inPlaceQuickSort(S, r + 1, b);				// 재귀호출, ArrayVector S와 index정보 r+1과 b을 인수로 넘겨줌
}

// 함수 오버로딩, <key, data>처리
Elem& selectPivot(DataSet& inS, int inA, int inB)				// selectPivot함수, 매개변수로 DataSet과 size를 ArrayVector reference와 int형 2개로 받음, pivot을 선정
{
	int size = inB - inA + 1;				// 범위를 나타내는 inA와 inB를 이용하여 size를 구함, int형 변수
	int num1, num2, num3;				// index 범위 내의 무작위 숫자를 저장할 3개의 int형 변수
	srand(static_cast<unsigned>(time(0)));				// time()함수를 이용하여 현재 시간을 반환, seed(unsigned int)를 srand를 통해 입력함

	while (1)				// while 반복문, while문 내에서 break가 실행되면 종료
	{
		num1 = inA + (rand() % size);				// inA(scailing factor) + 0~size-1 범위의 랜덤 숫자 생성
		num2 = inA + (rand() % size);				// inA(scailing factor) + 0~size-1 범위의 랜덤 숫자 생성
		num3 = inA + (rand() % size);				// inA(scailing factor) + 0~size-1 범위의 랜덤 숫자 생성
		if ((num1 == num2) || (num1 == num3))				// num1과 num2가 같거나 num1과 num3가 같은 경우
			continue;				// continue, 반복문 내의 아래 부분은 실행하지 않고 조건 확인 부분으로 돌아감
		else if (num2 == num3)				// 그 이외에 num2와 num3가 같은 경우
			continue;				// continue, 반복문 내의 아래 부분은 실행하지 않고 조건 확인 부분으로 돌아감
		else
			break;				// 반복문을 종료함
	}

	return mid(inS.key[num1], inS.key[num2], inS.key[num3]);				// mid 함수를 이용하여 ins.key[num1](=A[num1]), ins,key[num2](=A[num2]), ins,key[num3](=A[num3])중 중간값 구하여 반환
}

void inPlaceQuickSort(DataSet& S, int a, int b)				// inPlaceQuickSort함수, 매개변수로 DataSet과 index정보를 ArrayVector reference와 int형 2개를 받음, key와 data를 정렬
{
	if (a >= b) return;				// a가 b보다 크거나 같으면 함수 종료
	int size = b - a + 1;				// 범위를 나타내는 a와 b를 이용하여 size를 구함, int형 변수	
	int pivotNum;				// pivot의 index를 저장할 int형 변수
	if (size >= 3)				// size가 3보다 큰 경우
	{
		pivotNum = S.key.index(selectPivot(S, a, b));				// pivotNum에 selectPivot()함수와 index()함수로 구한 pivot의 index 값을 저장
		swap(S.key[pivotNum], S.key[a]);				// S.key[pivotNum](=A[pivotNum])과 S.key[a](=A[a])를 교환
		swap(S.data[pivotNum], S.data[a]);				// S.data[pivotNum]와 S.data[a]를 교환
	}
	const Elem& p = S.key[a];				// const Elem(int) referenc형 변수 p가 S[a]를 가리킴(별명)
	int l = a + 1;				// l이 a+1의 index 값을 저장
	int r = b;				// r이 b의 index 값을 저장

	while (l < r)				// while 반복문, l이 r보다 작을 경우 반복
	{
		while ((l <= r) && (S.key[l] <= p))				// while 반복문, l이 r보다 작거나 같고 s[l](=A[l])이 p보다 작거나 같을경우 반복
			l++;				// l을 1만큼 증가시킴
		while ((l <= r) && (S.key[r] >= p))				// while 반복문, l이 r보다 작거나 같고 s[r](=A[r])이 p보다 크거나 같을경우 반복
			r--;				// r을 1만큼 감소시킴
		if (l < r)				// l이 r보다 작을 경우
		{
			swap(S.key[l], S.key[r]);				// S.key[l](=A[l])과 S.key[r](=A[r])을 교환
			swap(S.data[l], S.data[r]);				// S.data[l]와 S.data[r]를 교환
		}
	}
	if (S.key[a] > S.key[r])				// S[a](=A[a])가 S[r](=A[r])보다 큰 경우
	{
		swap(S.key[r], S.key[a]);				// S.key[r](=A[r])와 S.key[a](=A[a])을 교환
		swap(S.data[r], S.data[a]);				// S.data[r]과 S.data[a]를 교환
	}
	inPlaceQuickSort(S, a, r - 1);				// 재귀호출, ArrayVector S와 index정보 a와 r-1을 인수로 넘겨줌
	inPlaceQuickSort(S, r + 1, b);				// 재귀호출, ArrayVector S와 index정보 r+1과 b을 인수로 넘겨줌
}