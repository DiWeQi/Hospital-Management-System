#include <fstream>
#include <sstream>
#include <iomanip> 
#include "HospitalManagementSystem.h"
#include "Tool.h"
using namespace std;

HospitalManagementSystem::HospitalManagementSystem() {
	ifstream hospitalData;
	hospitalData.open("HospitalData.txt");
	while (!hospitalData.eof()) {
		hospitals.push_back(readHospital(hospitalData));
	}
	hospitalData.close();
}

Hospital* HospitalManagementSystem::readHospital(ifstream& hospitalData) {
	string dataStream;
	vector<string>info, comments;
	vector<Department*> departments;
	getline(hospitalData, dataStream);
	info = readOneLine(dataStream, 6);
	comments = readComments(hospitalData);
	departments = readDepartments(hospitalData);
	return new Hospital(info[(int)hospitalIndex::name], info[(int)hospitalIndex::location],
		info[(int)hospitalIndex::contact], (unsigned int)stoi(info[(int)hospitalIndex::ID]),
		stoi(info[(int)hospitalIndex::averageCost]), stof(info[(int)hospitalIndex::rank]),
		comments, departments);
}

vector<string> HospitalManagementSystem::readComments(ifstream& hospitalData) {
	string dataStream;
	vector<string> comments;
	do {
		getline(hospitalData, dataStream);
		if (dataStream == "commentend") break;
		comments.push_back(dataStream);
	} while (true);
	return comments;
}

vector<Department*> HospitalManagementSystem::readDepartments(ifstream& hospitalData) {
	string dataStream;
	vector<string>info;
	vector<Department*> departments;
	vector<Doctor*> doctors;
	do {
		getline(hospitalData, dataStream);
		if (dataStream == "departmentend") break;
		info = readOneLine(dataStream, 2);
		doctors = readDoctors(hospitalData);
		departments.push_back(new Department(info[(int)departmentIndex::name],
			(unsigned int)stoi(info[(int)departmentIndex::ID]), doctors));
	} while (true);
}

vector<Doctor*> HospitalManagementSystem::readDoctors(ifstream& hospitalData) {
	string dataStream;
	vector<string>info;
	vector<Doctor*> doctors;
	do {
		getline(hospitalData, dataStream);
		if (dataStream == "subdepartmentend") break;
		info = readOneLine(dataStream, 5);
		doctors.push_back(new Doctor(info[(int)doctorIndex::name], info[(int)doctorIndex::contact],
			(unsigned int)stoi(info[(int)doctorIndex::ID]), info[(int)doctorIndex::description],
			info[(int)doctorIndex::secretCode]));
	} while (true);
	return doctors;
}

void HospitalManagementSystem::updateInformation() {
	string dataStream = "";
	ofstream hospitalData;
	hospitalData.open("HospitalData.txt", ios::trunc);
	for (Hospital* hospital : hospitals) {
		dataStream += updateHospitalInformation(hospital) + "departmentend\n";
	}
	dataStream = dataStream.substr(0, dataStream.size() - 1);
	hospitalData << dataStream;
}

string HospitalManagementSystem::updateHospitalInformation(Hospital* hospital) {
	ostringstream rank;
	rank << std::fixed << setprecision(2) << hospital -> getRank();
	string dataStream = hospital -> getHospitalName() + "," + hospital -> getLocation() + "," +
		hospital -> getContact() + "," + to_string(hospital -> getHospitalID()) + "," +
		to_string(hospital -> getAverageCost()) + "," + rank.str() + "\n";
	for (Department* department : hospital->getDepartments()) {
		dataStream += department->getName() + "," + to_string(department->getDepartmentID()) + "\n";
		for (Doctor* doctor : department->getDoctors()) {
			dataStream += doctor->getDoctorName() + "," + doctor->getContact() + "," +
				to_string(doctor->getDoctorID()) + "," + doctor->getDescription() + "," +
				doctor->getSecretCode() + "\n";
		}
		dataStream += "subdepartmentend\n";
	}
	return dataStream;
}