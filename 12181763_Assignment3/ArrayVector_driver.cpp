#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include "ArrayVector.h"

int main()
{
	ArrayVector myArrVec;				// ArrayVector 클래스의 객체 myArrVec 생성, 기본 생성자 호출
	cout << "현재 ArrayVector의 상태" << endl;				// myArrVec의 초기 상태
	cout << "Size : " << myArrVec.size() << endl;				// myArrVec의 size 출력
	cout << "Empty : " << (myArrVec.empty() ? "Yes" : "No") << endl;				// myArrVec의 empty여부 출력

	int numCount, inputNum;				// int형 변수
	cout << "\n삽입할 정수 개수 : ";
	cin >> numCount;
	for (int i = 0; i < numCount; i++)				// for반복문, i=0에서 numCount - 1까지 반복, i는 1씩 증가
	{
		cout << "A[" << i << "] = ";
		cin >> inputNum;
		myArrVec.insert(i, inputNum);				// insert()를 통해 0부터 numCount - 1까지 배열 공간을 생성하고, 정수형 변수 inputNum 데이터 입력
	}

	try {				// 예외처리 구간
		cout << "\nArrayVector에 입력된 값" << endl;
		for (int j = 0; j < numCount; j++)				// for반복문, j=0에서 numCount - 1까지 반복, j는 1씩 증가
			cout << myArrVec.at(j) << endl;				// at()을 통해 0부터 numCount -1까지 배열 데이터 출력
	}
	catch (const IndexOutOfBounds& ex1)				//  IndexoutOfBounds를 반환한 경우
	{
		ex1.printMsg();				// 에러 문구 출력
	}

	cout << "\n현재 ArrayVector의 상태" << endl;				// myArrVec의 상태
	cout << "Size : " << myArrVec.size() << endl;				// myArrVec의 size 출력
	cout << "Empty : " << (myArrVec.empty() ? "Yes" : "No") << endl;				// myArrVec의 empty여부 출력

	return 0;
}