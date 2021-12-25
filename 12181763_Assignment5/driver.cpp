#include "BinarySearchTree.h"
#include "printTree.h"

int BinarySearchTree<int>::count = 0;

int main()
{
	int treeSize, deleteNum;
	cout << "Ʈ���� ������ ���� ���� �Է��ϼ��� : ";
	cin >> treeSize;

	int* Elem = new int[treeSize];				// ������ element�� ������ int�� �迭 �����Ҵ�
	State* tKey = new State[treeSize];				// height�� left, right Ƚ�� element�� ������ State�� �迭 �����Ҵ�

	for (int i = 0; i < treeSize; i++)				//for �ݺ���, i = 0���� treeSize-1���� 1�� ������Ű�� �ݺ�
	{
		cout << i + 1 << "��° ���� : ";
		cin >> Elem[i];
	}

	BinarySearchTree<int> BST(Elem[0]);				// BinarySearchTreeŬ������ ��ü BST
	for (int i = 1; i < treeSize; i++)				//for �ݺ���, i = 0���� treeSize-1���� 1�� ������Ű�� �ݺ�
		BST.insert(Elem[i]);				// BST��ü�� insert�Լ� ȣ��

	setState(BST, tKey, Elem, BST.size());				// SetState �Լ� ȣ��

	printTree<int>(tKey, BST.size());				// printTree�Լ� ȣ��

	cout << endl;
	cout << "preorder : ";
	BST.preorder(BST.root());				// ������ȯ
	cout << endl;

	cout << "postorder : ";
	BST.postorder(BST.root());				// ������ȯ
	cout << endl;

	cout << "inorder : ";
	BST.inorder(BST.root());				// ������ȯ
	cout << endl;

	delete[] Elem;				// Elem�� �޸� ��������
	BinarySearchTree<int>::count = 0;				// BinarySearchTree�� count������ 0�� ����

	for (int i = 0; i < treeSize; i++)
	{
		tKey[i].clear();				// State ����ü�� Em, lt, rt, ht�� ��� 0���� �ʱ�ȭ �ϴ� clear �Լ�
	}

	cout << "Ʈ���� ������ ���� ���� �Է��ϼ��� : ";
	cin >> deleteNum;

	Elem = new int[treeSize - deleteNum];				// element�� ������ int�� �迭 �����Ҵ�

	for (int i = 0; i < deleteNum; i++)				//for �ݺ���, i = 0���� deleteNum-1���� 1�� ������Ű�� �ݺ�
	{
		cout << i + 1 << "��° ���� : ";
		cin >> Elem[i];
	}

	for (int i = 0; i < deleteNum; i++)				//for �ݺ���, i = 0���� deleteNum-1���� 1�� ������Ű�� �ݺ�
		BST.remove(Elem[i]);				// BST��ü�� remove�Լ� ȣ��


	setState(BST, tKey, Elem, BST.size());				// SetState �Լ� ȣ��

	printTree<int>(tKey, BST.size());				// printTree�Լ� ȣ��
	
	cout << endl;
	cout << "preorder : ";
	BST.preorder(BST.root());				// ������ȯ
	cout << endl;

	cout << "postorder : ";
	BST.postorder(BST.root());				// ������ȯ
	cout << endl;

	cout << "inorder : ";
	BST.inorder(BST.root());				//������ȯ
	cout << endl;

	delete[] Elem;				// Elem�� �޸� ���� ����
	delete[] tKey;				// tKey�� �޸� ���� ����

	return 0;
}