#ifndef VTR_H				// preprocessor wrapper�� ���� VTR_H�� �� �� �̻� ���ԵǴ� ���� ����[���� ����(multiple definition) ������ ����]
#define VTR_H

#include "Media.h"				// �θ� Ŭ������ ����� ��� ���� "Media.h"�� ����

class VTR :public Media				// �θ� Ŭ����(Media)�� public ���·� ���
{
public:
	VTR(string = "title", int = 0, string = "format");				// VTR class�� constructor, private data member�� �ʱ�ȭ�ϱ� ���� �� ���� string�� int�� parameter�� ����, default argument ����
	void setFormat(string);				// private data member�� format�� �����ϴ� �Լ�
	string getFormat() const;				// private data member�� format�� �������� �Լ�
	void play() const;				// "VTR�� play�ǰ� �ֽ��ϴ�."�� ����ϴ� �Լ�, const ��� �Լ�, virtual(����) �Լ�[Media Ŭ������ ����]
	~VTR();				// VTR Ŭ������ virtual(����) destructor[Media Ŭ������ ����]
private:
	string format;				// private data member, string type
};

#endif