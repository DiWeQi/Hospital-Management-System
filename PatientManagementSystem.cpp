#include <fstream>
#include <sstream>
#include <iomanip> 
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
	patientData << dataStream;
	patientData.close();
}

vector<vector<string>> PatientManagementSystem::getPatientList(unsigned int doctorID) {
	vector<vector<string>> patientList;
	for (Patient* patient : patients) {
		if(patient -> getBind() == doctorID)
			patientList.push_back(patient->getPatientInformation());
	}
	return patientList;
}

ErrorHandle PatientManagementSystem::sendBill(unsigned int patientID, float fee) {
	if (!checkBalance(fee)) return ErrorHandle("金额不能小于0");
	for (Patient* patient : patients) {
		if (patient->getPatientID() == patientID) {
			patient->modifyFee(fee);
			return ErrorHandle();
		}
	}
	return ErrorHandle("不存在该患者");
}