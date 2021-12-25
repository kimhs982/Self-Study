#ifndef NODE_H
#define NODE_H

template <typename Object>
struct Node				// Node structure(����ü), template ����ü
{
	Object element;				// element ���� ����
	Node* parent;				// ������, �θ� Node�� ����Ŵ
	Node* left;				// ������, left child Node�� ����Ŵ
	Node* right;				// ������, right child Node�� ����Ŵ
	Node() : element(Object())				// �⺻������, element�� 0���� �ʱ�ȭ
	{
		parent = left = right = NULL;				// ������ parent, left, right�� NULL�� �ʱ�ȭ
	}
	Node* sibling() const				// sibling�Լ�, �ڸ� Node�� ��ȯ, ��ȯ�� Node ������
	{
		return (this == parent->left ? parent->right : parent->left);				// left child�� ��� right child�� ��ȯ�ϰ� right child�� ��� left child�� ��ȯ
	}
};

#endif