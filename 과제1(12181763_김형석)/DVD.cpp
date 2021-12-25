#include <iostream>
using std::cout;
using std::endl;

#include "Media.h"				// 부모 클래스 Media의 선언이 있는 헤더 파일 "Media.h"를 포함
#include "DVD.h"				// DVD 클래스의 선언이 있는 헤더 파일 "DVD.h"를 포함

// binary scope resolution operator ::을 통해 DVD 클래스에 속한 member임을 알려준다.

DVD::DVD(string inTitle, int inLength, string inLicense) : Media(inTitle, inLength)				// DVD 클래스의 생성자, parameter로 2개의 stirng과 int를 받음, member initializer를 통해 Media 객체의 생성자 호출
{
	setLicense(inLicense);				// public 멤버 함수 setLicense()을 통해 data member인 license 설정
}

void DVD::setLicense(string inLicense)				// public 멤버 함수 setLicense(), parameter로 string을 받음
{
	license = inLicense;				// private data member인 license에 string형 변수 inTitle을 대입
}

string DVD::getLicense() const				// public 멤버 함수 getLisence(), const 멤버 함수
{
	return license;				// private data member인 license를 반환
}

void DVD::play() const				// public 멤버 함수  play(), const 멤버 함수
{
	cout << "DVD가 play되고 있습니다." << endl;				// "DVD가 play되고 있습니다"를 출력
}


DVD::~DVD()				// DVD 클래스의 소멸자, 객체들이 소멸했는지 확인
{
	cout << "(DVD) " << Media::getTitle() << "이(가) 소멸되었습니다." << endl;				// "(DVD) title이(가) 소멸되었습니다." 호출
}