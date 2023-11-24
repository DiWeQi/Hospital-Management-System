#include <fstream>
#include <sstream>
#include <iomanip> 
#include "UserManagementSystem.h"
#include "Tool.h"
using namespace std;

UserManagementSystem::UserManagementSystem() {
	string dataStream;
	vector<string>info;
	ifstream userData;
	userData.open("UserData.txt");
	while (getline(userData, dataStream)) {
		info = readOneLine(dataStream, 6);
		User* user = new User((unsigned int)stoi(info[(int)userIndex::ID]), 
			(unsigned int)stoi(info[(int)userIndex::code]), info[(int)userIndex::name],
			info[(int)userIndex::password], (unsigned int)stoi(info[(int)userIndex::bind]), 
			stof(info[(int)userIndex::balance]));
		users.push_back(user);
	}
	userData.close();
}


void UserManagementSystem::updateInformation() {
	string dataStream = "";
	ofstream userData;
	userData.open("UserData.txt", ios::trunc);
	for (User* user: users) {
		ostringstream balance;
		balance << std::fixed << setprecision(2) << user -> getBalance();
		std::string str = balance.str();
		dataStream += to_string(user->getUserID()) + "," + to_string(user->getIdentityCode()) + ","
			+ user->getUserName() + "," + user->getPassword() + "," + to_string(user->getBindDoctor())
			+ "," + balance.str() + "\n";
	}
	userData << dataStream;
	userData.close();
}

unordered_map<string, string> UserManagementSystem::getUserList() {
	unordered_map<string, string> userList;
	for (User* user : users) {
		userList.insert({ user->getUserName(), user->getPassword() });
	}
	return userList;
}

ErrorHandle UserManagementSystem::userRegister(unsigned int indentityCode,
	string userName, string password, string _secretCode) {
	for (User* user : users) {
		if (userName == user->getUserName()) return ErrorHandle("该用户名已存在");
	}
	User* user = new User((unsigned int)users.size() + 1, indentityCode, userName, password, 0, 0);
	users.push_back(user);
	return ErrorHandle();
}