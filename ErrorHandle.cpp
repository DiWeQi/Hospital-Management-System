#include "ErrorHandle.h"
using namespace std;

ErrorHandle::ErrorHandle() {
	errorInfo = "�����ɹ�";
	hasError = false;
}

ErrorHandle::ErrorHandle(string _errorInfo) {
	errorInfo = _errorInfo;
	hasError = true;
}

string ErrorHandle::getErrorInfo() {
	return errorInfo;
}