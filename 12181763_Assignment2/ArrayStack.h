#pragma once
#include <string>
using std::string;

class RuntimeException				// RuntimeException class, 예외 처리 문장을 저장/출력
{
private:
	string errorMsg;				// private data member, string형
public:
	RuntimeException(const string& err)				// RuntimeException 클래스의 생성자, 매개변수를 string형의 변경할 수 없는 reference(참조자)로 받음
	{
		errorMsg = err;				// string형 data member errMsg에 참조자로 받아온 문자열 err을 저장
	}
	string getMessage() const				// get함수, const 멤버 함수
	{
		return errorMsg;				// private data member errorMsg에 저장된 값을 반환
	}
};

class StackEmptyException : public RuntimeException				// StackEmptyException클래스, 빈(empty) 상태일 때 예외 처리 문장을 받아 RuntimeException 클래스에 넘겨줌
{
public:
	StackEmptyException(const string& err) : RuntimeException(err) {}				// StackEmptyException 클래스의 기본 생성자, member initializer를 통하여 RuntimeException 생성자에 참조자로 받아온 문자열 err을 넘겨줌
};

class StackFullException : public RuntimeException				// StackFullException클래스, 모두 채워진(Full) 상태일 때 예외 처리 문장을 받아 RuntimeException 클래스에 넘겨줌
{
public:
	StackFullException(const string& err) : RuntimeException(err) {}				// StackFullException 클래스의 기본 생성자, member initializer를 통하여 RuntimeException 생성자에 참조자로 받아온 문자열 err을 넘겨줌
};

template <typename E>				// 클래스 template
class ArrayStack				// ArrayStack 클래스
{
	enum { DEF_CAPACITY = 10 };				// enum을 통해 DEF_CAPACITY라는 변수에 10값을 지정
public:				// public 접근 지정자
	ArrayStack(int cap = DEF_CAPACITY);				// ArrayStack의 기본 생성자, 매개변수형 int, default값 DEF_CAPACITY(==10)
	int size() const;				// Stack의 크기를 반환하는 함수,반환형 int, 매개변수형 void, const 맴버 함수
	bool empty() const;				// Stack이 빈 상태인지 확인하는 함수, 반환형 bool(0 또는 1), 매개변수형 void, const 맴버 함수
	const E& top() const throw(StackEmptyException);				// Stack의 맨 위 값을 확인하는 함수, 반환형 template E의 reference(참조자) & const, 매개변수형 void, const 맴버 함수, 예외 처리(StackEmptyException 객체 호출)
	void push(const E& e) throw(StackFullException);				// Stack에 값을 입력하는 함수, 반환형 void, 매개변수형 template E의 reference(참조자) & const, 예외 처리(StackFullException 객체 호출)
	void pop() throw(StackEmptyException);				// Stack의 값을 위부터 꺼내는 함수, 반환형 void, 매개변수형 void, 예외 처리 StackEmptyException 객체 호출
	~ArrayStack();				// ArrayStack의 소멸자
private:				// private 접근 지정자
	E* S;				// template E형 포인터 S
	int capacity;				// int형 변수 capacity
	int t;				// int형 변수 t
};

template <typename E> ArrayStack<E>::ArrayStack(int cap)				// ArrayStack의 생성자, int형 매개변수 cap
	: S(new E[cap]), capacity(cap), t(-1) { }				// member initializer로 data member들을 초기화, 몸체의 실행 부분이 빈 생성자

template <typename E> int ArrayStack<E>::size() const				// size함수, const 맴버 함수, 반환형 int
{
	return (t + 1);				// t+1값을 반환
}

template <typename E> bool ArrayStack<E>::empty() const				// empty함수, const 맴버 함수, 반환형 bool(0 또는 1)
{
	return (t < 0);				// private data member t가 0보다 작을 경우 1을 반환, t가 0보다 크거나 같을 경우 0을 반환
}

template <typename E>
const E& ArrayStack<E>::top() const throw(StackEmptyException)				// top함수, const 맴버함수, 반환형 template E, 예외 처리(StackEmptyException 객체 호출)
{
	if (empty())				// empty함수가 1을 반환한 경우 조건 만족
		throw StackEmptyException("Top of empty stack");				// 예외 처리(StackEmptyException 객체 호출, 문자열을 인수로 넘겨줌)
	return S[t];				// S[t]값 반환
}

template <typename E>
void ArrayStack<E>::push(const E& e) throw(StackFullException)				// push함수, template E형 매개변수, 예외 처리(StackFullException 객체 호출)
{
	if (size() == capacity)				// size함수가 반환한 값이 data member capacity와 같은 경우 조건 만족
		throw StackFullException("Push to full stack");				// 예외 처리(StackFullException 객체 호출, 문자열을 인수로 넘겨줌)
	S[++t] = e;				// t의 값을 1 증가시킨후 S[]에 매개변수로 받은 e값을 대입
}

template <typename E>
void ArrayStack<E>::pop() throw(StackEmptyException)				// pop함수, 예외 처리(StackEmptyException 객체 호출)
{
	if (empty())				// empty함수가 1을 반환한 경우 조건 만족
		throw StackEmptyException("Pop from empty stack");				// 예외 처리(StackEmptyException 객체 호출, 문자열을 인수로 넘겨줌)
	--t;				// t의 값 1 감소
}

template <typename E>
ArrayStack<E>::~ArrayStack()				// ArrayStack의 소멸자
{
	delete[] S;				// 포인터 S가 가리키는 동적할당된 배열 공간을 해제(delete)함
	S = NULL;				// 포인터 S가 가리키는 공간을 NULL값으로 초기화, 연결 해제
}

inline std::ostream& operator<<(std::ostream& out, const RuntimeException& e)				// 인라인 함수, output stream 연산자(<<) 오버로딩, cout << RuntimeException 객체; 형식으로 사용가능
{
	return out << e.getMessage();				// cout << 객체.getMessage()형태로 반환
}