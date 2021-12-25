#include <iostream>
using std::cout;
using std::endl;

#include "DVD.h"				// 부모 클래스 DVD의 선언이 있는 헤더 파일 "DVD.h"를 포함
#include "LegalDVD.h"				// LegalDVD 클래스의 선언이 있는 헤더 파일 "LegalDVD.h"를 포함

// binary scope resolution operator ::을 통해 LegalDVD 클래스에 속한 member임을 알려준다.

LegalDVD::LegalDVD(string inTitle, int inLength, string inLicense, string inCopyright) : DVD(inTitle, inLength, inLicense)			// LegalDVD 클래스의 생성자, parameter로 3개의 stirng과 int를 받음, member initializer를 통해 DVD 객체의 생성자 호출	
{
	setCopyright(inCopyright);				// public 멤버 함수 setCopyright()를 통해 data member인 copyright 설정
}

void LegalDVD::setCopyright(string inCopyright)				// public 멤버 함수 setCopyright(), parameter로 string을 받음
{
	copyright = inCopyright;				// private data member인 copyright에 string형 변수 inCopyright를 대입
}

string LegalDVD::getCopyright() const				// public 멤버 함수 getCopyright(), const 멤버 함수
{
	return copyright;				// private data member인 copyright를 반환
}

void LegalDVD::play() const				// public 멤버 함수  play(), const 멤버 함수
{
	cout << "LegalDVD가 play되고 있습니다." << endl;				// "LegalDVD가 play되고 있습니다"를 출력
}

LegalDVD::~LegalDVD()				// LegalDVD 클래스의 소멸자, 객체들이 소멸했는지 확인
{
	cout << "(LegalDVD) " << Media::getTitle() << "이(가) 소멸되었습니다." << endl;				// "(LegalDVD) title이(가) 소멸되었습니다." 호출
}