#include "Check.h"
using namespace std;

bool checkContact(std::string contact) {
	for (int index = 0; index < contact.size(); index++) {
		if (!isdigit(contact[index])) return false;
	}
	return true;
}

bool checkBalance(float balance) {
	return balance > 0;
}

bool checkSize(std::string str) {
	return str.size() > 0;
}

string checkLimitSize(string str, int size) {
	if (str.size() > size) return str.substr(0, size);
	return str;
}