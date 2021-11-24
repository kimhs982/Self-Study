#include <iostream>
using std::cout;
using std::endl;

#include "DoublyLinkedList.h"

DLinkedList::DLinkedList()
{
	header = new DNode;				// header, 새로운 DNode 객체 동적할당
	trailer = new DNode;				// trailer, 새로운 DNode 객체 동적할당
	header->next = trailer;				// 초기 상태, header와 trailer를 서로 연결
	trailer->prev = header;				// 초기 상태, header와 trailer를 서로 연결
}

DLinkedList::~DLinkedList()
{
	while (!empty()) removeFront();				// DLinkedList가 empty상태가 될때까지 removeFront()를 반복
	delete header;				// header의 메모리 공간 해제
	delete trailer;				// trailer의 메모리 공간 해제
}

bool DLinkedList::empty() const
{
	return (header->next == trailer);				// header->next == trailer이면 1을 반환, header->next != trailer이면 0을 반환
}

const Elem& DLinkedList::front() const
{
	return (header->next->elem);				// header->next DNode 객체의 데이터를 반환
}

const Elem& DLinkedList::back() const
{
	return (trailer->prev->elem);				// trailer->prev Dnode 객체의 데이터를 반환
}

void DLinkedList::printAll() const
{
	DNode* temp = header->next;				// 임시 DNode객체 포인터 temp, header->next DNode 객체를 가리킴
	while (temp != trailer)				// temp != trailer이기 전까지 반복
	{
		cout << temp->elem << " ";				// temp가 가리키는 DNode 객체의 데이터 출력
		temp = temp->next;				// temp가 temp->next DNode 객체를 가리키게 됨
	}
	cout << endl;
}

void DLinkedList::add(DNode* v, const Elem& e)
{
	DNode* u = new DNode;				// 새로운 DNode 동적할당
	u->elem = e;				// 새로운 DNode에 데이터 입력
	u->next = v;				// 새로운 DNode에 v DNode를 next로 연결
	u->prev = v->prev;				// 새로운 DNode에 v->prev를 연결
	v->prev->next = u;				// v->prev->next에 새로운 DNode를 연결
	v->prev = u;				// v->prev가 새로운 DNode가 됨
}

void DLinkedList::addFront(const Elem& e)
{
	add(header->next, e);				// v = header->next, 데이터(e)
}

void DLinkedList::addBack(const Elem& e)
{
	add(trailer, e);				// v = trailer, 데이터(e)
}

void DLinkedList::remove(DNode* v)
{
	DNode* u = v->prev;				// v->prev를 u라 함
	DNode* w = v->next;				// v->next를 v라 함
	u->next = w;				// v 앞 뒤 DNode끼리 서로 연결, u->next를 w라 함
	w->prev = u;				// v 앞 뒤 DNode끼리 서로 연결, v->prev를 u라 함
	delete v;				// v DNode 삭제
}

void DLinkedList::removeFront()
{
	remove(header->next);				// v = header->next
}

void DLinkedList::removeBack()
{
	remove(trailer->prev);				// v = trailer->prev
}