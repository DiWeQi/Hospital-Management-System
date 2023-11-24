#pragma once
#include <string>
#include <vector>
#include "Hospital.h"
#include "ErrorHandle.h"

class HospitalManagementSystem
{
public:
	HospitalManagementSystem();


private:
	std::vector<Hospital*> hospitals;
};

