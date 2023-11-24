#pragma once
#include <string>
class ErrorHandle
{
public:
	ErrorHandle();
	ErrorHandle(std::string _errorInfo);
	std::string getErrorInfo();
	bool getError() { return hasError; }

private:
	std::string errorInfo;
	bool hasError;
};

