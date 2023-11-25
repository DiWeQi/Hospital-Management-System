#pragma once
#include <string>
#include <vector>
#include "HospitalManagementSystem.h"
#include "PatientManagementSystem.h"
#include "UserManagementSystem.h"

class UI{
public:
	UI() {}
	ErrorHandle mainInterface();
	ErrorHandle patientInterface();
	ErrorHandle doctorInterface();

	void loginInterface(std::string& userName, std::string& password);
	void registerInterface(std::string& name, std::string& contact,std::string& userName, 
		std::string& password, std::string& code, std::string& secret, std::string& des);

	std::string patientListInterface(std::vector<std::vector<std::string>> patientList);
	void sendBill(std::string& ID, std::string& fee);
	void modifyDoctorInformation(std::string& newContact, std::string& newPassword, std::string& des);

	std::string hospitalListInterface(std::vector<std::vector<std::string>> hospitalList);
	std::string sortHospitalInterface();
	std::string commentListInterface();
	std::string departmentListInterface();
	void addEvaluateInterface(std::string& ID, std::string& comment);
	std::string makeAppointmentInterface();
	std::string chargeInterface();
	bool payInterface(float fee, float balance);
	void modifyUserInformation(std::string& newContext, std::string& index);

	void separateLine(int length);
};

