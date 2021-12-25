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

class NonexistentElementException				// ���� ó�� Ŭ����, BinarySearchTree�� remove�Լ��� �������� �ʴ� element�� �����Ϸ��� �Ҷ� ���
{
private:
	string errorMsg;				// private data member, ���� �޽��� ����
public:
	NonexistentElementException(const string& err)				// ������, �Ű������� string reference�� const���·� �޴´�
	{
		errorMsg = err;				// private data member errorMsg�� err�� �ʱ�ȭ
	}
	string getMessage() const				// getMessage�Լ�, ��ȯ�� string, const ����Լ�
	{
		return errorMsg;				// errorMsg ��ȯ
	}
};

ostream& operator<<(ostream& output, const NonexistentElementException& e)				// <<������ �����ε�, �����Լ�, �Ű������� ostream reference�� NonexistentElementException referencefmf const ���·� �ݴ´�.
{
	output << e.getMessage();				// cout<<e -> cout<<e.getMessage()�� ����
	return output;				// cout�� ��ȯ
}

template <typename Object>
class BinarySearchTree				// BinarySearchTree Ŭ����, template Ŭ����
{
	typedef Node<Object>* NodePtr;				// Node<Object>*�� NodePtr�� ���
private:				// private ���� ������
	NodePtr ROOT;				// private data member, NodePtr�� ����
	int sz;				// private data member, int�� ����
	bool insType;				// private data member, bool�� ����
	NodePtr finder(const NodePtr p, const Object& k)				// finder�Լ�, �Ű������� NodePtr�� const����, Object refernece�� const���·� ����, ��ȯ�� NodePtr
	{
		insType = false;				// left child �Ǵ� right child�� ����ִ� ��� �� ����ִ� Node�� ���� �����ϴ� ��츦 ǥ��
		if (isExternal(p))				// left child�� right child�� NULL�� ���
			return p;				// p�� ��ȯ
		Object curKey = p->element;				// ���� element�� �����ϴ� Object�� ���� curKey
		if (k < curKey)				// k�� curKey���� ���� ���
		{
			if (p->left != NULL)				// p�� left child�� NULL�� �ƴ� ���
				return finder(leftChild(p), k);				// finder(p�� left child, k)�� ��ȯ, ��� ȣ��
			else
			{
				insType = true;				// left child �Ǵ� right child�� ����ִ� ��� �� ����ִ� Node�� ���� �����ϴ� ��츦 ǥ��
				return p;				// p�� ��ȯ
			}
		}
		else if (k > curKey)				// k�� curKey���� ū ���
		{
			if (p->right != NULL)				// p�� right child�� NULL�� �ƴ� ���
				return finder(rightChild(p), k);				// finder(p�� right child, k)�� ��ȯ, ��� ȣ��
			else
			{
				insType = true;				// left child �Ǵ� right child�� ����ִ� ��� �� ����ִ� Node�� ���� �����ϴ� ��츦 ǥ��
				return p;				// p�� ��ȯ
			}
		}
		else
			return p;				// p�� ��ȯ
	}
	NodePtr finder(const NodePtr p, const Object& k, int& lt, int& rt)				// finder�Լ� �����ε�, ���� �Լ��� Ư�� element�� leftȽ���� right Ƚ���� ���ϴ� ��� �߰�
	{
		insType = false;
		if (isExternal(p))
			return p;
		Object curKey = p->element;
		if (k < curKey)
		{
			if (p->left != NULL)
			{
				lt++;				// left�ѹ� ����
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
				rt++;				// right�ѹ� ����
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
	NodePtr inserter(const Object& k)				// inserter�Լ�, �Ű������� Object reference�� const ���·� ����, ��ȯ�� NodePtr
	{
		NodePtr p = finder(ROOT, k);				// NodePtr�� ������ element k�� root���� ã�Ƽ� ����
		if (!insType)				// insType�� false�� ���
			while (leftChild(p) != NULL)				// p�� left child�� NULL�� �ƴ� ��� �ݺ�
				p = finder(leftChild(p), k);				// p�� k�� p�� left child���� ã�Ƽ� ����
		expandExternal(p, k);				// Node�� �����ϴ� expandExternal �Լ� ȣ��
		return p;				// p�� ��ȯ, p�� ������ Node�� parent
	}
	NodePtr remover(const NodePtr r)				// remover�Լ�, �Ű������� NodePtr�� const ���·� ����, ��ȯ�� NodePtr
	{
		NodePtr p = r;				// NodePtr�� ������ r�� ����
		if (isExternal(p))				// p�� left child�� right child�� ��� NULL�� ���
			return removeExternal(p);				// left child�� right child�� ��� NULL�� Node�� �����ϴ� removeExternal�Լ� ȣ��
		if (leftChild(p) == NULL)				// p�� left child�� NULL�� ���
			return removeAboveExternal(p, p->right);				// left child�� right child�� ��� NULL�� Node�� parent Node�� ����, child�� �Ѹ��� NULL
		else if (rightChild(p) == NULL)				// p�� right child�� NULL�� ���
			return removeAboveExternal(p, p->left);				// left child�� right child�� ��� NULL�� Node�� parent Node�� ����, child�� �Ѹ��� NULL
		else
		{
			p = leftChild(r);				// r�� left child�� p�� ����
			while (p->right != NULL)				// p�� right child�� NULL�� �ƴ� ��� �ݺ�
				p = rightChild(p);				// p�� p�� right child�� ����
			r->element = p->element;				// r�� element�� p�� element�� ����, inorder ������ �ٷ� ���� element�� ��ȯ
			remover(p);				// Node�� �����ϴ� remover�Լ� ȣ��
		}
	}
public:				// public ���� ������
	static int count;				// static int�� ���� count
	NodePtr find(const Object& k)				// find�Լ�, �Ű������� Object reference�� const������ ����, ��ȯ�� NodePtr
	{
		NodePtr p = finder(ROOT, k);				// NodePtr�� ������ element k�� root���� ã�Ƽ� ����
		if (isInternal(p) && k == p->element)				// left child�� right child�� ��� NULL�� �ƴϰ� Node, k�� p�� element�� ��ġ�Ҷ�
			return p;				// p�� ��ȯ
		else if (k == p->element)				// left child�� right child�� ��� NULL�̰� k�� p�� element�� ��ġ�Ҷ�
			return p;				// p�� ��ȯ
		else
			return NULL;				// NULL�� ��ȯ
	}
	NodePtr find(const Object& k, int& lt, int& rt)				// find�Լ� �����ε�, ���� �Լ��� Ư�� element�� leftȽ���� right Ƚ���� ���ϴ� ��� �߰�
	{
		NodePtr p = finder(ROOT, k, lt, rt);
		if (isInternal(p) && k == p->element)
			return p;
		else if (k == p->element)
			return p;
		else
			return NULL;
	}
	void insert(const Object& k)				// insert�Լ�, �Ű������� Object reference�� const������ ����
	{
		inserter(k);				// inserter�Լ��� ȣ��
	}
	void remove(const Object& k) throw(NonexistentElementException)				// romove�Լ�, �Ű������� Object reference�� const������ ����, NonexistentElementException�� ���ܷ� �����ٴ� ���� �˷���
	{
		NodePtr p = find(k);				// NodePtr�� ������ element k�� ã�Ƽ� ����
		if (p == NULL)				// p�� NULL�� ���
			throw NonexistentElementException("Remove nonexistent element!");				// NonexistentElementException���ܸ� ����
		remover(p);				// remover�Լ��� ȣ��
	}
	NodePtr root() const				// root�Լ�, ��ȯ�� NodePtr
	{
		return ROOT;				// ROOT�� ��ȯ
	}
	NodePtr leftChild(NodePtr v) const				// leftChild�Լ�, �Ű������� NodePtr�� ����, ��ȯ�� NodePtr, const ��� �Լ�
	{
		return v->left;				// v�� left child�� ��ȯ
	}
	NodePtr rightChild(NodePtr v) const				// rightChild�Լ�, �Ű������� NodePtr�� ����, ��ȯ�� NodePtr, const ��� �Լ�
	{
		return v->right;				// v�� right child�� ��ȯ
	}
	bool isExternal(NodePtr n) const				// isExternal�Լ�, �Ű������� NodePtr�� ����, ��ȯ�� bool, const ��� �Լ�
	{
		return (n->left == NULL && n->right == NULL);				// left child�� right child�� ��� NULL�� ��� true�� ��ȯ
	}
	bool isInternal(NodePtr n) const				// isInternal�Լ�, �Ű������� NodePtr�� ����, ��ȯ�� bool, const ��� �Լ�
	{
		return !isExternal(n);				// isExternal�� not���� ��ȯ
	}
	bool isRoot(NodePtr n) const				// isRoot�Լ�, �Ű������� NodePtr�� ����, ��ȯ�� bool, const ��� �Լ�
	{
		return (n == ROOT);				// n==ROOT�� ��� true�� ��ȯ
	}
	void setRoot(NodePtr r)				// setRoot�Լ�, �Ű������� NodePtr�� ����
	{
		ROOT = r;				// ROOT�� r�� ����
		r->parent = NULL;				// r�� parent�� NULL�� ����
	}
	void replaceElement(NodePtr n, const Object& o)				// replaceElement�Լ�, �Ű������� NodePtr�� Object reference�� const������ ����
	{
		n->element = o;				// n�� element�� o�� ����
	}
	void swapElements(NodePtr n, NodePtr w)				// swapElement�Լ�, �Ű������� NodePtr 2���� ����
	{
		Object temp = w->element;				// Object�� ���� temp�� w�� element�� ����
		w->element = n->element;				// w�� element�� n�� element�� ����
		n->element = temp;				// n�� element�� temp�� ����
	}
	void expandExternal(NodePtr n, const Object& k)				// expandExternal�Լ�, �Ű������� NodePtr�� Object reference�� const������ ����
	{
		if (k > n->element)				// k�� n�� element���� ū ���
		{
			n->right = new Node<Object>;				// n�� right child�� Node<Object>�� �����Ҵ�
			n->right->parent = n;				// n�� right child�� parent�� n�� ����
			n->right->element = k;				// n�� right child�� element�� k�� ����
		}
		else
		{
			n->left = new Node<Object>;				// n�� left child�� Node<Object>�� �����Ҵ�
			n->left->parent = n;				// n�� left child�� parent�� n�� ����
			n->left->element = k;				// n�� left child�� element�� k�� ����
		}
		sz++;
	}
	NodePtr removeExternal(NodePtr n)				// removeExternal�Լ�, �Ű������� NodePtr�� ����
	{
		NodePtr p = n->parent;				// NodePtr�� ������ n�� parent�� ����
		if (p->right == n)				// p�� right child�� n�� ���
			p->right = NULL;				// p�� right child�� NULL�� ����
		else
			p->left = NULL;				// p�� left child�� NULL�� ����
		delete n;				// n�� ���� ����
		sz--;				// sz 1��ŭ ����
		return p;				// p�� ��ȯ
	}
	NodePtr removeAboveExternal(NodePtr n, NodePtr s)				// removeAboveExternal�Լ�, �Ű������� NodePtr 2���� ����
	{
		if (isRoot(n))				// n�� root�� ���
			setRoot(s);				// s�� root�� ����
		else
		{
			NodePtr g = n->parent;				// NodePtr�� ���� g�� n�� parnet�� ����
			if (n == g->left)				// n�� g�� left child�� ���
				g->left = s;				// g�� left child�� s�� ����
			else
				g->right = s;				// g�� right child�� s�� ����
			s->parent = g;				// s�� parent�� g�� ����
		}
		delete n;				// n�� ��������
		sz--;				// sz�� 1��ŭ ����
		return s;				// s�� ��ȯ
	}
	BinarySearchTree(Object elem)				// ������, �Ű������� Object�� ������ ����
	{
		ROOT = new Node<Object>;				// ROOT�� Node<Object>�� �����Ҵ�
		sz = 1;				// sz�� 1�� ����
		ROOT->element = elem;				// ROOT�� element�� elem�� ����
		insType = false;				// insType�� false�� ����
	}
	int size() const				// size�Լ�, const ��� �Լ�
	{
		return sz;				// sz�� ��ȯ
	}
	bool isEmpty() const				// isEmpty�Լ�, ��ȯ�� bool, const ����Լ�
	{
		return (sz == 0);				// sz�� 0�� ��� true�� ��ȯ
	}
	void preorder(NodePtr v)				// preorder�Լ�, �Ű������� NodePtr�� ����, ������ȯ
	{
		cout << v->element << " ";				// v�� element�� ���

		if (v->left!=NULL)				// v�� left child�� NULL�� �ƴ� ���
			preorder(leftChild(v));				// ���ȣ��
		if (v->right != NULL)				// v�� right child�� NULL�� �ƴ� ���
			preorder(rightChild(v));				// ���ȣ��
	}
	void postorder(NodePtr v)				// postorder�Լ�, �Ű������� NodePtr�� ����, ������ȯ
	{
		if (v->left != NULL)				// v�� left child�� NULL�� �ƴ� ���
			postorder(leftChild(v));				// ���ȣ��
		if (v->right != NULL)				// v�� right child�� NULL�� �ƴ� ���
			postorder(rightChild(v));				// ���ȣ��

		cout << v->element << " ";				// v�� element�� ���
	}
	void inorder(NodePtr v)				// inorder�Լ�, �Ű������� NodePtr�� ����, ������ȯ
	{
		if (v->left != NULL)					// v�� left child�� NULL�� �ƴ� ���
			inorder(leftChild(v));				// ���ȣ��

		cout << v->element << " ";				// v�� element�� ���

		if (v->right != NULL)				// ���ȣ��
			inorder(rightChild(v));				// v�� right child�� NULL�� �ƴ� ���
	}
	void ElemInorder(NodePtr v, Object* inElem)				// ElemInorder�Լ�, �Ű������� NodePtr���� Object pointer���� ����, inorder�Լ� ����
	{
		if (v->left != NULL)
			ElemInorder(leftChild(v), inElem);

		inElem[count++] = v->element;				// inElem[count]�� v�� element�� ����

		if (v->right != NULL)
			ElemInorder(rightChild(v), inElem);
	}
};

#endif