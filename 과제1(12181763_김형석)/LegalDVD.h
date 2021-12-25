#ifndef LEGALDVD_H				// preprocessor wrapper�� ���� LEGALDVD_H�� �� �� �̻� ���ԵǴ� ���� ����[���� ����(multiple definition) ������ ����]
#define LEGALDEV_H

#include "DVD.h"				// �θ� Ŭ������ ����� ��� ���� "DVD.h"�� ����

class LegalDVD :public DVD				// �θ� Ŭ����(DVD)�� public ���·� ���
{
public:
	LegalDVD(string = "title", int = 0, string = "license", string = "copyright");				// LeglaDVD class�� constructor, private data member�� �ʱ�ȭ�ϱ� ���� �� ���� string�� int�� parameter�� ����, default argument ����
	void setCopyright(string);				// private data member�� copyright�� �����ϴ� �Լ�
	string getCopyright() const;				// private data member�� copyright�� �������� �Լ�
	void play() const;				// "LegalDVDrk play�ǰ� �ֽ��ϴ�."�� ����ϴ� �Լ�, const ��� �Լ�, virtual(����) �Լ�[Media Ŭ������ ����]
	~LegalDVD();				// LegalDVD Ŭ������ virtual(����) destructor[Media Ŭ������ ����]
private:
	string copyright;				// private data member, string type
};

#endif