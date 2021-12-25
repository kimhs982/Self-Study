#include <iostream>
using std::cout;
using std::endl;

#include "Media.h"				// 부모 클래스 Media의 선언이 있는 헤더 파일 "Media.h"를 포함
#include "VTR.h"				// VTR 클래스의 선언이 있는 헤더 파일 "VTR.h"를 포함

// binary scope resolution operator ::을 통해 VTR 클래스에 속한 member임을 알려준다.

VTR::VTR(string inTitle, int inLength, string inFormat) : Media(inTitle, inLength)				// VTR 클래스의 생성자, parameter로 2개의 stirng과 int를 받음, member initializer를 통해 Media 객체의 생성자 호출
{
	setFormat(inFormat);				// public 멤버 함수 setFormat()을 통해 data member인 format 설정
}

void VTR::setFormat(string inFormat)				// public 멤버 함수 setFormat(), parameter로 string을 받음
{
	format = inFormat;				// private data member인 format에 string형 변수 inFormat을 대입
}

string VTR::getFormat() const				// public 멤버 함수 getFormat(), const 멤버 함수
{
	return format;				// private data member인 format을 반환
}

void VTR::play() const				// public 멤버 함수  play(), const 멤버 함수
{
	cout << "VTR이 play되고 있습니다." << endl;				// "VTR이 play되고 있습니다"를 출력
}

VTR::~VTR()				// VTR 클래스의 소멸자, 객체들이 소멸했는지 확인
{
	cout << "(VTR) " << Media::getTitle() << "이(가) 소멸되었습니다." << endl;				// "(VTR) title이(가) 소멸되었습니다." 호출
}