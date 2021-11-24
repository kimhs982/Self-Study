#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "SortAlgorithm.h"

enum { INS, SEL, MER, QUI };				// 열거형(enumeration), INS(0), SEL(1), MER(2), QUI(3)을 의미함

int main()
{
	ArrayVector myKey;				// ArrayVector 클래스의 객체 myKey, 기본 생성자
	int size, method;				// int형 변수, size와 정렬 알고리즘을 선택
	cout << "Data Set의 크기를 입력하세요 : ";
	cin >> size;
	DataSet sortDataSet(myKey, size);				// DataSet 클래스의 객체 sortDataSet, 생성자에 myKey와 size를 인수로 넘겨줌

	cout << "Data Set의 key와 data값을 입력하세요" << endl;
	cout << "ex) DS[] : 1 a" << endl;				// 입력 방법 예시
	cin >> sortDataSet;				// 연산자 (>>) 오버로딩

	cout << "\n<<Unsorted Data Set>>" << endl;
	cout << sortDataSet;				// 연산자 (<<) 오버로딩

	cout << "\n\n(Insertion(0), Selection(1), Merge(2), Quick(3))\n"
		<< "정렬 알고리즘을 선택하세요 : ";
	cin >> method;				// 0, 1, 2, 3 중에 하나를 입력하여 정렬 알고리즘을 선택

	switch (method)				// switch문, method를 인자로 받음
	{
	case INS:				// method==INS(0)일 경우
		insertionSort(myKey.size(), sortDataSet);				// insertionSort
		cout << "\n<<Insertion Sort>>" << endl;
		cout << sortDataSet;				// 연산자 (<<) 오버로딩, 정렬 후 데이터의 상태를 출력
		break;
	case SEL:				// method==SEL(1)일 경우
		selectionSort(myKey.size(), sortDataSet);				// selectionSort
		cout << "\n<<Selection Sort>>" << endl;
		cout << sortDataSet;				// 연산자 (<<) 오버로딩, 정렬 후 데이터의 상태를 출력
		break;
	case MER:				// method==MER(2)일 경우
		mergeSort(myKey.size(), sortDataSet);				//mergeSort	
		cout << "\n<<Merge Sort>>" << endl;
		cout << sortDataSet;				// 연산자 (<<) 오버로딩, 정렬 후 데이터의 상태를 출력
		break;
	case QUI:				// method==QUI(3)일 경우
		inPlaceQuickSort(sortDataSet, 0, myKey.size() - 1);				// quickSort
		cout << "\n<<Quick Sort>>" << endl;
		cout << sortDataSet;				// 연산자 (<<) 오버로딩, 정렬 후 데이터의 상태를 출력
		break;
	default:				// method가 0, 1, 2, 3의 경우가 아닌 경우
		cout << "잘못된 접근입니다!" << endl;				// 에러 메세지 출력
	}

	return 0;				// main함수 종료
}