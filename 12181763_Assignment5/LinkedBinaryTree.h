//#include <iostream>
//using std::cout;
//using std::ostream;
//
//#include <string>
//using std::string;
//
//#ifndef LINKEDBINARYTREE_H
//#define LINKEDBINARYTREE_H
//
//#include "Node.h"
//
//class NonexistentElementException
//{
//private:
//	string errorMsg;
//public:
//	NonexistentElementException(const string& err)
//	{
//		errorMsg = err;
//	}
//	string getMessage() const
//	{
//		return errorMsg;
//	}
//};
//
//ostream& operator<<(ostream& output, const NonexistentElementException& e)
//{
//	output << e.getMessage();
//	return output;
//}
//
//template <typename Object>
//class BinarySearchTree
//{
//	typedef Node<Object>* NodePtr;
//private:
//	NodePtr ROOT;
//	int sz;
//	NodePtr finder(const NodePtr p, const Object& k)
//	{
//		if (isExternal(p))
//			return p;
//		Object curKey = p->element;
//		if (k < curKey)
//			return finder(leftChild(p), k);
//		else if (k > curKey)
//			return finder(rightChild(p), k);
//		else
//			return p;
//	}
//	NodePtr inserter(const Object& k)
//	{
//		NodePtr p = finder(ROOT, k);
//		while (isInternal(p))
//			p = finder(leftChild(p), k);
//		expandExternal(p, k);
//		return p;
//	}
//	NodePtr remover(const NodePtr r)
//	{
//		NodePtr p;
//		if (isExternal(leftChild(r)))
//			p = leftChild(r);
//		else if (isExternal(rightChild(r)))
//			p = rightChild(r);
//		else
//		{
//			p = leftChild(r);
//			do
//				p = rightChild(p);
//			while (isInternal(p));
//			r->element = p->element;
//		}
//		return removeAboveExternal(p);
//	}
//public:
//	NodePtr find(const Object& k)
//	{
//		NodePtr p = finder(ROOT, k);
//		if (isInternal(p))
//			return p;
//		else
//			return NULL;
//	}
//	void insert(const Object& k)
//	{
//		inserter(k);
//	}
//	void remove(const Object& k) throw(NonexistentElementException)
//	{
//		NodePtr p = finder(ROOT, k);
//		if (p == NULL)
//			throw NonexistentElementException("Remove nonexistent element!");
//		remover(p);
//	}
//	NodePtr root() const
//	{
//		return ROOT;
//	}
//	NodePtr leftChild(NodePtr v) const
//	{
//		return v->left;
//	}
//	NodePtr rightChild(NodePtr v) const
//	{
//		return v->right;
//	}
//	bool isExternal(NodePtr n) const
//	{
//		return (n->left == NULL && n->right == NULL);
//	}
//	bool isInternal(NodePtr n) const
//	{
//		return !isExternal(n);
//	}
//	bool isRoot(NodePtr n) const
//	{
//		return (n == ROOT);
//	}
//	void setRoot(NodePtr r)
//	{
//		ROOT = r;
//		r->parent = NULL;
//	}
//	void replaceElement(NodePtr n, const Object& o)
//	{
//		n->element = o;
//	}
//	void swapElements(NodePtr n, NodePtr w)
//	{
//		Object temp = w->element;
//		w->element = n->element;
//		n->element = temp;
//	}
//	void expandExternal(NodePtr n, const Object& k)
//	{
//		n->right = new Node<Object>;
//		n->left = new Node<Object>;
//		n->right->parent = n;
//		n->left->parent = n;
//		if (k > n->element)
//		{
//			n->right->element = k;
//
//		}
//		else
//		{
//			n->left->element = k;
//		}
//		sz += 2;
//	}
//	NodePtr removeAboveExternal(NodePtr n)
//	{
//		NodePtr p = n->parent;
//		NodePtr s = n->sibling();
//		if (isRoot(p))
//			setRoot(s);
//		else
//		{
//			NodePtr g = p->parent;
//			if (p == g->left)
//				g->left = s;
//			else
//				g->right = s;
//		}
//		delete n;
//		delete p;
//		sz -= 2;
//		return s;
//	}
//	BinarySearchTree(Object elem)
//	{
//		ROOT = new Node<Object>;
//		sz = 1;
//		ROOT->element = elem;
//	}
//	int size() const
//	{
//		return sz;
//	}
//	bool isEmpty() const
//	{
//		return (sz == 0);
//	}
//	void preorder(NodePtr v)
//	{
//		cout << v->element << " ";
//
//		if (isInternal(v))
//		{
//			preorder(leftChild(v));
//			preorder(rightChild(v));
//		}
//	}
//	void postorder(NodePtr v)
//	{
//		if (isInternal(v))
//		{
//			postorder(leftChild(v));
//			postorder(rightChild(v));
//		}
//
//		cout << v->element << " ";
//	}
//	void inorder(NodePtr v)
//	{
//		if (isInternal(v))
//			inorder(leftChild(v));
//
//		cout << v->element << " ";
//
//		if (isInternal(v))
//			inorder(rightChild(v));
//	}
//	void eulerTour(NodePtr v)
//	{
//		cout << v->element << " ";
//
//		if (isInternal(v))
//			eulerTour(leftChild(v));
//
//		cout << v->element << " ";
//
//		if (isInternal(v))
//			eulerTour(rightChild(v));
//
//		cout << v->element << " ";
//	}
//};
//
//#endif