#pragma once
#include <string>
using std::string;

typedef int Elem;				// typedef�� Elem�̶�� �̸����� int�� ���

class IndexOutOfBounds				// ����ó��
{
public:
	IndexOutOfBounds(const string&);				// ������, �Ű������� const string reference, member initializer�� private ������ ��� msg �ʱ�ȭ
	void printMsg() const;				// private ������ ��� msg�� ��ȯ
private:
	string msg;				// private ������ ���, string��
};

class DNode				// DNode Ŭ����
{
private:
	Elem elem;				// private ������ ���, ������ ����
	DNode* prev;				// private ������ ���, ���� DNode ��ü�� ����Ű�� ������
	DNode* next;				// private ������ ���, ���� DNode ��ü�� ����Ű�� ������
	friend class DLinkedList;				// DLinkedList Ŭ������ ģ�� ����
};

class DLinkedList				// DLinkedList Ŭ����
{
public:
	DLinkedList();				// �⺻ ������
	~DLinkedList();				// �Ҹ���
	bool empty() const;			// DLinkedList�� empty���� ��ȯ	
	const Elem& front() const;				// DLinkedList�� �� �� DNode ��ü�� ������ ��ȯ, const ����Լ�
	const Elem& back() const;				// DLinkedList�� �� �� DNode ��ü�� ������ ��ȯ, const ����Լ�
	void printAll() const;				// DLinkedList�� ��� DNode ��ü�� ������ ���
	void addFront(const Elem& e);				// DLinkedList�� �� �տ� DNode ��ü�� �����Ͽ� header�� header->next�� ����
	void addBack(const Elem& e);				// DLinkedList�� �� �ڿ� DNode ��ü�� �����Ͽ� trailer�� trailer->next�� ����
	void removeFront();				// DLinkedList�� �� �տ� DNode ��ü�� ����
	void removeBack();				// DLinkedList�� �� �ڿ� DNode ��ü�� ����
private:
	DNode* header;				// pivate ������ ���,header, DNode ������ ��
	DNode* trailer;				// pivate ������ ���,trailer, DNode ������ ��
protected:
	void add(DNode* v, const Elem& e);				// protected ����Լ�, addFront()�� addBack()�� �⺻
	void remove(DNode* v);				// protected ����Լ�, removeFront()�� removeBakc()�� �⺻
};