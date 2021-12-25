#include <iostream>
using std::cout;
using std::endl;

#include "Media.h"				// �θ� Ŭ���� Media�� ������ �ִ� ��� ���� "Media.h"�� ����
#include "DVD.h"				// DVD Ŭ������ ������ �ִ� ��� ���� "DVD.h"�� ����

// binary scope resolution operator ::�� ���� DVD Ŭ������ ���� member���� �˷��ش�.

DVD::DVD(string inTitle, int inLength, string inLicense) : Media(inTitle, inLength)				// DVD Ŭ������ ������, parameter�� 2���� stirng�� int�� ����, member initializer�� ���� Media ��ü�� ������ ȣ��
{
	setLicense(inLicense);				// public ��� �Լ� setLicense()�� ���� data member�� license ����
}

void DVD::setLicense(string inLicense)				// public ��� �Լ� setLicense(), parameter�� string�� ����
{
	license = inLicense;				// private data member�� license�� string�� ���� inTitle�� ����
}

string DVD::getLicense() const				// public ��� �Լ� getLisence(), const ��� �Լ�
{
	return license;				// private data member�� license�� ��ȯ
}

void DVD::play() const				// public ��� �Լ�  play(), const ��� �Լ�
{
	cout << "DVD�� play�ǰ� �ֽ��ϴ�." << endl;				// "DVD�� play�ǰ� �ֽ��ϴ�"�� ���
}


DVD::~DVD()				// DVD Ŭ������ �Ҹ���, ��ü���� �Ҹ��ߴ��� Ȯ��
{
	cout << "(DVD) " << Media::getTitle() << "��(��) �Ҹ�Ǿ����ϴ�." << endl;				// "(DVD) title��(��) �Ҹ�Ǿ����ϴ�." ȣ��
}