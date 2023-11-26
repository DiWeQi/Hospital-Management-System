#pragma once
#include <string>
//用于返程序和功能执行信息

class ErrorHandle
{
public:
	ErrorHandle(); //默认构造函数表示按预期执行
	ErrorHandle(std::string _errorInfo); //表示有错误，需要用错误信息进行初始化
	std::string getErrorInfo(); //获得相关信息
	bool getError() { return hasError; } //判定是否有错误

private:
	std::string errorInfo;
	bool hasError;
};

