#ifndef MEDIA_H				// preprocessor wrapper�� ���� MEDIA_H�� �� �� �̻� ���ԵǴ� ���� ����[���� ����(multiple definition) ������ ����]
#define MEDIA_H

#include <string>
using std::string;

#include <iostream>
using std::ostream;				// output stream operator(<<)�� �����ε��� ����ϱ� ���� <iostream>�� std::ostream�� ostream���� ����ϰڴٰ� ����

class Media
{
public:
	static int count;				// Media Ŭ������ ��ü�� new�� ���� ������ Ƚ���� ����ϴ� public static ������ ���(���� Ŭ������ ��� ��ü�� ���� ����)
	Media(string = "title", int = 0);				// Media class�� constructor, private data member�� �ʱ�ȭ�ϱ� ���� string�� int�� parameter�� ����, default argument ����
	void setTitle(string);				// private data member�� title�� �����ϴ� �Լ�
	void setLength(int);				// private data member�� length�� �����ϴ� �Լ�
	int getLength() const;				// private data member�� length�� �������� �Լ�, const ��� �Լ�
	string getTitle() const;				// private data member�� title�� �������� �Լ�, const ��� �Լ�
	virtual void play() const;				// "Media�� play�ǰ� �ֽ��ϴ�."�� ����ϴ� �Լ�, const ��� �Լ�, virtual(����) �Լ�
	friend ostream& operator<<(ostream&, const Media*);				// ������ �����ε�, ��� ���� <iostream>�� output stream operator << �������Ͽ� reference(&)�� ��ȯ, ���� �Լ�(friend ����)
	Media* operator+(const Media*);				// ������ �����ε�, +(���ϱ�) �����ڸ� ��ü�� ��ü�� �ּҸ� ���Ͽ� �ּҷ� ��ȯ�ϵ��� ������, ��� �Լ�
	virtual ~Media();				// Media Ŭ������ virtual(����) destructor
private:
	string title;				// private data member, string type
	int length;				// private data member, int type
};

#endif