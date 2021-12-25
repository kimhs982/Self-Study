#include <iostream>
using std::cout;
using std::endl;

#include "DVD.h"				// �θ� Ŭ���� DVD�� ������ �ִ� ��� ���� "DVD.h"�� ����
#include "LegalDVD.h"				// LegalDVD Ŭ������ ������ �ִ� ��� ���� "LegalDVD.h"�� ����

// binary scope resolution operator ::�� ���� LegalDVD Ŭ������ ���� member���� �˷��ش�.

LegalDVD::LegalDVD(string inTitle, int inLength, string inLicense, string inCopyright) : DVD(inTitle, inLength, inLicense)			// LegalDVD Ŭ������ ������, parameter�� 3���� stirng�� int�� ����, member initializer�� ���� DVD ��ü�� ������ ȣ��	
{
	setCopyright(inCopyright);				// public ��� �Լ� setCopyright()�� ���� data member�� copyright ����
}

void LegalDVD::setCopyright(string inCopyright)				// public ��� �Լ� setCopyright(), parameter�� string�� ����
{
	copyright = inCopyright;				// private data member�� copyright�� string�� ���� inCopyright�� ����
}

string LegalDVD::getCopyright() const				// public ��� �Լ� getCopyright(), const ��� �Լ�
{
	return copyright;				// private data member�� copyright�� ��ȯ
}

void LegalDVD::play() const				// public ��� �Լ�  play(), const ��� �Լ�
{
	cout << "LegalDVD�� play�ǰ� �ֽ��ϴ�." << endl;				// "LegalDVD�� play�ǰ� �ֽ��ϴ�"�� ���
}

LegalDVD::~LegalDVD()				// LegalDVD Ŭ������ �Ҹ���, ��ü���� �Ҹ��ߴ��� Ȯ��
{
	cout << "(LegalDVD) " << Media::getTitle() << "��(��) �Ҹ�Ǿ����ϴ�." << endl;				// "(LegalDVD) title��(��) �Ҹ�Ǿ����ϴ�." ȣ��
}