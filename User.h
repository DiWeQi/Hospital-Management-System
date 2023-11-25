#pragma once
#include <vector>
#include <string>
#include "Doctor.h"
#include "Patient.h"
#include "ErrorHandle.h"

enum class userIndex {
	ID = 0,
	code = 1,
	name = 2,
	password = 3,
	bind = 4,
	balance = 5
};

class User{
public:
	User(unsigned _userID, unsigned int _identityCode, std::string _userName,
		std::string _password, unsigned int _bindDoctor, float _balance);
	std::vector<std::string> getUserInformation();

	ErrorHandle modifyPassword(std::string newPassword);
	void modifyBlance(float _balance);

	unsigned int getUserID() { return userID; }
	unsigned int getIdentityCode() { return identityCode; }
	std::string getUserName() { return userName; }
	std::string getPassword() { return password; }
	unsigned int getBindDoctor() { return bindDoctor; }
	float getBalance() { return balance; }

private:
	unsigned userID;
	unsigned identityCode; //0为患者，1为医生
	std::string userName;
	std::string password;
	unsigned int bindDoctor; //患者登陆后可预约医生
	float balance;

	//绑定对应的患者信息和医生信息，若当前为医生身份，则Patient指针为空
	Doctor* identityBindingDoctor;
	Patient* identityBindingPatient;
};



