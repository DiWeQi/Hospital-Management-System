#pragma once
#include <string>
//���ڷ�����͹���ִ����Ϣ

class ErrorHandle
{
public:
	ErrorHandle(); //Ĭ�Ϲ��캯����ʾ��Ԥ��ִ��
	ErrorHandle(std::string _errorInfo); //��ʾ�д�����Ҫ�ô�����Ϣ���г�ʼ��
	std::string getErrorInfo(); //��������Ϣ
	bool getError() { return hasError; } //�ж��Ƿ��д���

private:
	std::string errorInfo;
	bool hasError;
};

