#include "Department.h"

using namespace std;

Department::Department(std::string _departmentName, unsigned int _departmentID, std::vector<Doctor*> _doctors) {
	departmentName = _departmentName;
	departmentID = _departmentID;
	doctors = _doctors;
}

vector<vector<string>> Department::getDoctorList() {
	vector<vector<string>> doctorList;
	for (Doctor* doctor : doctors) {
		doctorList.push_back(doctor->getDoctorInformation());
	}
	return doctorList;
}

void Department::addDoctor(string doctorName, string contact, unsigned ID, string description) {
	Doctor* newDoctor = new Doctor(doctorName, contact, ID, description);
	doctors.push_back(newDoctor);
}