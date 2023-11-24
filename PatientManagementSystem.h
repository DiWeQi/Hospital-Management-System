#pragma once
#include "Patient.h"
#include "ErrorHandle.h"

class PatientManagementSystem{
public:
	PatientManagementSystem();
	void updateInformation();

	std::vector<std::vector<std::string>> getPatientList(unsigned int doctorID);
	ErrorHandle sendBill(unsigned int patientID, float fee);
private:
	std::vector<Patient*> patients;
};

