#pragma once
#include <string>
#include <vector>

enum class doctorIndex {
	name = 0,
	contact = 1,
	ID = 2,
	description = 3
};

class Doctor{
public:
	Doctor(std::string _doctorName, std::string _contact, unsigned int _doctorID, std::string _description);
	std::vector<std::string> getDoctorInformation();
	bool modifyContact(std::string newContact);
	bool modifyDescription(std::string newDescription);

private:
	std::string doctorName;
	std::string contact;
	unsigned int doctorID;
	std::string description;
};

