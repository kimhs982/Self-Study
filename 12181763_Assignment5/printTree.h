#ifndef PRINTTREE_H
#define PRINTTREE_H

#include "Node.h"
#include "BinarySearchTree.h"

struct State				// State structure(구조체)
{
	int Em;				// element를 저장
	int lt;				// left 횟수를 저장
	int rt;				// right 횟수를 저장
	int ht;				// height를 저장
	State() : Em(0), lt(0), rt(0), ht(0) {}				// 기본 생성자, Em, lt, rt, ht를 모두 0으로 초기화
	void clear()				// clear함수
	{
		Em = lt = rt = ht = 0;				// Em, lt, rt, ht를 모두 0으로 초기화
	}
};

template <typename Object>
void setState(BinarySearchTree<Object>& inBST, State* inTKey, Object* inElem, int inTreeSize)				// setState함수, 매개변수로 BinarySearchTree<Object> reference와 State pointer와 Object pointer와 int형을 받음
{
	inBST.ElemInorder(inBST.root(), inElem);				// 중위순환하며 값을 배열에 저장하는 함수 ElemInorder호출
	for (int i = 0; i < inTreeSize; i++)				// for 반복문, i=0부터 inTreeSize-1까지 1씩 증가시키며 반복
	{
		inBST.find(inElem[i], inTKey[i].lt, inTKey[i].rt);				// left와 right 횟수를 계산하기 위한 find함수 호출
		inTKey[i].Em = inElem[i];				// inTKey[i].Em에 inElem[i]를 저장
		inTKey[i].ht = inTKey[i].lt + inTKey[i].rt;				// height = left호출 횟수 + right호출 횟수
	}
}

int htMax(State* inTKey, int st)				// htMax함수, 매개변수로 State pointer와 int형을 받음, 반환형 int, Tree의 height를 계산
{
	int temp = inTKey[0].ht;
	for (int i = 1; i < st; i++)				// for 반복문, i=1부터 st-1까지 1씩 증가시키며 반복, Node의 height의 최대값 찾기
	{
		if (temp < inTKey[i].ht)
			temp = inTKey[i].ht;
	}
	return temp;				// temp를 반환
}

int htNum(State* inTKey, int inHt, int inSt)				// htNum함수, 매개변수로 State pointer와 int형 2개를 받음, 반환형 int, 같은 height의 Node 수를 계산
{
	int count = 0;
	for (int i = 0; i < inSt; i++)				// for 반복문, i=0부터 st-1까지 1씩 증가시키며 반복, 특정 height의 Node 수를 계산
	{
		if (inTKey[i].ht == inHt)
			count++;
	}
	return count;				// count를 반환
}

void printChild(State* inTKey, int inHt, int inSt)				// printChild함수, 매개변수로 State pointer와 int형 2개를 받음, 같은 height의 Node의 element를 출력
{
	int childNum = htNum(inTKey, inHt, inSt);				// 특정 height의 Node수를 int형 변수에 저장
	int count = 0;
	int index;
	static int blank = inSt * 2;				// 빈칸의 갯수를 저장하기 위한 static int형 변수
	if (inHt != 0)				// Node의 height가 0이 아닌 경우
		blank -= (htMax(inTKey, inSt) - inHt);				// 빈간의 갯수를 수정
	State* temp1 = new State[childNum];				// State pointer형 변수에 childNum만큰 State배열 동적할당

	for (int i = 0; i < inSt; i++)				// for 반복문, i=1부터 inSt-1까지 1씩 증가시키며 반복, 특정 height를 가진 노드를 복사
	{
		if (inTKey[i].ht == inHt)
		{
			temp1[count] = inTKey[i];
			count++;
		}
	}

	State tempVal;
	for (int i = 0; i < childNum; i++)				// for 반복문, i=0부터 childNum-1까지 1씩 증가시키며 반복, BinarySearchTree의 Node의 element가 왼쪽 Node에 있을 수록 작다, 배열을 순서대로 재배치
	{
		tempVal = temp1[i];
		index = -1;
		for (int j = i + 1; j < childNum; j++)
		{
			if (tempVal.Em > temp1[j].Em)
			{
				tempVal = temp1[j];
				index = j;
			}
		}
		if (index > 0)
		{
			temp1[index] = temp1[i];
			temp1[i] = tempVal;
		}
	}

	for (int i = 0; i < childNum; i++)				// for 반복문, i=0부터 childNum-1까지 1씩 증가시키며 반복
	{
		for (int j = 0; j < (blank * temp1[i].rt); j++)				//for 반복문, j = 0부터 blank*(temp1[i].rt-1)까지 1씩 증가시키며 반복
			cout << " ";				// 빈칸 출력
		cout << temp1[i].Em;				// 정렬된 배열 출력
	}
	cout << endl;

	delete[] temp1;				// temp1의 메모리 공간 해제
}

template <typename Object>
void printTree(State* inTKey, int st)				// printTree함수, 매개변수로 State pointer와 int형 변수를 받음, Tree 형태로 출력
{
	typedef Node<Object>* NodePtr;

	int maxHt = htMax(inTKey, st);				// int형 변수에 Tree의 height를 구하여 대입

	cout << "----------BinarySearchTree----------" << endl;
	for (int i = 0; i < maxHt + 1; i++)				//for 반복문, i = 0부터 maxHt까지 1씩 증가시키며 반복
	{
		cout << "Height[" << i << "] : ";
		printChild(inTKey, i, st);				// printChild호출
	}
}

#endif