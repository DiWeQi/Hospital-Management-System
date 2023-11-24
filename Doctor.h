#pragma once
#include <string>
#include <vector>
#include "ErrorHandle.h"

enum class doctorIndex {
	name = 0,
	contact = 1,
	ID = 2,
	description = 3
};

class Doctor{
public:
	Doctor(std::string _doctorName, std::string _contact, 
		unsigned int _doctorID, std::string _description, std::string _secretCode);
	std::vector<std::string> getDoctorInformation();
	ErrorHandle modifyContact(std::string newContact);
	ErrorHandle modifyDescription(std::string newDescription);

private:
	std::string doctorName;
	std::string contact;
	unsigned int doctorID;
	std::string description;

	std::string secretCode; //用于医生用户注册时核对身份
};

