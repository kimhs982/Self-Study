#ifndef DVD_H				// preprocessor wrapper�� ���� DVD_H�� �� �� �̻� ���ԵǴ� ���� ����[���� ����(multiple definition) ������ ����]
#define DVD_H

#include "Media.h"				// �θ� Ŭ������ ����� ��� ���� "Media.h"�� ����

class DVD :public Media				// �θ� Ŭ����(Media)�� public�� ���·� ��� ����
{
public:
	DVD(string = "title", int = 0, string = "license");				// DVD class�� constructor, private data member�� �ʱ�ȭ�ϱ� ���� �� ���� string�� int�� parameter�� ����, default argument ����
	void setLicense(string);				// private data member�� license�� �����ϴ� �Լ�
	string getLicense() const;				// private data member�� license�� �������� �Լ�, const ��� �Լ�
	void play() const;				// "DVD�� play�ǰ� �ֽ��ϴ�."�� ����ϴ� �Լ�, const ��� �Լ�, virtual(����) �Լ�[Media Ŭ������ ����]
	~DVD();				// DVD Ŭ������ virtual(����) destructor[Media Ŭ������ ����]
private:
	string license;				// private data member, string type
};

#endif