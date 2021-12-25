#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;

#include <string>
using std::string;

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "Node.h"

class NonexistentElementException				// 예외 처리 클래스, BinarySearchTree의 remove함수가 존재하지 않는 element를 제거하려고 할때 사용
{
private:
	string errorMsg;				// private data member, 에러 메시지 저장
public:
	NonexistentElementException(const string& err)				// 생성자, 매개변수로 string reference를 const형태로 받는다
	{
		errorMsg = err;				// private data member errorMsg를 err로 초기화
	}
	string getMessage() const				// getMessage함수, 반환형 string, const 멤버함수
	{
		return errorMsg;				// errorMsg 반환
	}
};

ostream& operator<<(ostream& output, const NonexistentElementException& e)				// <<연산자 오버로딩, 전역함수, 매개변수로 ostream reference와 NonexistentElementException referencefmf const 형태로 반는다.
{
	output << e.getMessage();				// cout<<e -> cout<<e.getMessage()로 변경
	return output;				// cout을 반환
}

template <typename Object>
class BinarySearchTree				// BinarySearchTree 클래스, template 클래스
{
	typedef Node<Object>* NodePtr;				// Node<Object>*를 NodePtr로 사용
private:				// private 접근 지정자
	NodePtr ROOT;				// private data member, NodePtr형 변수
	int sz;				// private data member, int형 변수
	bool insType;				// private data member, bool형 변수
	NodePtr finder(const NodePtr p, const Object& k)				// finder함수, 매개변수로 NodePtr을 const형태, Object refernece를 const형태로 받음, 반환형 NodePtr
	{
		insType = false;				// left child 또는 right child가 비어있는 경우 그 비어있는 Node에 값을 저장하는 경우를 표시
		if (isExternal(p))				// left child와 right child가 NULL인 경우
			return p;				// p를 반환
		Object curKey = p->element;				// 현재 element를 저장하는 Object형 변수 curKey
		if (k < curKey)				// k가 curKey보다 작은 경우
		{
			if (p->left != NULL)				// p의 left child가 NULL이 아닌 경우
				return finder(leftChild(p), k);				// finder(p의 left child, k)를 반환, 재귀 호출
			else
			{
				insType = true;				// left child 또는 right child가 비어있는 경우 그 비어있는 Node에 값을 저장하는 경우를 표시
				return p;				// p를 반환
			}
		}
		else if (k > curKey)				// k가 curKey보다 큰 경우
		{
			if (p->right != NULL)				// p의 right child가 NULL이 아닌 경우
				return finder(rightChild(p), k);				// finder(p의 right child, k)를 반환, 재귀 호출
			else
			{
				insType = true;				// left child 또는 right child가 비어있는 경우 그 비어있는 Node에 값을 저장하는 경우를 표시
				return p;				// p를 반환
			}
		}
		else
			return p;				// p를 반환
	}
	NodePtr finder(const NodePtr p, const Object& k, int& lt, int& rt)				// finder함수 오버로딩, 기존 함수에 특정 element의 left횟수와 right 횟수를 구하는 기능 추가
	{
		insType = false;
		if (isExternal(p))
			return p;
		Object curKey = p->element;
		if (k < curKey)
		{
			if (p->left != NULL)
			{
				lt++;				// left한번 수행
				return finder(leftChild(p), k, lt, rt);
			}
			else
			{
				insType = true;
				return p;
			}
		}
		else if (k > curKey)
		{
			if (p->right != NULL)
			{
				rt++;				// right한번 수행
				return finder(rightChild(p), k, lt, rt);
			}
			else
			{
				insType = true;
				return p;
			}
		}
		else
			return p;
	}
	NodePtr inserter(const Object& k)				// inserter함수, 매개변수로 Object reference를 const 형태로 받음, 반환형 NodePtr
	{
		NodePtr p = finder(ROOT, k);				// NodePtr형 변수에 element k를 root부터 찾아서 대입
		if (!insType)				// insType가 false일 경우
			while (leftChild(p) != NULL)				// p의 left child가 NULL이 아닌 경우 반복
				p = finder(leftChild(p), k);				// p에 k를 p의 left child부터 찾아서 대입
		expandExternal(p, k);				// Node를 삽입하는 expandExternal 함수 호출
		return p;				// p를 반환, p는 삽입한 Node의 parent
	}
	NodePtr remover(const NodePtr r)				// remover함수, 매개변수로 NodePtr를 const 형태로 받음, 반환형 NodePtr
	{
		NodePtr p = r;				// NodePtr형 변수에 r을 대입
		if (isExternal(p))				// p의 left child와 right child가 모두 NULL인 경우
			return removeExternal(p);				// left child와 right child가 모두 NULL인 Node를 삭제하는 removeExternal함수 호출
		if (leftChild(p) == NULL)				// p의 left child가 NULL인 경우
			return removeAboveExternal(p, p->right);				// left child와 right child가 모두 NULL인 Node의 parent Node를 삭제, child중 한명이 NULL
		else if (rightChild(p) == NULL)				// p의 right child가 NULL인 경우
			return removeAboveExternal(p, p->left);				// left child와 right child가 모두 NULL인 Node의 parent Node를 삭제, child중 한명이 NULL
		else
		{
			p = leftChild(r);				// r의 left child를 p에 대입
			while (p->right != NULL)				// p의 right child가 NULL이 아닌 경우 반복
				p = rightChild(p);				// p에 p의 right child를 대입
			r->element = p->element;				// r의 element에 p의 element를 대입, inorder 순서의 바로 앞의 element와 교환
			remover(p);				// Node를 제거하는 remover함수 호출
		}
	}
public:				// public 접근 지정자
	static int count;				// static int형 변수 count
	NodePtr find(const Object& k)				// find함수, 매개변수로 Object reference를 const형으로 받음, 반환형 NodePtr
	{
		NodePtr p = finder(ROOT, k);				// NodePtr형 변수에 element k를 root부터 찾아서 대입
		if (isInternal(p) && k == p->element)				// left child와 right child가 모두 NULL이 아니고 Node, k와 p의 element가 일치할때
			return p;				// p를 반환
		else if (k == p->element)				// left child와 right child가 모두 NULL이고 k와 p의 element가 일치할때
			return p;				// p를 반환
		else
			return NULL;				// NULL을 반환
	}
	NodePtr find(const Object& k, int& lt, int& rt)				// find함수 오버로딩, 기존 함수에 특정 element의 left횟수와 right 횟수를 구하는 기능 추가
	{
		NodePtr p = finder(ROOT, k, lt, rt);
		if (isInternal(p) && k == p->element)
			return p;
		else if (k == p->element)
			return p;
		else
			return NULL;
	}
	void insert(const Object& k)				// insert함수, 매개변수로 Object reference를 const형으로 받음
	{
		inserter(k);				// inserter함수를 호출
	}
	void remove(const Object& k) throw(NonexistentElementException)				// romove함수, 매개변수로 Object reference를 const형으로 받음, NonexistentElementException를 예외로 던진다는 것을 알려줌
	{
		NodePtr p = find(k);				// NodePtr형 변수에 element k를 찾아서 대입
		if (p == NULL)				// p가 NULL인 경우
			throw NonexistentElementException("Remove nonexistent element!");				// NonexistentElementException예외를 던짐
		remover(p);				// remover함수를 호출
	}
	NodePtr root() const				// root함수, 반환형 NodePtr
	{
		return ROOT;				// ROOT를 반환
	}
	NodePtr leftChild(NodePtr v) const				// leftChild함수, 매개변수로 NodePtr을 받음, 반환형 NodePtr, const 멤버 함수
	{
		return v->left;				// v의 left child를 반환
	}
	NodePtr rightChild(NodePtr v) const				// rightChild함수, 매개변수로 NodePtr을 받음, 반환형 NodePtr, const 멤버 함수
	{
		return v->right;				// v의 right child를 반환
	}
	bool isExternal(NodePtr n) const				// isExternal함수, 매개변수로 NodePtr을 받음, 반환형 bool, const 멤버 함수
	{
		return (n->left == NULL && n->right == NULL);				// left child와 right child가 모두 NULL인 경우 true를 반환
	}
	bool isInternal(NodePtr n) const				// isInternal함수, 매개변수로 NodePtr을 받음, 반환형 bool, const 멤버 함수
	{
		return !isExternal(n);				// isExternal의 not값을 반환
	}
	bool isRoot(NodePtr n) const				// isRoot함수, 매개변수로 NodePtr을 받음, 반환형 bool, const 멤버 함수
	{
		return (n == ROOT);				// n==ROOT인 경우 true를 반환
	}
	void setRoot(NodePtr r)				// setRoot함수, 매개변수로 NodePtr을 받음
	{
		ROOT = r;				// ROOT에 r을 대입
		r->parent = NULL;				// r의 parent에 NULL을 대입
	}
	void replaceElement(NodePtr n, const Object& o)				// replaceElement함수, 매개변수로 NodePtr와 Object reference를 const형으로 받음
	{
		n->element = o;				// n의 element에 o를 대입
	}
	void swapElements(NodePtr n, NodePtr w)				// swapElement함수, 매개변수로 NodePtr 2개를 받음
	{
		Object temp = w->element;				// Object형 변수 temp에 w의 element를 저장
		w->element = n->element;				// w의 element에 n의 element를 저장
		n->element = temp;				// n의 element에 temp를 저장
	}
	void expandExternal(NodePtr n, const Object& k)				// expandExternal함수, 매개변수로 NodePtr와 Object reference를 const형으로 받음
	{
		if (k > n->element)				// k가 n의 element보다 큰 경우
		{
			n->right = new Node<Object>;				// n의 right child에 Node<Object>를 동적할당
			n->right->parent = n;				// n의 right child의 parent에 n을 대입
			n->right->element = k;				// n의 right child의 element에 k를 대입
		}
		else
		{
			n->left = new Node<Object>;				// n의 left child에 Node<Object>를 동적할당
			n->left->parent = n;				// n의 left child의 parent에 n을 대입
			n->left->element = k;				// n의 left child의 element에 k를 대입
		}
		sz++;
	}
	NodePtr removeExternal(NodePtr n)				// removeExternal함수, 매개변수로 NodePtr를 받음
	{
		NodePtr p = n->parent;				// NodePtr형 변수에 n의 parent를 대입
		if (p->right == n)				// p의 right child가 n인 경우
			p->right = NULL;				// p의 right child를 NULL로 설정
		else
			p->left = NULL;				// p의 left child를 NULL로 설정
		delete n;				// n의 공간 해제
		sz--;				// sz 1만큼 감소
		return p;				// p를 반환
	}
	NodePtr removeAboveExternal(NodePtr n, NodePtr s)				// removeAboveExternal함수, 매개변수로 NodePtr 2개를 받음
	{
		if (isRoot(n))				// n이 root인 경우
			setRoot(s);				// s를 root로 설정
		else
		{
			NodePtr g = n->parent;				// NodePtr형 변수 g에 n의 parnet를 대입
			if (n == g->left)				// n이 g의 left child인 경우
				g->left = s;				// g의 left child를 s로 설정
			else
				g->right = s;				// g의 right child를 s로 설정
			s->parent = g;				// s의 parent를 g로 설정
		}
		delete n;				// n의 공간해제
		sz--;				// sz를 1만큼 감소
		return s;				// s를 반환
	}
	BinarySearchTree(Object elem)				// 생성자, 매개변수로 Object형 변수를 받음
	{
		ROOT = new Node<Object>;				// ROOT에 Node<Object>를 도적할당
		sz = 1;				// sz를 1로 설정
		ROOT->element = elem;				// ROOT의 element를 elem로 설정
		insType = false;				// insType을 false로 설정
	}
	int size() const				// size함수, const 멤버 함수
	{
		return sz;				// sz를 반환
	}
	bool isEmpty() const				// isEmpty함수, 반환형 bool, const 멤버함수
	{
		return (sz == 0);				// sz가 0인 경우 true를 반환
	}
	void preorder(NodePtr v)				// preorder함수, 매개변수로 NodePtr을 받음, 전위순환
	{
		cout << v->element << " ";				// v의 element를 출력

		if (v->left!=NULL)				// v의 left child가 NULL이 아닌 경우
			preorder(leftChild(v));				// 재귀호출
		if (v->right != NULL)				// v의 right child가 NULL이 아닌 경우
			preorder(rightChild(v));				// 재귀호출
	}
	void postorder(NodePtr v)				// postorder함수, 매개변수로 NodePtr을 받음, 후위순환
	{
		if (v->left != NULL)				// v의 left child가 NULL이 아닌 경우
			postorder(leftChild(v));				// 재귀호출
		if (v->right != NULL)				// v의 right child가 NULL이 아닌 경우
			postorder(rightChild(v));				// 재귀호출

		cout << v->element << " ";				// v의 element를 출력
	}
	void inorder(NodePtr v)				// inorder함수, 매개변수로 NodePtr을 받음, 중위순환
	{
		if (v->left != NULL)					// v의 left child가 NULL이 아닌 경우
			inorder(leftChild(v));				// 재귀호출

		cout << v->element << " ";				// v의 element를 출력

		if (v->right != NULL)				// 재귀호출
			inorder(rightChild(v));				// v의 right child가 NULL이 아닌 경우
	}
	void ElemInorder(NodePtr v, Object* inElem)				// ElemInorder함수, 매개변수로 NodePtr형과 Object pointer형을 받음, inorder함수 변형
	{
		if (v->left != NULL)
			ElemInorder(leftChild(v), inElem);

		inElem[count++] = v->element;				// inElem[count]에 v의 element를 저장

		if (v->right != NULL)
			ElemInorder(rightChild(v), inElem);
	}
};

#endif