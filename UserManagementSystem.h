#pragma once
#include <unordered_map>
#include "User.h"
#include "ErrorHandle.h"

class UserManagementSystem{
public:
	UserManagementSystem();
	void updateInformation();

	std::unordered_map<std::string, std::string> getUserList();
	User* getUser(unsigned int ID);

	ErrorHandle userRegister(unsigned int indentityCode, std::string userName,
		std::string password, unsigned int ID);
	ErrorHandle userCheckName(std::string userName);
	User* userLogin(std::string userName, std::string password);
private:
	std::vector<User*> users;
};

