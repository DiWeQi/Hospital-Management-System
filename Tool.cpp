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
	while (size--) {
		fill += str;
	}
	return fill;
}

string patientLine(string ID, string name, string contact, string unpaidFee) {
	return "|" + ID + fillStr(" ", 4 - ID.size()) +
		"|" + name + fillStr(" ", 14 - name.size()) +
		"|" + contact + fillStr(" ", 14 - contact.size()) +
		"|" + unpaidFee + fillStr(" ", 13 - unpaidFee.size()) + "|\n";
}

string hospitalLine(string name, string contact, string location, string rank) {
	return "|" + name + fillStr(" ", 14 - name.size()) +
		"|" + contact + fillStr(" ", 14 - contact.size()) +
		"|" + location + fillStr(" ", 19 - location.size()) +
		"|" + rank + fillStr(" ", 3 - rank.size()) + "|\n";
}

string departmentLine(string doctor, string contact, string description) {
	return "|" + doctor + fillStr(" ", 14 - doctor.size()) +
		"|" + contact + fillStr(" ", 14 - contact.size()) +
		"|" + description + fillStr(" ", 88 - description.size()) + "|\n";
}