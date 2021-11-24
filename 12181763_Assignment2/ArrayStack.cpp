#include <iostream>
#include "ArrayStack.h"

using namespace std;

int main(void)				// main함수
{
	ArrayStack <int> mystack;				// ArrayStack 객체 mystack, 자료형의 크기<int>

	try {				// 예외 처리 구간
		cout << mystack.size() << endl;				// mystack의 현재 size 출력

		mystack.push(1);				// mystack에 1을 push
		mystack.push(2);				// mystack에 2를 push

		cout << mystack.top() << endl;				// mtstack의 제일 윗 부분 값을 출력
		mystack.pop();				// mystack에서 제일 윗 부분을 pop

		cout << mystack.top() << endl;				// mtstack의 제일 윗 부분 값을 출력
		cout << mystack.size() << endl;				// mystack의 현재 size 출력
	}
	catch (const StackEmptyException& ex1)				// StackEmptyException을 throw한 경우 예외 처리
	{
		cout << ex1 << endl;				// 연산자(<<) 오버로딩, cout<<e.getMessage();로 변환
	}
	catch (const StackFullException& ex2)				// StackFullException을 throw한 경우 예외 처리
	{
		cout << ex2 << endl;				// 연산자(<<) 오버로딩, cout<<e.getMessage();로 변환
	}

	// 현재 mystack에는 1개의 값이 들어있음
	try {				// 예외 처리 구간
		for (int i = 0; i < 10; i++)				// 반복문 for, i가 0부터 9까지 1씩 증가하면서 10번 반복
		{
			mystack.push(i + 1);				// mystack에 i+1을 push
		}
	}
	catch (const StackEmptyException& ex1)				// StackEmptyException을 throw한 경우 예외 처리
	{
		cout << ex1 << endl;				// 연산자(<<) 오버로딩, cout<<e.getMessage();로 변환
	}
	catch (const StackFullException& ex2)				// StackFullException을 throw한 경우 예외 처리
	{
		cout << ex2 << endl;				// 연산자(<<) 오버로딩, cout<<e.getMessage();로 변환
	}

	try {				// 예외 처리 구간
		for (int j = 0; j < 11; j++)				// 반복문 for, j가 0부터 9까지 1씩 증가하면서 11번 반복
		{
			mystack.pop();				// mystack에서 제일 윗 부분을 pop
		}
	}
	catch (const StackEmptyException& ex1)				// StackEmptyException을 throw한 경우 예외 처리
	{
		cout << ex1 << endl;				// 연산자(<<) 오버로딩, cout<<e.getMessage();로 변환
	}
	catch (const StackFullException& ex2)				// StackFullException을 throw한 경우 예외 처리
	{
		cout << ex2 << endl;				// 연산자(<<) 오버로딩, cout<<e.getMessage();로 변환
	}

	return 0;				// main함수 종료
}