#include <iostream>
using std::cout;
using std::endl;

#include "DoublyLinkedList.h"

DLinkedList::DLinkedList()
{
	header = new DNode;				// header, ���ο� DNode ��ü �����Ҵ�
	trailer = new DNode;				// trailer, ���ο� DNode ��ü �����Ҵ�
	header->next = trailer;				// �ʱ� ����, header�� trailer�� ���� ����
	trailer->prev = header;				// �ʱ� ����, header�� trailer�� ���� ����
}

DLinkedList::~DLinkedList()
{
	while (!empty()) removeFront();				// DLinkedList�� empty���°� �ɶ����� removeFront()�� �ݺ�
	delete header;				// header�� �޸� ���� ����
	delete trailer;				// trailer�� �޸� ���� ����
}

bool DLinkedList::empty() const
{
	return (header->next == trailer);				// header->next == trailer�̸� 1�� ��ȯ, header->next != trailer�̸� 0�� ��ȯ
}

const Elem& DLinkedList::front() const
{
	return (header->next->elem);				// header->next DNode ��ü�� �����͸� ��ȯ
}

const Elem& DLinkedList::back() const
{
	return (trailer->prev->elem);				// trailer->prev Dnode ��ü�� �����͸� ��ȯ
}

void DLinkedList::printAll() const
{
	DNode* temp = header->next;				// �ӽ� DNode��ü ������ temp, header->next DNode ��ü�� ����Ŵ
	while (temp != trailer)				// temp != trailer�̱� ������ �ݺ�
	{
		cout << temp->elem << " ";				// temp�� ����Ű�� DNode ��ü�� ������ ���
		temp = temp->next;				// temp�� temp->next DNode ��ü�� ����Ű�� ��
	}
	cout << endl;
}

void DLinkedList::add(DNode* v, const Elem& e)
{
	DNode* u = new DNode;				// ���ο� DNode �����Ҵ�
	u->elem = e;				// ���ο� DNode�� ������ �Է�
	u->next = v;				// ���ο� DNode�� v DNode�� next�� ����
	u->prev = v->prev;				// ���ο� DNode�� v->prev�� ����
	v->prev->next = u;				// v->prev->next�� ���ο� DNode�� ����
	v->prev = u;				// v->prev�� ���ο� DNode�� ��
}

void DLinkedList::addFront(const Elem& e)
{
	add(header->next, e);				// v = header->next, ������(e)
}

void DLinkedList::addBack(const Elem& e)
{
	add(trailer, e);				// v = trailer, ������(e)
}

void DLinkedList::remove(DNode* v)
{
	DNode* u = v->prev;				// v->prev�� u�� ��
	DNode* w = v->next;				// v->next�� v�� ��
	u->next = w;				// v �� �� DNode���� ���� ����, u->next�� w�� ��
	w->prev = u;				// v �� �� DNode���� ���� ����, v->prev�� u�� ��
	delete v;				// v DNode ����
}

void DLinkedList::removeFront()
{
	remove(header->next);				// v = header->next
}

void DLinkedList::removeBack()
{
	remove(trailer->prev);				// v = trailer->prev
}