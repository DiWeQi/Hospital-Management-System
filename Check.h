#pragma once
#include <string>

//����Ƿ�ֻ�������֣���������չ����Ƿ�Ϊ�Ϸ���ϵ��ʽ
bool checkContact(std::string contact);

//����Ǯ��Ŀ�Ƿ�Ϸ����Ϸ�Ӧ�ô���0
bool checkBalance(float balance);

//����ַ����Ƿ�Ϊ��
bool checkSize(std::string str);

//���str��С�Ƿ�С��size�����������ȥ��������
std::string checkLimitSize(std::string str, int size);