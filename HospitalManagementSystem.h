#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "Hospital.h"
#include "ErrorHandle.h"

class HospitalManagementSystem
{
public:
	HospitalManagementSystem();
	Hospital* readHospital(std::ifstream& hospitalData);
	std::vector<std::string> readComments(std::ifstream& hospitalData);
	std::vector<Department*> readDepartments(std::ifstream& hospitalData);
	std::vector<Doctor*> readDoctors(std::ifstream& hospitalData);

	void updateInformation();
	std::string updateHospitalInformation(Hospital* hospital);

	std::vector<std::vector<std::string>> getHospitalList();
	Doctor* getDoctor(unsigned int ID);
	Hospital* getHospital(unsigned int ID);
	void sortHospitalList(std::string mode);

	int doctorRegister(std::string _doctorName, std::string _secretCode);
	std::string getCommentList(unsigned int ID);
	std::string getDepartmentList(unsigned int ID);

private:
	std::vector<Hospital*> hospitals;
};

