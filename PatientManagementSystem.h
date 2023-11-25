#pragma once
#include "Patient.h"
#include "ErrorHandle.h"

class PatientManagementSystem{
public:
	PatientManagementSystem();
	void updateInformation();

	std::vector<std::vector<std::string>> getPatientList(unsigned int doctorID);
	Patient* getPatient(unsigned int ID);
	ErrorHandle sendBill(unsigned int doctorID, unsigned int patientID, float fee);

	unsigned int patientRegister(std::string _patientName, std::string _contact);

private:
	std::vector<Patient*> patients;
};

