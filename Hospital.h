#pragma once
#include <string>
#include <vector>
#include "Department.h"
#include "Doctor.h"
// Store the data of Hospital 

class Hospital {
public:
	

private:
	std::string hospitalName;
	std::string location;
	std::string contact;
	int HospitalID;
	int averageCost;
	float rank;
	std::vector<std::string> comments;
	std::vector<Department*> departments;
};

