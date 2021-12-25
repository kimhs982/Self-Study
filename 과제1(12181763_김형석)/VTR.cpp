#include <iostream>
using std::cout;
using std::endl;

#include "Media.h"				// �θ� Ŭ���� Media�� ������ �ִ� ��� ���� "Media.h"�� ����
#include "VTR.h"				// VTR Ŭ������ ������ �ִ� ��� ���� "VTR.h"�� ����

// binary scope resolution operator ::�� ���� VTR Ŭ������ ���� member���� �˷��ش�.

VTR::VTR(string inTitle, int inLength, string inFormat) : Media(inTitle, inLength)				// VTR Ŭ������ ������, parameter�� 2���� stirng�� int�� ����, member initializer�� ���� Media ��ü�� ������ ȣ��
{
	setFormat(inFormat);				// public ��� �Լ� setFormat()�� ���� data member�� format ����
}

void VTR::setFormat(string inFormat)				// public ��� �Լ� setFormat(), parameter�� string�� ����
{
	format = inFormat;				// private data member�� format�� string�� ���� inFormat�� ����
}

string VTR::getFormat() const				// public ��� �Լ� getFormat(), const ��� �Լ�
{
	return format;				// private data member�� format�� ��ȯ
}

void VTR::play() const				// public ��� �Լ�  play(), const ��� �Լ�
{
	cout << "VTR�� play�ǰ� �ֽ��ϴ�." << endl;				// "VTR�� play�ǰ� �ֽ��ϴ�"�� ���
}

VTR::~VTR()				// VTR Ŭ������ �Ҹ���, ��ü���� �Ҹ��ߴ��� Ȯ��
{
	cout << "(VTR) " << Media::getTitle() << "��(��) �Ҹ�Ǿ����ϴ�." << endl;				// "(VTR) title��(��) �Ҹ�Ǿ����ϴ�." ȣ��
}