#include <fstream>
#include <sstream>
#include <iomanip> 
#include <algorithm>
#include "PatientManagementSystem.h"
#include "Tool.h"
using namespace std;

PatientManagementSystem::PatientManagementSystem() {
	string dataStream;
	vector<string>info;
	ifstream patientData;
	patientData.open("PatientData.txt");
	while (getline(patientData, dataStream)) {
		info = readOneLine(dataStream, 5);
		Patient* patient = new Patient(info[(int)patientIndex::name],
			info[(int)patientIndex::contact], (unsigned int)stoi(info[(int)patientIndex::ID]),
			stof(info[(int)patientIndex::unpaidfee]), (unsigned int)stoi(info[(int)patientIndex::bind]));
		patients.push_back(patient);
	}
	patientData.close();
}

void PatientManagementSystem::updateInformation() {
	string dataStream = "";
	ofstream patientData;
	patientData.open("PatientData.txt", ios::trunc);
	for (Patient* patient : patients) {
		ostringstream unpaidFee;
		unpaidFee << std::fixed << setprecision(2) << patient->getUnpaidFee();
		dataStream += patient->getPatientName() + "," + patient -> getContact() + "," 
			+ to_string(patient->getPatientID()) + "," + unpaidFee.str() + "," 
			+ to_string(patient -> getBind()) + "\n";
	}
	dataStream = dataStream.substr(0, dataStream.size() - 1);
	patientData << dataStream;
	patientData.close();
}

vector<vector<string>> PatientManagementSystem::getPatientList(unsigned int doctorID) {
	vector<vector<string>> patientList;
	for (Patient* patient : patients) {
		if(patient -> getBind() == doctorID)patientList.push_back(patient->getPatientInformation());
	}
	return patientList;
}

Patient* PatientManagementSystem::getPatient(unsigned int ID) {
	for (Patient* patient : patients) {
		if (ID == patient->getPatientID()) return patient;
	}
	return NULL;
}

ErrorHandle PatientManagementSystem::sendBill(unsigned int doctorID, unsigned int patientID, float fee) {
	if (!checkBalance(fee)) return ErrorHandle("The amount cannot be less than 0");
	for (Patient* patient : patients) {
		if (patient->getPatientID() == patientID) {
			if (doctorID != patient->getBind()) {
				return ErrorHandle("You are not this patient's doctor");
			}
			patient->modifyFee(fee);
			return ErrorHandle();
		}
	}
	return ErrorHandle("The patient does not exist");
}

unsigned int PatientManagementSystem::patientRegister(std::string _patientName, std::string _contact) {
	patients.push_back(new Patient(_patientName, _contact, patients.size() + 1, 0, 0));
	sort(patients.begin(), patients.end(),
		[](Patient* a, Patient* b)->bool {return a->getPatientID() > b->getPatientID();});
	return patients[0]->getPatientID() + 1;
}