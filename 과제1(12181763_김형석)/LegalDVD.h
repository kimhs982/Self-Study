#ifndef LEGALDVD_H				// preprocessor wrapper을 통해 LEGALDVD_H가 두 번 이상 포함되는 것을 방지[다중 정의(multiple definition) 에러를 방지]
#define LEGALDEV_H

#include "DVD.h"				// 부모 클래스가 선언된 헤더 파일 "DVD.h"를 포함

class LegalDVD :public DVD				// 부모 클래스(DVD)를 public 형태로 상속
{
public:
	LegalDVD(string = "title", int = 0, string = "license", string = "copyright");				// LeglaDVD class의 constructor, private data member를 초기화하기 위한 세 개의 string과 int를 parameter로 받음, default argument 설정
	void setCopyright(string);				// private data member인 copyright를 설정하는 함수
	string getCopyright() const;				// private data member인 copyright를 가져오는 함수
	void play() const;				// "LegalDVDrk play되고 있습니다."를 출력하는 함수, const 멤버 함수, virtual(가상) 함수[Media 클래스에 선언]
	~LegalDVD();				// LegalDVD 클래스의 virtual(가상) destructor[Media 클래스에 선언]
private:
	string copyright;				// private data member, string type
};

#endif