#ifndef NODE_H
#define NODE_H

template <typename Object>
struct Node				// Node structure(구조체), template 구조체
{
	Object element;				// element 값을 저장
	Node* parent;				// 포인터, 부모 Node를 가리킴
	Node* left;				// 포인터, left child Node를 가리킴
	Node* right;				// 포인터, right child Node를 가리킴
	Node() : element(Object())				// 기본생성자, element를 0으로 초기화
	{
		parent = left = right = NULL;				// 포인터 parent, left, right를 NULL로 초기화
	}
	Node* sibling() const				// sibling함수, 자매 Node를 반환, 반환형 Node 포인터
	{
		return (this == parent->left ? parent->right : parent->left);				// left child일 경우 right child를 반환하고 right child일 경우 left child를 반환
	}
};

#endif