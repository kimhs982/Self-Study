#include <iostream>
using std::cout;
using std::endl;

#include "Media.h"				// Media Ŭ������ ����� "Media.h"�� ȣ��
#include "DVD.h"				// DVD Ŭ������ ����� "DVD.h"�� ȣ��
#include "VTR.h"				// VTR Ŭ������ ����� "VTR.h"�� ȣ��
#include "LegalDVD.h"				// LegalDVD Ŭ������ ����� "LegalDVD.h"�� ȣ��

int main(void)
{
	Media* mp[4];				// Media ��ü�� ������ 4���� ������ �迭 mp[]

	mp[0] = new VTR("Hello", 15, "avi");				// Media ��ü�� ������ mp[0]�� VTR ��ü�� new�Ͽ� �ּ� �� ����
	mp[1] = new DVD("Superman", 3, "123-9899");				// Media ��ü�� ������ mp[1]�� DVD ��ü�� new�Ͽ� �ּ� �� ����
	mp[2] = new LegalDVD("Marvel", 10, "456-9899", "GG entertainment");				// Media ��ü�� ������ mp[2]�� LegalDVD ��ü�� new�Ͽ� �ּ� �� ����
	mp[3] = new VTR("Disney", 23, "mkv");				// Media ��ü�� ������ mp[3]�� VTR ��ü�� new�Ͽ� �ּ� �� ����

	for (int i = 0; i < Media::count; i++)				// ������ ���� i�� 0���� ����� ���ÿ� �ʱ�ȭ�ϰ�, i�� ���� Media ��ü�� public static data member�� count���� ���������� i�� ������Ű�鼭 for���� �ݺ�
		mp[i]->play();				// ������ ��ü�� public ��� �Լ� play()�� ����

	cout << "������ �����ε� �ǽ�" << endl;

	cout << mp[0];				// output stream operator <<�� �����ε��Ͽ� mp[0]�� �ּ� �� ��� mp[0]->play()�� ����ǰ� ��

	Media* temp = mp[3];				// Media ��ü�� ����Ű�� �ӽ� ������ temp�� �����Ͽ� Media ��ü ������ mp[3]�� �ּҸ� �Ѱ���(���Ŀ� mp[3]�� �ٸ� Media ��ü�� ����Ű�� �ּ� ���� ���ԵǹǷ� mp[3]�� ���� ����Ű�� ���� ��ư� ���� �ʵ��� ����)

	mp[3] = *mp[1] + mp[2];				// +(���ϱ�) �����ڸ� �����ε��Ͽ� Media ��ü *mp[1]�� Media ��ü�� ������ mp[2]�� ���Ͽ� �ּ� ���� ��ȯ�ϰ� ��, *mp[1]�� private data member�� length�� mp[2]�� private data member�� length�� ���� ���������� ��
	cout << mp[3]->getLength() << endl;				// �� ���� +(���ϱ�) ������ �����ε��� �� ����Ǿ����� Ȯ��

	for (int j = 0; j < Media::count; j++)				// ������ ���� j�� 0���� ����� ���ÿ� �ʱ�ȭ�ϰ�, j�� ���� Media ��ü�� public static data member�� count���� ���������� j�� ������Ű�鼭 for���� �ݺ�
		delete mp[j];				// new�� ������ �޸� ������ �Ҹ��Ŵ, +(���ϱ�) ������ �����ε����� new�� ������ Media ��ü�� ������ delete mp[3]���� �Ҹ��
	delete temp;				// Media ��ü�� ������ mp[3]�� ���� �ڽ��� ����Ű�� ������ ���̻� ����Ű�� �����Ƿ� delete temp�� ���� ���� �Ҹ������

	return 0;
}