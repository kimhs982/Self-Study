#include <iostream>
using std::cout;
using std::endl;

#include "Media.h"				// Media Ŭ������ ������ �ִ� ��� ���� "Media.h"�� ����

// binary scope resolution operator ::�� ���� Media Ŭ������ ���� member���� �˷��ش�.

int Media::count = 0;				// public static data member�� Media Ŭ���� �ܺο��� �ʱ�ȭ

Media::Media(string inTitle, int inLength)				// Media Ŭ������ ������, parameter�� stirng�� int�� ����
{
	setTitle(inTitle);				// public ��� �Լ� setTitle()�� ���� data member�� title ����
	setLength(inLength);				// public ��� �Լ� setLength()�� ���� data member�� length ����
	count++;				// Media Ŭ������ constructor�� ȣ��� ������ public static data member�� count�� 1�� ����
}


void Media::setTitle(string inTittle)				// public ��� �Լ� setTitle(), parameter�� string�� ����
{
	title = inTittle;				// private data member�� title�� string�� ���� inTitle�� ����
}

void Media::setLength(int inLength)				// public ��� �Լ� setLength(), parameter�� int�� ����
{
	length = inLength;				// private data member�� length�� int�� ���� inLength�� ����
}

string Media::getTitle() const				// public ��� �Լ� getTitle(), const ��� �Լ�
{
	return title;				// private data member�� title�� ��ȯ
}

int Media::getLength() const				// public ��� �Լ� getLength(), const ��� �Լ�
{
	return length;				// private data member�� length�� ��ȯ
}

void Media::play() const				// public ��� �Լ�  play(), const ��� �Լ�
{
	cout << "Media�� play�ǰ� �ֽ��ϴ�." << endl;				// "Media�� play�ǰ� �ֽ��ϴ�"�� ���
}

ostream& operator<<(ostream& os, const Media* media_p)				// ��� ���� <iostream>�� output stream operator <<�� �����ε�, ���� �Լ�, parameter�� ostram�� reference(&) ���·� �ް�, Media ��ü�� �ּ� ���� ����
{
	media_p->play();				// Media ��ü�� public ��� �Լ� play()�� ȣ��
	return os;				// output stream operator�� �ڱ� �ڽ��� ��ȯ�Ͽ� reference(&) ���·� ��ȯ��
}

Media* Media::operator+(const Media* media_p)				// +(���ϱ�) ������ �����ε�, ��� �Լ�, parameter�� Media ��ü�� �ּ� ���� ����, ��ü + ��ü�� �ּҸ� �޾� �ּ� ������ ��ȯ
{
	Media* temp = new Media;				// Media ��ü�� ����Ű�� �ӽ� ������ temp, �����Ҵ�(new, heap�� ���� ����)->��������(delete)�ʿ�!
	count--;				// �ӽ� �����ͷ� Media ��ü�� new �����Ƿ� constructor�� ���� ����� count++;�� ��� ��Ŵ
	temp->setLength(getLength() + media_p->getLength());				// �ӽ� Media ��ü ������ temp�� public ��� �Լ� setLength()�� ���� private data member�� length�� ���� ����

	return temp;				// heap ������ ������ Media ��ü�� �ּ� ���� ��ȯ, Media ��ü ������ temp�� �Լ��� ������ �Ҹ������, heap�� new�� ���� ������ ������ delete���� �Ҹ���� ����
}

Media::~Media()				// Media Ŭ������ �Ҹ���, ��ü���� �Ҹ��ߴ��� Ȯ��
{
	cout << "(Media) " << getTitle() << "��(��) �Ҹ�Ǿ����ϴ�." << endl;				// "(Media) title��(��) �Ҹ�Ǿ����ϴ�." ȣ��
}