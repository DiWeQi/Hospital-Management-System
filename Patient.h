#pragma once 
#include <string>
#include <vector>
#include "ErrorHandle.h"

enum class patientIndex {
	name = 0,
	contact = 1,
	ID = 2,
	unpaidfee = 3,
	bind = 4
};

class Patient{
public:
	Patient(std::string _patientName, std::string _contact, unsigned int _patientID, float _fee, unsigned int _bind);
	std::vector<std::string> getPatientInformation();

	ErrorHandle modifyContact(std::string newContact);
	ErrorHandle modifyFee(float fee);

	std::string getPatientName() { return patientName; }
	std::string getContact() { return contact; }
	unsigned int getPatientID() { return patientID; }
	float getUnpaidFee() { return unpaidFee; }
	unsigned int getBind() { return bind; }

private:
	std::string patientName;
	std::string contact;
	unsigned int patientID;
	float unpaidFee;
	unsigned int bind;
};



