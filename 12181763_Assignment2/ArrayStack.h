#pragma once
#include <string>
using std::string;

class RuntimeException				// RuntimeException class, ���� ó�� ������ ����/���
{
private:
	string errorMsg;				// private data member, string��
public:
	RuntimeException(const string& err)				// RuntimeException Ŭ������ ������, �Ű������� string���� ������ �� ���� reference(������)�� ����
	{
		errorMsg = err;				// string�� data member errMsg�� �����ڷ� �޾ƿ� ���ڿ� err�� ����
	}
	string getMessage() const				// get�Լ�, const ��� �Լ�
	{
		return errorMsg;				// private data member errorMsg�� ����� ���� ��ȯ
	}
};

class StackEmptyException : public RuntimeException				// StackEmptyExceptionŬ����, ��(empty) ������ �� ���� ó�� ������ �޾� RuntimeException Ŭ������ �Ѱ���
{
public:
	StackEmptyException(const string& err) : RuntimeException(err) {}				// StackEmptyException Ŭ������ �⺻ ������, member initializer�� ���Ͽ� RuntimeException �����ڿ� �����ڷ� �޾ƿ� ���ڿ� err�� �Ѱ���
};

class StackFullException : public RuntimeException				// StackFullExceptionŬ����, ��� ä����(Full) ������ �� ���� ó�� ������ �޾� RuntimeException Ŭ������ �Ѱ���
{
public:
	StackFullException(const string& err) : RuntimeException(err) {}				// StackFullException Ŭ������ �⺻ ������, member initializer�� ���Ͽ� RuntimeException �����ڿ� �����ڷ� �޾ƿ� ���ڿ� err�� �Ѱ���
};

template <typename E>				// Ŭ���� template
class ArrayStack				// ArrayStack Ŭ����
{
	enum { DEF_CAPACITY = 10 };				// enum�� ���� DEF_CAPACITY��� ������ 10���� ����
public:				// public ���� ������
	ArrayStack(int cap = DEF_CAPACITY);				// ArrayStack�� �⺻ ������, �Ű������� int, default�� DEF_CAPACITY(==10)
	int size() const;				// Stack�� ũ�⸦ ��ȯ�ϴ� �Լ�,��ȯ�� int, �Ű������� void, const �ɹ� �Լ�
	bool empty() const;				// Stack�� �� �������� Ȯ���ϴ� �Լ�, ��ȯ�� bool(0 �Ǵ� 1), �Ű������� void, const �ɹ� �Լ�
	const E& top() const throw(StackEmptyException);				// Stack�� �� �� ���� Ȯ���ϴ� �Լ�, ��ȯ�� template E�� reference(������) & const, �Ű������� void, const �ɹ� �Լ�, ���� ó��(StackEmptyException ��ü ȣ��)
	void push(const E& e) throw(StackFullException);				// Stack�� ���� �Է��ϴ� �Լ�, ��ȯ�� void, �Ű������� template E�� reference(������) & const, ���� ó��(StackFullException ��ü ȣ��)
	void pop() throw(StackEmptyException);				// Stack�� ���� ������ ������ �Լ�, ��ȯ�� void, �Ű������� void, ���� ó�� StackEmptyException ��ü ȣ��
	~ArrayStack();				// ArrayStack�� �Ҹ���
private:				// private ���� ������
	E* S;				// template E�� ������ S
	int capacity;				// int�� ���� capacity
	int t;				// int�� ���� t
};

template <typename E> ArrayStack<E>::ArrayStack(int cap)				// ArrayStack�� ������, int�� �Ű����� cap
	: S(new E[cap]), capacity(cap), t(-1) { }				// member initializer�� data member���� �ʱ�ȭ, ��ü�� ���� �κ��� �� ������

template <typename E> int ArrayStack<E>::size() const				// size�Լ�, const �ɹ� �Լ�, ��ȯ�� int
{
	return (t + 1);				// t+1���� ��ȯ
}

template <typename E> bool ArrayStack<E>::empty() const				// empty�Լ�, const �ɹ� �Լ�, ��ȯ�� bool(0 �Ǵ� 1)
{
	return (t < 0);				// private data member t�� 0���� ���� ��� 1�� ��ȯ, t�� 0���� ũ�ų� ���� ��� 0�� ��ȯ
}

template <typename E>
const E& ArrayStack<E>::top() const throw(StackEmptyException)				// top�Լ�, const �ɹ��Լ�, ��ȯ�� template E, ���� ó��(StackEmptyException ��ü ȣ��)
{
	if (empty())				// empty�Լ��� 1�� ��ȯ�� ��� ���� ����
		throw StackEmptyException("Top of empty stack");				// ���� ó��(StackEmptyException ��ü ȣ��, ���ڿ��� �μ��� �Ѱ���)
	return S[t];				// S[t]�� ��ȯ
}

template <typename E>
void ArrayStack<E>::push(const E& e) throw(StackFullException)				// push�Լ�, template E�� �Ű�����, ���� ó��(StackFullException ��ü ȣ��)
{
	if (size() == capacity)				// size�Լ��� ��ȯ�� ���� data member capacity�� ���� ��� ���� ����
		throw StackFullException("Push to full stack");				// ���� ó��(StackFullException ��ü ȣ��, ���ڿ��� �μ��� �Ѱ���)
	S[++t] = e;				// t�� ���� 1 ������Ų�� S[]�� �Ű������� ���� e���� ����
}

template <typename E>
void ArrayStack<E>::pop() throw(StackEmptyException)				// pop�Լ�, ���� ó��(StackEmptyException ��ü ȣ��)
{
	if (empty())				// empty�Լ��� 1�� ��ȯ�� ��� ���� ����
		throw StackEmptyException("Pop from empty stack");				// ���� ó��(StackEmptyException ��ü ȣ��, ���ڿ��� �μ��� �Ѱ���)
	--t;				// t�� �� 1 ����
}

template <typename E>
ArrayStack<E>::~ArrayStack()				// ArrayStack�� �Ҹ���
{
	delete[] S;				// ������ S�� ����Ű�� �����Ҵ�� �迭 ������ ����(delete)��
	S = NULL;				// ������ S�� ����Ű�� ������ NULL������ �ʱ�ȭ, ���� ����
}

inline std::ostream& operator<<(std::ostream& out, const RuntimeException& e)				// �ζ��� �Լ�, output stream ������(<<) �����ε�, cout << RuntimeException ��ü; �������� ��밡��
{
	return out << e.getMessage();				// cout << ��ü.getMessage()���·� ��ȯ
}