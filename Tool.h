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

//生成随机数
unsigned int generateRandom();

//检测基本信息是否合法
bool checkBasicInformation(std::string contact, std::string passworad, 
	std::string name, std::string code);

//用于辅助终端界面的输出的填补函数，返回填补size次str的string类型对象
std::string fillStr(std::string str, int size);

//制作患者信息列表一行输出的辅助函数，将信息按一定格式编制
std::string patientLine(std::string ID, std::string name, std::string contact, std::string unpaidFee);
//制作医院信息列表一行输出的辅助函数，将信息按一定格式编制
std::string hospitalLine(std::string name, std::string contact, std::string location, std::string rank);
//制作科室信息列表一行输出的辅助函数，将信息按一定格式编制
std::string departmentLine(std::string doctor, std::string contact, std::string description);