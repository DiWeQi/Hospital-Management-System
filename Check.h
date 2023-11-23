#pragma once
#include <string>

//检查是否只包含数字，后续可扩展检测是否为合法联系方式
bool checkContact(std::string contact);

//检查金钱数目是否合法，合法应该大于0
bool checkBalance(float balance);

//检查字符串是否不为空
bool checkSize(std::string str);

//检测str大小是否小于size，若大于则截去超出部分
std::string checkLimitSize(std::string str, int size);