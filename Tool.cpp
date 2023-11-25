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

bool checkFloat(std::string str) {
	int cnt = 0; //只能有一个小数点
	for (int index = 0; index < str.size(); index++) {
		if (str[index] == '.') {
			if (cnt || index == 0 || str.size() == 1) return false;
			cnt++;
			index++;
		}
		if (!isdigit(str[index])) return false;
	}
	return true;
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

bool checkBasicInformation(string contact, string passworad,
	string name, string code) {
	if (!checkContact(contact)) return false;
	if (!checkSize(passworad)) return false;
	if (!checkSize(name)) return false;
	if (stoi(code) != 0 && stoi(code) != 1) return false;
	return true;
}

string fillStr(string str, int size) {
	string fill = "";
	while (size > 0) {
		fill += str;
		size--;
	}
	return fill;
}

string patientLine(string ID, string name, string contact, string unpaidFee) {
	return "|" + ID + fillStr(" ", 4 - (int)ID.size()) +
		"|" + name + fillStr(" ", 14 - (int)name.size()) +
		"|" + contact + fillStr(" ", 14 - (int)contact.size()) +
		"|" + unpaidFee + fillStr(" ", 13 - (int)unpaidFee.size()) + "|\n";
}

string hospitalLine(string name, string contact, string location, string rank) {
	return "|" + name + fillStr(" ", 19 - (int)name.size()) +
		"|" + contact + fillStr(" ", 14 - (int)contact.size()) +
		"|" + location + fillStr(" ", 29 - (int)location.size()) +
		"|" + rank + fillStr(" ", 3 - (int)rank.size()) + "|\n";
}

string departmentLine(string doctor, string contact, string description) {
	return "|" + doctor + fillStr(" ", 14 - (int)doctor.size()) +
		"|" + contact + fillStr(" ", 14 - (int)contact.size()) +
		"|" + description + fillStr(" ", 88 - (int)description.size()) + "|\n";
}