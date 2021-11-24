#include "ArrVecStack.h"

int main()
{
	ArrVecStack<int> myArrVecStack;				// ArrVecStack 클래스의 객체 myArrVecStack, Elem을 int로 간주하여 객체 생성(잉크, 힌트)
	bool done;
	int dayCount, h;

	cout << "주식 시세표의 일수를 입력하세요 : ";
	cin >> dayCount;
	int* stockPa = new int[dayCount];				// 주가를 저장하는 포인터 배열, dayCount만큼 int형 배열을 동적할당
	int* spanPa = new int[dayCount];				// Span을 저장하는 포인터 배역, dayCount만큰 int형 배열을 동적할당

	cout << "주식 시세표의 주가를 차례대로 입력하세요" << endl;
	for (int i = 0; i < dayCount; i++)				// for반복문, i=0~i=dayCount-1까지 i를 1씩 증가시키면서 반복
	{
		cout << i << "일 : ";
		cin >> stockPa[i];
	}

	try {				// 예외처리 구간
		for (int j = 0; j < dayCount; j++)				// for반복문, j=0~j=dayCount-1까자ㅣ j를 1씩 증가시키면서 반복
		{
			done = false;				// 일수가 넘어갈 때 마다 done을 false로 변경
			while (!(myArrVecStack.empty() || done))				// while반복문, myArrVecStack과 done이 모두 false인 경우
			{
				if (stockPa[myArrVecStack.top()] <= stockPa[j])				// stockPa[myArrVecStack의 top] <= stock[j]인 경우
					myArrVecStack.pop();				// myArrVecStack에서 pop
				else
					done = true;				// 그 이외의 경우 done을 true로 변경
			}

			if (myArrVecStack.empty())				// myArrVecStack이 empty인 경우
				h = -1;				// int형 변수 h를 1로 변경
			else
				h = myArrVecStack.top();				// 그 이외의 경우 h를 myArrVecStack의 top으로 변경

			spanPa[j] = j - h;				// spanPa[j]을 j-h로 변경
			myArrVecStack.push(j);				// myArrVecStack에 j를 push
		}
	}
	catch (const StackEmptyException& ex1)				// StackEmptyException을 반환한 경우
	{
		cout << ex1.getMessage() << endl;				// 에러 문구 출력
	}

	for (int k = 0; k < dayCount; k++)				// for반복문, k=0~k=dayCount-1까지 k를 1씩 증가시키면서 반복
		cout << k + 1 << "일차 주가 : " << stockPa[k] << ", Span : " << spanPa[k] << endl;				// 주가와 span 정보 출력

	delete[] stockPa;				// 주가를 저장하고 있는 stockPa의 메모리 해제
	delete[] spanPa;				// Span을 저장하고 있는 spanPa의 메모리 해제

	return 0;
}