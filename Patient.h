#pragma once 
#include <string>
#include <vector>

enum class patientIndex {
	name = 0,
	contact = 1,
	ID = 2,
	fee = 3
};

class Patient{
public:
	Patient(std::string patientName, std::string contact, unsigned int patientID, float fee);
	std::vector<std::string> getPatientInformation();
	bool modifyContact(std::string newContact);
	bool modifyFee(float fee);

private:
	std::string patientName;
	std::string contact;
	unsigned int patientID;
	float unpaidFee;
};



