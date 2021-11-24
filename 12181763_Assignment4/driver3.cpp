#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <cstdlib>
using std::rand;
using std::srand;

#include <time.h>
using std::time;
using std::clock_t;

#include "SortAlgorithm.h"

enum { INS, SEL, MER, QUI };				// 열거형(enumeration), INS(0), SEL(1), MER(2), QUI(3)을 의미함

int main()
{
	ArrayVector myKey1, myKey2, myKey3, myKey4;				// ArrayVector 클래스의 객체 myKey, copyMyKey, 기본 생성자
	int size, value;				// int형 변수, size와 랜덤하게 생성한 값을 저장하는 value
	clock_t start, end;				// 시작 시각과 끝나는 시각을 저장하는 start, end

	srand(static_cast<unsigned int>(time(NULL)));

	cout << "Data Set의 크기를 입력하세요 : ";
	cin >> size;

	for (int i = 0; i < size; i++)				// for반복문, i=0부터 i=size-1까지 i를 1씩 증가시키면서 반복
	{
		value = rand() % size;
		myKey1.insert(i, value);				// ArrayVector의 객체 myKey에 입력받은 key값을 삽입
		myKey2.insert(i, value);				// ArrayVector의 객체 myKey에 입력받은 key값을 삽입
		myKey3.insert(i, value);				// ArrayVector의 객체 myKey에 입력받은 key값을 삽입
		myKey4.insert(i, value);				// ArrayVector의 객체 myKey에 입력받은 key값을 삽입
	}

	start = clock();				// 수행 시간 측정 시작
	insertionSort(myKey1.size(), myKey1);				// insertionSort
	end = clock();				// 수행 시간 측정 종료
	cout << "\n<<Insertion Sort>>" << endl;
	cout << "Insertion Sort 수행 시간 : " << (end - start) << "ms" << endl;				// Insertion Sort 수행 시간 출력
	cout << "Insertion Sort 수행 시간 : " << (static_cast<double>(end - start)) / CLOCKS_PER_SEC << "s" << endl;				// Insertion Sort 수행 시간 출력

	start = clock();				// 수행 시간 측정 시작
	selectionSort(myKey2.size(), myKey2);				// selectionSort
	end = clock();
	cout << "\n<<Selection Sort>>" << endl;
	cout << "Selection Sort 수행 시간 : " << (end - start) << "ms" << endl;				// Selection Sort 수행 시간 출력
	cout << "Selection Sort 수행 시간 : " << (static_cast<double>(end - start)) / CLOCKS_PER_SEC << "s" << endl;				// Selection Sort 수행 시간 출력

	start = clock();				// 수행 시간 측정 시작
	mergeSort(myKey3.size(), myKey3);				//mergeSort
	end = clock();				// 수행 시간 측정 종료
	cout << "\n<<Merge Sort>>" << endl;
	cout << "Merge Sort 수행 시간 : " << (end - start) << "ms" << endl;				// Merge Sort 수행 시간 출력
	cout << "Merge Sort 수행 시간 : " << (static_cast<double>(end - start)) / CLOCKS_PER_SEC << "s" << endl;				// Merge Sort 수행 시간 출력

	start = clock();				// 수행 시간 측정 시작
	inPlaceQuickSort(myKey4, 0, myKey4.size() - 1);				// quickSort
	end = clock();				// 수행 시간 측정 종료
	cout << "\n<<Quick Sort>>" << endl;
	cout << "Quick Sort 수행 시간 : " << (end - start) << "ms" << endl;				// Quick Sort 수행 시간 출력
	cout << "Quick Sort 수행 시간 : " << (static_cast<double>(end - start)) / CLOCKS_PER_SEC << "s" << endl;				// Quick Sort 수행 시간 출력

	return 0;				// main함수 종료
}