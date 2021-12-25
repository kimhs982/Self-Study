#include <iostream>
using std::cout;
using std::endl;

#include "Media.h"				// Media 클래스의 선언이 있는 헤더 파일 "Media.h"를 포함

// binary scope resolution operator ::을 통해 Media 클래스에 속한 member임을 알려준다.

int Media::count = 0;				// public static data member를 Media 클래스 외부에서 초기화

Media::Media(string inTitle, int inLength)				// Media 클래스의 생성자, parameter로 stirng과 int를 받음
{
	setTitle(inTitle);				// public 멤버 함수 setTitle()을 통해 data member인 title 설정
	setLength(inLength);				// public 멤버 함수 setLength()를 통해 data member인 length 설정
	count++;				// Media 클래스의 constructor가 호출될 때마다 public static data member인 count를 1씩 증가
}


void Media::setTitle(string inTittle)				// public 멤버 함수 setTitle(), parameter로 string을 받음
{
	title = inTittle;				// private data member인 title에 string형 변수 inTitle을 대입
}

void Media::setLength(int inLength)				// public 멤버 함수 setLength(), parameter로 int를 받음
{
	length = inLength;				// private data member인 length에 int형 변수 inLength를 대입
}

string Media::getTitle() const				// public 멤버 함수 getTitle(), const 멤버 함수
{
	return title;				// private data member인 title을 반환
}

int Media::getLength() const				// public 멤버 함수 getLength(), const 멤버 함수
{
	return length;				// private data member인 length를 반환
}

void Media::play() const				// public 멤버 함수  play(), const 멤버 함수
{
	cout << "Media가 play되고 있습니다." << endl;				// "Media가 play되고 있습니다"를 출력
}

ostream& operator<<(ostream& os, const Media* media_p)				// 헤더 파일 <iostream>의 output stream operator <<를 오버로딩, 전역 함수, parameter로 ostram을 reference(&) 형태로 받고, Media 객체의 주소 값을 받음
{
	media_p->play();				// Media 객체의 public 멤버 함수 play()를 호출
	return os;				// output stream operator가 자기 자신을 반환하여 reference(&) 형태로 반환함
}

Media* Media::operator+(const Media* media_p)				// +(더하기) 연산자 오버로딩, 멤버 함수, parameter로 Media 객체의 주소 값을 받음, 객체 + 객체의 주소를 받아 주소 값으로 반환
{
	Media* temp = new Media;				// Media 객체를 가리키는 임시 포인터 temp, 동적할당(new, heap에 공간 마련)->공간해제(delete)필요!
	count--;				// 임시 포인터로 Media 객체를 new 했으므로 constructor에 의해 실행된 count++;를 상쇄 시킴
	temp->setLength(getLength() + media_p->getLength());				// 임시 Media 객체 포인터 temp의 public 멤버 함수 setLength()를 통해 private data member인 length에 값을 대입

	return temp;				// heap 공간에 생성된 Media 객체의 주소 값을 반환, Media 객체 포인터 temp는 함수가 끝나면 소멸되지만, heap에 new를 통해 생성된 공간은 delete전에 소멸되지 않음
}

Media::~Media()				// Media 클래스의 소멸자, 객체들이 소멸했는지 확인
{
	cout << "(Media) " << getTitle() << "이(가) 소멸되었습니다." << endl;				// "(Media) title이(가) 소멸되었습니다." 호출
}