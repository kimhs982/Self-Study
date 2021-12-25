#ifndef VTR_H				// preprocessor wrapper을 통해 VTR_H가 두 번 이상 포함되는 것을 방지[다중 정의(multiple definition) 에러를 방지]
#define VTR_H

#include "Media.h"				// 부모 클래스가 선언된 헤더 파일 "Media.h"를 포함

class VTR :public Media				// 부모 클래스(Media)를 public 형태로 상속
{
public:
	VTR(string = "title", int = 0, string = "format");				// VTR class의 constructor, private data member를 초기화하기 위한 두 개의 string과 int를 parameter로 받음, default argument 설정
	void setFormat(string);				// private data member인 format을 설정하는 함수
	string getFormat() const;				// private data member인 format을 가져오는 함수
	void play() const;				// "VTR이 play되고 있습니다."를 출력하는 함수, const 멤버 함수, virtual(가상) 함수[Media 클래스에 선언]
	~VTR();				// VTR 클래스의 virtual(가상) destructor[Media 클래스에 선언]
private:
	string format;				// private data member, string type
};

#endif