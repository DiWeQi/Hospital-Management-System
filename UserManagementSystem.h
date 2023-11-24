#pragma once
#include <unordered_map>
#include "User.h"
#include "ErrorHandle.h"

class UserManagementSystem{
public:
	UserManagementSystem();
	void updateInformation();

	std::unordered_map<std::string, std::string> getUserList();
	ErrorHandle userRegister(unsigned int indentityCode, std::string userName,
		std::string password, std::string _secretCode);
private:
	std::vector<User*> users;
};

