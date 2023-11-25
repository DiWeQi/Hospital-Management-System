#pragma once
#include <string>
#include <vector>
#include "HospitalManagementSystem.h"
#include "PatientManagementSystem.h"
#include "UserManagementSystem.h"

class UI{
public:
	UI() {}
	void loginInterface(std::string& userName, std::string& password);
	void registerInterface(std::string& name, std::string& contact,std::string& userName, 
		std::string& password, std::string& code, std::string& secret, std::string& des);

	std::string patientListInterface(std::vector<std::vector<std::string>> patientList);
	void sendBill(unsigned int& ID, float& fee);
	void modifyDoctorInformation(std::string& newContact, std::string& newPassword, std::string& des);

	std::string hospitalListInterface(std::vector<std::vector<std::string>> hospitalList);
	std::string sortHospitalInterface();
	unsigned int commentListInterface();
	unsigned int departmentListInterface();
	void addEvaluateInterface(unsigned int& ID, std::string& comment);
	unsigned int makeAppointmentInterface();
	float chargeInterface();
	bool payInterface(float fee, float balance);
	void modifyUserInformation(string& newContext, int& index);

	void separateLine(int length);
};

