#pragma once
#include <string>
#include <vector>
#include "Department.h"
#include "Doctor.h"
// Store the data of Hospital 

class Hospital {
public:
	Hospital(std::string _hospitalName, std::string _location, std::string _contact, unsigned int _HospitalID,
		int _averageCost, float _rank, std::vector<std::string> _comments, std::vector<Department*> _departments);
	void addEvaluate(std::string newComment);
	std::vector<std::string> getCommentList();
	std::vector<std::string> getDepartmentList();

private:
	std::string hospitalName;
	std::string location;
	std::string contact;
	unsigned int HospitalID;
	int averageCost;
	float rank;
	std::vector<std::string> comments;
	std::vector<Department*> departments;
};

