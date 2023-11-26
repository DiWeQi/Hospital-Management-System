#pragma once
#include <string>
#include <vector>

//����Ƿ�ֻ�������֣���������չ����Ƿ�Ϊ�Ϸ���ϵ��ʽ
bool checkContact(std::string contact);

//����Ǯ��Ŀ�Ƿ�Ϸ����Ϸ�Ӧ�ô���0
bool checkBalance(float balance);

//����ַ����Ƿ�Ϊ��
bool checkSize(std::string str);

//���str��С�Ƿ�С��size�����������ȥ��������
std::string checkLimitSize(std::string str, int size);

bool checkFloat(std::string str);

//��һ���Զ��ŷָ������ݣ���������
std::vector<std::string> readOneLine(std::string dataStream, int numberOfData);

//���������
unsigned int generateRandom();

//��������Ϣ�Ƿ�Ϸ�
bool checkBasicInformation(std::string contact, std::string passworad, 
	std::string name, std::string code);

//���ڸ����ն˽���������������������size��str��string���Ͷ���
std::string fillStr(std::string str, int size);

//����������Ϣ�б�һ������ĸ�������������Ϣ��һ����ʽ����
std::string patientLine(std::string ID, std::string name, std::string contact, std::string unpaidFee);
//����ҽԺ��Ϣ�б�һ������ĸ�������������Ϣ��һ����ʽ����
std::string hospitalLine(std::string name, std::string contact, std::string location, std::string rank);
//����������Ϣ�б�һ������ĸ�������������Ϣ��һ����ʽ����
std::string departmentLine(std::string doctor, std::string contact, std::string description);