#pragma once
#include <string>
using std::string;

typedef int Elem;				// typedef로 Elem이라는 이름으로 int형 사용

class IndexOutOfBounds				// 예외처리
{
public:
	IndexOutOfBounds(const string&);				// 생성자, 매개변수로 const string reference, member initializer로 private 데이터 멤버 msg 초기화
	void printMsg() const;				// private 데이터 멤버 msg를 반환
private:
	string msg;				// private 데이터 멤버, string형
};

class DNode				// DNode 클래스
{
private:
	Elem elem;				// private 데이터 멤버, 데이터 저장
	DNode* prev;				// private 데이터 멤버, 이전 DNode 객체를 가리키는 포인터
	DNode* next;				// private 데이터 멤버, 이후 DNode 객체를 가리키는 포인터
	friend class DLinkedList;				// DLinkedList 클래스를 친구 선언
};

class DLinkedList				// DLinkedList 클래스
{
public:
	DLinkedList();				// 기본 생성자
	~DLinkedList();				// 소멸자
	bool empty() const;			// DLinkedList의 empty여부 반환	
	const Elem& front() const;				// DLinkedList의 맨 앞 DNode 객체의 데이터 반환, const 멤버함수
	const Elem& back() const;				// DLinkedList의 맨 뒤 DNode 객체의 데이터 반환, const 멤버함수
	void printAll() const;				// DLinkedList의 모든 DNode 객체의 데이터 출력
	void addFront(const Elem& e);				// DLinkedList의 맨 앞에 DNode 객체를 생성하여 header와 header->next와 연결
	void addBack(const Elem& e);				// DLinkedList의 맨 뒤에 DNode 객체를 생성하여 trailer와 trailer->next와 연결
	void removeFront();				// DLinkedList의 맨 앞에 DNode 객체를 제거
	void removeBack();				// DLinkedList의 맨 뒤에 DNode 객체를 제거
private:
	DNode* header;				// pivate 데이터 멤버,header, DNode 포인터 형
	DNode* trailer;				// pivate 데이터 멤버,trailer, DNode 포인터 형
protected:
	void add(DNode* v, const Elem& e);				// protected 멤버함수, addFront()와 addBack()의 기본
	void remove(DNode* v);				// protected 멤버함수, removeFront()와 removeBakc()의 기본
};