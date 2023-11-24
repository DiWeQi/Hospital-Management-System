#include <sstream>
#include <random>
#include "Tool.h"
#include "ErrorHandle.h"
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

vector<string> readOneLine(string dataStream, int numberOfData) {
	vector<string> data;
	for (int cnt = 0, index = 0; cnt < numberOfData; cnt++) {
		string temp = "";
		while (dataStream[index] != ',' && index < dataStream.size()) {
			temp += dataStream[index++];
		}
		data.push_back(temp);
		index++;
	}
	return data;
}

unsigned int generateRandom() {
	random_device random;
	mt19937 gen(random());
	uniform_int_distribution<> dis(100000, 999999);
	return dis(gen);
}