#include <iostream>
using std::cout;
using std::endl;

#include "Media.h"				// Media 클래스가 선언된 "Media.h"를 호출
#include "DVD.h"				// DVD 클래스가 선언된 "DVD.h"를 호출
#include "VTR.h"				// VTR 클래스가 선언된 "VTR.h"를 호출
#include "LegalDVD.h"				// LegalDVD 클래스가 선언된 "LegalDVD.h"를 호출

int main(void)
{
	Media* mp[4];				// Media 객체를 저장할 4개의 포인터 배열 mp[]

	mp[0] = new VTR("Hello", 15, "avi");				// Media 객체의 포인터 mp[0]에 VTR 객체를 new하여 주소 값 전달
	mp[1] = new DVD("Superman", 3, "123-9899");				// Media 객체의 포인터 mp[1]에 DVD 객체를 new하여 주소 값 전달
	mp[2] = new LegalDVD("Marvel", 10, "456-9899", "GG entertainment");				// Media 객체의 포인터 mp[2]에 LegalDVD 객체를 new하여 주소 값 전달
	mp[3] = new VTR("Disney", 23, "mkv");				// Media 객체의 포인터 mp[3]에 VTR 객체를 new하여 주소 값 전달

	for (int i = 0; i < Media::count; i++)				// 정수형 변수 i를 0으로 선언과 동시에 초기화하고, i의 값이 Media 객체의 public static data member인 count보다 작을때까지 i를 증가시키면서 for문을 반복
		mp[i]->play();				// 각각의 객체의 public 멤버 함수 play()를 실행

	cout << "연산자 오버로딩 실습" << endl;

	cout << mp[0];				// output stream operator <<를 오버로딩하여 mp[0]의 주소 값 대신 mp[0]->play()가 실행되게 함

	Media* temp = mp[3];				// Media 객체를 가리키는 임시 포인터 temp를 선언하여 Media 객체 포인터 mp[3]의 주소를 넘겨줌(이후에 mp[3]에 다른 Media 객체를 가리키는 주소 값이 대입되므로 mp[3]가 원래 가리키는 곳이 고아가 되지 않도록 해줌)

	mp[3] = *mp[1] + mp[2];				// +(더하기) 연산자를 오버로딩하여 Media 객체 *mp[1]에 Media 객체의 포인터 mp[2]를 더하여 주소 값을 반환하게 함, *mp[1]의 private data member인 length와 mp[2]의 private data member인 length가 서로 더해지도록 함
	cout << mp[3]->getLength() << endl;				// 윗 줄의 +(더하기) 연산자 오버로딩이 잘 실행되었는지 확인

	for (int j = 0; j < Media::count; j++)				// 정수형 변수 j를 0으로 선언과 동시에 초기화하고, j의 값이 Media 객체의 public static data member인 count보다 작을때까지 j를 증가시키면서 for문을 반복
		delete mp[j];				// new로 생성한 메모리 공간을 소멸시킴, +(더하기) 연산자 오버로딩에서 new로 생성된 Media 객체의 공간은 delete mp[3]에서 소멸됨
	delete temp;				// Media 객체의 포인터 mp[3]가 원래 자신이 가리키던 공간을 더이상 가리키지 않으므로 delete temp를 통해 따로 소멸시켜줌

	return 0;
}