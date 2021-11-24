#include "ArrVecStack.h"

int PIS(const char&);				// PIS(priority in stack) 함수 prototype, 매개변수로 const char reference
int PIE(const char&);				// PIE(priority in expression) 함수 prototype, 매개변수로 const char reference

int main()
{
	int length;				// 문자열 길이 저장
	cout << "중위 표기식의 길이를 입력하세요 : ";
	cin >> length;

	char* infixNotation = new char[length + 1];				// char 포인터 infixNotation에 length+1만큼 char 배열 동적할당, '\0'을 저장하기 위해 1을 추가
	cout << "중위 표기식을 입력하세요 : ";
	cin >> infixNotation;

	char* postfixNotation = new char[length + 1];				// char 포인터 postfixNotation에 length+1만큼 char 배열 동적할당, '\0'을 저장하기 위해 1을 추가
	ArrVecStack<char> myStack;				// ArrVecStack클래스의 객체 myStack, Elem을 int로 간주하여 객체 생성(잉크, 힌트)
	char token;				// 문자열을 돌면서 문자 하나씩 저장할 변수
	int count = 0;				// postfixNotation에 문자를 저장할 위치를 저장하는 변수

	try {				// 예외처리 구간
		for (int i = 0; i < length + 1; i++)				// for반복문, i=0~i=lenght까지 i를 1씩 증가시키며 반복
		{
			token = infixNotation[i];				// infixNotation[i]에 저장된 문자를 token에 복사

			if ((token >= 65 && token <= 90) || (token >= 97 && token <= 122))				// 아스키 코드표에서 A~Z와 a~z까지의 문자 번호
			{
				postfixNotation[count] = token;				// postfixNotation[count]에 token을 복사
				count++;				// count를 1만큼 증가시킴
			}
			else if (token == ')')				// token이 ')'인 경우
			{
				while (myStack.top() != '(')				// myStack의 top이 '('이 되기 전까지 반복
				{
					postfixNotation[count] = myStack.pop();				// postfixNotation[count]에 myStack에서 pop해서 저장
					count++;				// count를 1만큼 증가시킴
				}
				myStack.pop();				// myStack에서 '('를 pop시키기 위한 용도
			}
			else if (token == '\0')				// token이 문자열의 마지막 부분인 '\0'을 가리키는 경우
			{
				while (!(myStack.empty()))				// myStack이 empty가 될 때까지 반복
				{
					postfixNotation[count] = myStack.pop();				// postfixNotation[count]에 myStack에서 pop해서 저장
					count++;				// count를 1만큼 증가시킴
				}
				postfixNotation[count] = '\0';				// postfixNotation[count]에 '\0'을 저장, 문자열의 마지막 부분
			}
			else
			{
				switch (myStack.empty())				// myStack이 empty인 경우와 그렇지 않은 경우
				{
				case 0:				// myStack이 empty가 아닌 경우
					if (!(myStack.empty()))				// myStack이 empty인 경우 myStack.top()이 예외를 발생시키는 것을 방지
					{
						while (PIS(myStack.top()) >= PIE(token))				// PIS(myStack의 top) >= PIE(token)를 만족하는 경우 반복
						{
							postfixNotation[count] = myStack.pop();				// postfixNotation[count]에 myStack에서 pop해서 저장
							count++;				// count를 1만큼 증가시킴
							if (myStack.empty())				// myStack이 empty인 경우 myStack.top()이 예외를 발생시키는 것을 방지
								break;
						}
					}
				case 1:				// myStack이 empty인 경우, empty가 아닌 경우에도 실행됨!
					myStack.push(token);				// myStack에 token을 push
				}
			}
		}
	}
	catch (const StackEmptyException& ex1)				// StackEmptyException을 반환한 경우
	{
		cout << ex1.getMessage() << endl;				// 에러 문구 출력
	}

	cout << "후위 표기식 : " << postfixNotation << endl;				// 변환된 후위 표기식 출력

	delete[] infixNotation;				// infixNotation 메모리 공간 해제
	delete[] postfixNotation;				// postfixNotation 메모리 공간 해제

	return 0;
}

int PIS(const char& tokenIS)
{
	if (tokenIS == '(')				// Stack에 있는 경우 우선 순위가 가장 낮음
		return 0;
	else if (tokenIS == '+' || tokenIS == '-')
		return 1;
	else if (tokenIS == '*' || tokenIS == '/')
		return 2;
	else if (tokenIS == '^')
		return 3;
	else
	{
		cout << "잘못된 식입니다! 올바른 연산자를 입력하십시오!" << endl;				// 잘못된 연산자가 입력된 경우
		return -1;
	}
}

int PIE(const char& tokenIE)
{
	if (tokenIE == '(')				// 식(Expression)에 있는 경우 우선 순위가 가장 높음
		return 4;
	else if (tokenIE == '+' || tokenIE == '-')
		return 1;
	else if (tokenIE == '*' || tokenIE == '/')
		return 2;
	else if (tokenIE == '^')
		return 3;
	else
	{
		cout << "잘못된 식입니다! 올바른 연산자를 입력하십시오!" << endl;				// 잘못된 연산자가 입력된 경우
		return -1;
	}
}