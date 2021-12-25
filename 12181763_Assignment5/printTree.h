#ifndef PRINTTREE_H
#define PRINTTREE_H

#include "Node.h"
#include "BinarySearchTree.h"

struct State				// State structure(����ü)
{
	int Em;				// element�� ����
	int lt;				// left Ƚ���� ����
	int rt;				// right Ƚ���� ����
	int ht;				// height�� ����
	State() : Em(0), lt(0), rt(0), ht(0) {}				// �⺻ ������, Em, lt, rt, ht�� ��� 0���� �ʱ�ȭ
	void clear()				// clear�Լ�
	{
		Em = lt = rt = ht = 0;				// Em, lt, rt, ht�� ��� 0���� �ʱ�ȭ
	}
};

template <typename Object>
void setState(BinarySearchTree<Object>& inBST, State* inTKey, Object* inElem, int inTreeSize)				// setState�Լ�, �Ű������� BinarySearchTree<Object> reference�� State pointer�� Object pointer�� int���� ����
{
	inBST.ElemInorder(inBST.root(), inElem);				// ������ȯ�ϸ� ���� �迭�� �����ϴ� �Լ� ElemInorderȣ��
	for (int i = 0; i < inTreeSize; i++)				// for �ݺ���, i=0���� inTreeSize-1���� 1�� ������Ű�� �ݺ�
	{
		inBST.find(inElem[i], inTKey[i].lt, inTKey[i].rt);				// left�� right Ƚ���� ����ϱ� ���� find�Լ� ȣ��
		inTKey[i].Em = inElem[i];				// inTKey[i].Em�� inElem[i]�� ����
		inTKey[i].ht = inTKey[i].lt + inTKey[i].rt;				// height = leftȣ�� Ƚ�� + rightȣ�� Ƚ��
	}
}

int htMax(State* inTKey, int st)				// htMax�Լ�, �Ű������� State pointer�� int���� ����, ��ȯ�� int, Tree�� height�� ���
{
	int temp = inTKey[0].ht;
	for (int i = 1; i < st; i++)				// for �ݺ���, i=1���� st-1���� 1�� ������Ű�� �ݺ�, Node�� height�� �ִ밪 ã��
	{
		if (temp < inTKey[i].ht)
			temp = inTKey[i].ht;
	}
	return temp;				// temp�� ��ȯ
}

int htNum(State* inTKey, int inHt, int inSt)				// htNum�Լ�, �Ű������� State pointer�� int�� 2���� ����, ��ȯ�� int, ���� height�� Node ���� ���
{
	int count = 0;
	for (int i = 0; i < inSt; i++)				// for �ݺ���, i=0���� st-1���� 1�� ������Ű�� �ݺ�, Ư�� height�� Node ���� ���
	{
		if (inTKey[i].ht == inHt)
			count++;
	}
	return count;				// count�� ��ȯ
}

void printChild(State* inTKey, int inHt, int inSt)				// printChild�Լ�, �Ű������� State pointer�� int�� 2���� ����, ���� height�� Node�� element�� ���
{
	int childNum = htNum(inTKey, inHt, inSt);				// Ư�� height�� Node���� int�� ������ ����
	int count = 0;
	int index;
	static int blank = inSt * 2;				// ��ĭ�� ������ �����ϱ� ���� static int�� ����
	if (inHt != 0)				// Node�� height�� 0�� �ƴ� ���
		blank -= (htMax(inTKey, inSt) - inHt);				// ���� ������ ����
	State* temp1 = new State[childNum];				// State pointer�� ������ childNum��ū State�迭 �����Ҵ�

	for (int i = 0; i < inSt; i++)				// for �ݺ���, i=1���� inSt-1���� 1�� ������Ű�� �ݺ�, Ư�� height�� ���� ��带 ����
	{
		if (inTKey[i].ht == inHt)
		{
			temp1[count] = inTKey[i];
			count++;
		}
	}

	State tempVal;
	for (int i = 0; i < childNum; i++)				// for �ݺ���, i=0���� childNum-1���� 1�� ������Ű�� �ݺ�, BinarySearchTree�� Node�� element�� ���� Node�� ���� ���� �۴�, �迭�� ������� ���ġ
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

	for (int i = 0; i < childNum; i++)				// for �ݺ���, i=0���� childNum-1���� 1�� ������Ű�� �ݺ�
	{
		for (int j = 0; j < (blank * temp1[i].rt); j++)				//for �ݺ���, j = 0���� blank*(temp1[i].rt-1)���� 1�� ������Ű�� �ݺ�
			cout << " ";				// ��ĭ ���
		cout << temp1[i].Em;				// ���ĵ� �迭 ���
	}
	cout << endl;

	delete[] temp1;				// temp1�� �޸� ���� ����
}

template <typename Object>
void printTree(State* inTKey, int st)				// printTree�Լ�, �Ű������� State pointer�� int�� ������ ����, Tree ���·� ���
{
	typedef Node<Object>* NodePtr;

	int maxHt = htMax(inTKey, st);				// int�� ������ Tree�� height�� ���Ͽ� ����

	cout << "----------BinarySearchTree----------" << endl;
	for (int i = 0; i < maxHt + 1; i++)				//for �ݺ���, i = 0���� maxHt���� 1�� ������Ű�� �ݺ�
	{
		cout << "Height[" << i << "] : ";
		printChild(inTKey, i, st);				// printChildȣ��
	}
}

#endif