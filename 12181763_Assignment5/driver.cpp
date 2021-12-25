#include "BinarySearchTree.h"
#include "printTree.h"

int BinarySearchTree<int>::count = 0;

int main()
{
	int treeSize, deleteNum;
	cout << "트리에 삽입할 원소 수를 입력하세요 : ";
	cin >> treeSize;

	int* Elem = new int[treeSize];				// 삽입할 element를 저장할 int형 배열 동적할당
	State* tKey = new State[treeSize];				// height와 left, right 횟수 element를 저장할 State형 배열 동적할당

	for (int i = 0; i < treeSize; i++)				//for 반복문, i = 0부터 treeSize-1까지 1씩 증가시키며 반복
	{
		cout << i + 1 << "번째 원소 : ";
		cin >> Elem[i];
	}

	BinarySearchTree<int> BST(Elem[0]);				// BinarySearchTree클래스의 객체 BST
	for (int i = 1; i < treeSize; i++)				//for 반복문, i = 0부터 treeSize-1까지 1씩 증가시키며 반복
		BST.insert(Elem[i]);				// BST객체의 insert함수 호출

	setState(BST, tKey, Elem, BST.size());				// SetState 함수 호출

	printTree<int>(tKey, BST.size());				// printTree함수 호출

	cout << endl;
	cout << "preorder : ";
	BST.preorder(BST.root());				// 전위순환
	cout << endl;

	cout << "postorder : ";
	BST.postorder(BST.root());				// 후위순환
	cout << endl;

	cout << "inorder : ";
	BST.inorder(BST.root());				// 중위순환
	cout << endl;

	delete[] Elem;				// Elem의 메모리 공간해제
	BinarySearchTree<int>::count = 0;				// BinarySearchTree의 count변수에 0을 대입

	for (int i = 0; i < treeSize; i++)
	{
		tKey[i].clear();				// State 구조체의 Em, lt, rt, ht를 모두 0으로 초기화 하는 clear 함수
	}

	cout << "트리에 삭제할 원소 수를 입력하세요 : ";
	cin >> deleteNum;

	Elem = new int[treeSize - deleteNum];				// element를 저장할 int형 배열 동적할당

	for (int i = 0; i < deleteNum; i++)				//for 반복문, i = 0부터 deleteNum-1까지 1씩 증가시키며 반복
	{
		cout << i + 1 << "번째 원소 : ";
		cin >> Elem[i];
	}

	for (int i = 0; i < deleteNum; i++)				//for 반복문, i = 0부터 deleteNum-1까지 1씩 증가시키며 반복
		BST.remove(Elem[i]);				// BST객체의 remove함수 호출


	setState(BST, tKey, Elem, BST.size());				// SetState 함수 호출

	printTree<int>(tKey, BST.size());				// printTree함수 호출
	
	cout << endl;
	cout << "preorder : ";
	BST.preorder(BST.root());				// 전위순환
	cout << endl;

	cout << "postorder : ";
	BST.postorder(BST.root());				// 후위순환
	cout << endl;

	cout << "inorder : ";
	BST.inorder(BST.root());				//중위순환
	cout << endl;

	delete[] Elem;				// Elem의 메모리 공간 해제
	delete[] tKey;				// tKey의 메모리 공간 해제

	return 0;
}