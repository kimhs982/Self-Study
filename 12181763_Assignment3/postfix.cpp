#include "ArrVecStack.h"

int PIS(const char&);				// PIS(priority in stack) �Լ� prototype, �Ű������� const char reference
int PIE(const char&);				// PIE(priority in expression) �Լ� prototype, �Ű������� const char reference

int main()
{
	int length;				// ���ڿ� ���� ����
	cout << "���� ǥ����� ���̸� �Է��ϼ��� : ";
	cin >> length;

	char* infixNotation = new char[length + 1];				// char ������ infixNotation�� length+1��ŭ char �迭 �����Ҵ�, '\0'�� �����ϱ� ���� 1�� �߰�
	cout << "���� ǥ����� �Է��ϼ��� : ";
	cin >> infixNotation;

	char* postfixNotation = new char[length + 1];				// char ������ postfixNotation�� length+1��ŭ char �迭 �����Ҵ�, '\0'�� �����ϱ� ���� 1�� �߰�
	ArrVecStack<char> myStack;				// ArrVecStackŬ������ ��ü myStack, Elem�� int�� �����Ͽ� ��ü ����(��ũ, ��Ʈ)
	char token;				// ���ڿ��� ���鼭 ���� �ϳ��� ������ ����
	int count = 0;				// postfixNotation�� ���ڸ� ������ ��ġ�� �����ϴ� ����

	try {				// ����ó�� ����
		for (int i = 0; i < length + 1; i++)				// for�ݺ���, i=0~i=lenght���� i�� 1�� ������Ű�� �ݺ�
		{
			token = infixNotation[i];				// infixNotation[i]�� ����� ���ڸ� token�� ����

			if ((token >= 65 && token <= 90) || (token >= 97 && token <= 122))				// �ƽ�Ű �ڵ�ǥ���� A~Z�� a~z������ ���� ��ȣ
			{
				postfixNotation[count] = token;				// postfixNotation[count]�� token�� ����
				count++;				// count�� 1��ŭ ������Ŵ
			}
			else if (token == ')')				// token�� ')'�� ���
			{
				while (myStack.top() != '(')				// myStack�� top�� '('�� �Ǳ� ������ �ݺ�
				{
					postfixNotation[count] = myStack.pop();				// postfixNotation[count]�� myStack���� pop�ؼ� ����
					count++;				// count�� 1��ŭ ������Ŵ
				}
				myStack.pop();				// myStack���� '('�� pop��Ű�� ���� �뵵
			}
			else if (token == '\0')				// token�� ���ڿ��� ������ �κ��� '\0'�� ����Ű�� ���
			{
				while (!(myStack.empty()))				// myStack�� empty�� �� ������ �ݺ�
				{
					postfixNotation[count] = myStack.pop();				// postfixNotation[count]�� myStack���� pop�ؼ� ����
					count++;				// count�� 1��ŭ ������Ŵ
				}
				postfixNotation[count] = '\0';				// postfixNotation[count]�� '\0'�� ����, ���ڿ��� ������ �κ�
			}
			else
			{
				switch (myStack.empty())				// myStack�� empty�� ���� �׷��� ���� ���
				{
				case 0:				// myStack�� empty�� �ƴ� ���
					if (!(myStack.empty()))				// myStack�� empty�� ��� myStack.top()�� ���ܸ� �߻���Ű�� ���� ����
					{
						while (PIS(myStack.top()) >= PIE(token))				// PIS(myStack�� top) >= PIE(token)�� �����ϴ� ��� �ݺ�
						{
							postfixNotation[count] = myStack.pop();				// postfixNotation[count]�� myStack���� pop�ؼ� ����
							count++;				// count�� 1��ŭ ������Ŵ
							if (myStack.empty())				// myStack�� empty�� ��� myStack.top()�� ���ܸ� �߻���Ű�� ���� ����
								break;
						}
					}
				case 1:				// myStack�� empty�� ���, empty�� �ƴ� ��쿡�� �����!
					myStack.push(token);				// myStack�� token�� push
				}
			}
		}
	}
	catch (const StackEmptyException& ex1)				// StackEmptyException�� ��ȯ�� ���
	{
		cout << ex1.getMessage() << endl;				// ���� ���� ���
	}

	cout << "���� ǥ��� : " << postfixNotation << endl;				// ��ȯ�� ���� ǥ��� ���

	delete[] infixNotation;				// infixNotation �޸� ���� ����
	delete[] postfixNotation;				// postfixNotation �޸� ���� ����

	return 0;
}

int PIS(const char& tokenIS)
{
	if (tokenIS == '(')				// Stack�� �ִ� ��� �켱 ������ ���� ����
		return 0;
	else if (tokenIS == '+' || tokenIS == '-')
		return 1;
	else if (tokenIS == '*' || tokenIS == '/')
		return 2;
	else if (tokenIS == '^')
		return 3;
	else
	{
		cout << "�߸��� ���Դϴ�! �ùٸ� �����ڸ� �Է��Ͻʽÿ�!" << endl;				// �߸��� �����ڰ� �Էµ� ���
		return -1;
	}
}

int PIE(const char& tokenIE)
{
	if (tokenIE == '(')				// ��(Expression)�� �ִ� ��� �켱 ������ ���� ����
		return 4;
	else if (tokenIE == '+' || tokenIE == '-')
		return 1;
	else if (tokenIE == '*' || tokenIE == '/')
		return 2;
	else if (tokenIE == '^')
		return 3;
	else
	{
		cout << "�߸��� ���Դϴ�! �ùٸ� �����ڸ� �Է��Ͻʽÿ�!" << endl;				// �߸��� �����ڰ� �Էµ� ���
		return -1;
	}
}