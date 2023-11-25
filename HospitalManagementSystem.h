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
	void sortHospitalList(std::string mode);

	//void test();

private:
	std::vector<Hospital*> hospitals;
};

