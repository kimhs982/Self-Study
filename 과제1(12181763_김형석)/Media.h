#ifndef MEDIA_H				// preprocessor wrapper을 통해 MEDIA_H가 두 번 이상 포함되는 것을 방지[다중 정의(multiple definition) 에러를 방지]
#define MEDIA_H

#include <string>
using std::string;

#include <iostream>
using std::ostream;				// output stream operator(<<)를 오버로딩에 사용하기 위해 <iostream>의 std::ostream을 ostream으로 사용하겠다고 선언

class Media
{
public:
	static int count;				// Media 클래스의 객체가 new를 통해 생성된 횟수를 계산하는 public static 데이터 멤버(같은 클래스의 모든 객체가 값을 공유)
	Media(string = "title", int = 0);				// Media class의 constructor, private data member를 초기화하기 위한 string과 int를 parameter로 받음, default argument 설정
	void setTitle(string);				// private data member인 title을 설정하는 함수
	void setLength(int);				// private data member인 length를 설정하는 함수
	int getLength() const;				// private data member인 length를 가져오는 함수, const 멤버 함수
	string getTitle() const;				// private data member인 title을 가져오는 함수, const 멤버 함수
	virtual void play() const;				// "Media가 play되고 있습니다."를 출력하는 함수, const 멤버 함수, virtual(가상) 함수
	friend ostream& operator<<(ostream&, const Media*);				// 연산자 오버로딩, 헤더 파일 <iostream>의 output stream operator << 재정의하여 reference(&)로 반환, 전역 함수(friend 선언)
	Media* operator+(const Media*);				// 연산자 오버로딩, +(더하기) 연산자를 객체와 객체의 주소를 더하여 주소로 반환하도록 재정의, 멤버 함수
	virtual ~Media();				// Media 클래스의 virtual(가상) destructor
private:
	string title;				// private data member, string type
	int length;				// private data member, int type
};

#endif