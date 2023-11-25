#pragma once
#include <string>
#include <vector>

//检查是否只包含数字，后续可扩展检测是否为合法联系方式
bool checkContact(std::string contact);

//检查金钱数目是否合法，合法应该大于0
bool checkBalance(float balance);

//检查字符串是否不为空
bool checkSize(std::string str);

//检测str大小是否小于size，若大于则截去超出部分
std::string checkLimitSize(std::string str, int size);

bool checkFloat(std::string str);

//从一行以逗号分隔的数据，区分数据
std::vector<std::string> readOneLine(std::string dataStream, int numberOfData);

unsigned int generateRandom();

bool checkBasicInformation(std::string contact, std::string passworad, 
	std::string name, std::string code);

std::string fillStr(std::string str, int size);

std::string patientLine(std::string ID, std::string name, std::string contact, std::string unpaidFee);
std::string hospitalLine(std::string name, std::string contact, std::string location, std::string rank);
std::string departmentLine(std::string doctor, std::string contact, std::string description);