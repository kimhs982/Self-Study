#include "SortAlgorithm.h"

// 함수 오버로딩, key만처리
void merge(int inputH, int inputM, ArrayVector& inputU, ArrayVector& inputV, ArrayVector& inputS)				// merge함수, 매개변수로 size와 ArrayVector를 int형 2개와 ArrayVector reference 3개를 받음, key만 merge
{
	int i = 0, j = 0, k = 0;				// 특정 위치 index를 저장할 3개의 int형 변수
	while (i < inputH && j < inputM)				// i가 inputH보다 작고 j가 inputM보다 작은 경우
	{
		if (inputU[i] <= inputV[j])				// inputU[i](=A[i])가 inputV[j](=A[j])보다 작거나 같은 경우
		{
			inputS[k] = inputU[i];				// inputS[k](=A[k])에 inputU[i](=A[i])를 대입
			i++;				// i를 1만큼 증가시킴
		}
		else
		{
			inputS[k] = inputV[j];				// inputS[k](=A[k])에 inputV[j](=A[j])를 대입
			j++;				// j를 1만큼 증가시킴
		}
		k++;				// k를 1만큼 증가시킴
	}
	if (i >= inputH)				// i가 inputH보다 크거나 같은때
		inputS.copy(inputV, j, k);				// ArrayVector inputS에 inputV의 나머지 부분을 복사
	else
		inputS.copy(inputU, i, k);				// ArrayVector inputS에 inputU의 나머지 부분을 복사
}

void mergeSort(int n, ArrayVector& S)				// mergeSort함수, 매개변수로 size와 ArrayVector를 int형과 ArrayVector reference형으로 받음, key만 정렬
{
	const int h = n / 2, m = n - h;				// h에 n/2를 저장(소수점 버림, int형 변수), m에 n-h를 저장, const int형 변수, 값 변경 불가
	ArrayVector U, V;				// 새로운 저장공간, ArrayVector U, V

	if (n > 1)				// n이 1보다 큰 경우
	{
		U.copy(S, 0, h);				// 새로운 ArrayVector U에 ArrayVector S의 절반(index가 0부터 h-1까지) 저장
		V.copy(S, h, n);				// 새로운 ArrayVector V에 ArrayVector S의 절반(index가 h부터 n-1까지) 저장
		mergeSort(h, U);				// 재귀호출, size정보 h와 ArrayVector U를 인수로 넘겨줌
		mergeSort(m, V);				// 재귀호출, size정보 m과 ArrayVector V를 인수로 넘겨줌
		merge(h, m, U, V, S);				// merge함수 호출, size정보 h,m과 ArrayVector U, V, S를 인수로 넘겨줌
	}
}

// 함수 오버로딩, <key, data>처리
void merge(int inputH, int inputM, DataSet& inputU, DataSet& inputV, DataSet& inputS)				// merge함수, 매개변수로 size와 ArrayVector를 int형 2개와 ArrayVector reference 3개를 받음, key와 data를 merge
{
	int i = 0, j = 0, k = 0;				// 특정 위치 index를 저장할 3개의 int형 변수
	while (i < inputH && j < inputM)				// i가 inputH보다 작고 j가 inputM보다 작은 경우
	{
		if (inputU.key[i] <= inputV.key[j])				// inputU.key[i](=A[i])가 inputV.key[j](=A[j])보다 작거나 같은 경우
		{
			inputS.key[k] = inputU.key[i];				// inputS.key[k](=A[k])에 inputU.key[i](=A[i])를 대입
			inputS.data[k] = inputU.data[i];				// inputS.data[k]에 inputU.data[i]를 대입
			i++;				// i를 1만큼 증가시킴
		}
		else
		{
			inputS.key[k] = inputV.key[j];				// inputS.key[k](=A[k])에 inputV.key[j](=A[j])를 대입
			inputS.data[k] = inputV.data[j];				// inputS.data[k]에 inputV.data[j]를 대입
			j++;				// j를 1만큼 증가시킴
		}
		k++;				// k를 1만큼 증가시킴
	}
	if (i >= inputH)				// i가 inputH보다 크거나 같은때
		inputS.copy(inputV, j, k);				// ArrayVector inputS에 inputV의 나머지 부분을 복사
	else
		inputS.copy(inputU, i, k);				// ArrayVector inputS에 inputU의 나머지 부분을 복사
}

void mergeSort(int n, DataSet& S)
{
	const int h = n / 2, m = n - h;				// h에 n/2를 저장(소수점 버림, int형 변수), m에 n-h를 저장, const int형 변수, 값 변경 불가
	ArrayVector U, V;				// 새로운 저장공간, ArrayVector U, V
	DataSet u(U, h), v(V, m);				// key와 data를 저장할 새로운 저장공간, DataSet u, v

	if (n > 1)
	{
		u.copy(S, 0, h);				// 새로운 DataSet u에 DataSet S의 절반(index가 0부터 h-1까지) 저장
		v.copy(S, h, n);				// 새로운 DataSet v에 DataSet S의 절반(index가 h부터 n-1까지) 저장
		mergeSort(h, u);				// 재귀호출, size정보 h와 DataSet u를 인수로 넘겨줌
		mergeSort(m, v);				// 재귀호출, size정보 m과 DataSet v를 인수로 넘겨줌
		merge(h, m, u, v, S);				// merge함수 호출, size정보 h,m과 DataSet u, v, S를 인수로 넘겨줌
	}
}