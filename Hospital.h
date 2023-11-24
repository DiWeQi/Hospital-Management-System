#pragma once
#include <string>
#include <vector>
#include "Department.h"
#include "Doctor.h"
// Store the data of Hospital 

enum class hospitalIndex {
	name = 0,
	location = 1,
	contact = 2,
	ID = 3,
	averageCost = 4,
	rank = 5
};

class Hospital {
public:
	Hospital(std::string _hospitalName, std::string _location, std::string _contact, unsigned int _hospitalID,
		int _averageCost, float _rank, std::vector<std::string> _comments, std::vector<Department*> _departments);
	void addEvaluate(std::string newComment);
	std::vector<std::string> getCommentList();
	std::vector<std::string> getDepartmentList();

	std::string getHospitalName() { return hospitalName; }
	std::string getLocation() { return location; }
	std::string getContact() { return contact; }
	unsigned int getHospitalID() { return hospitalID; }
	int getAverageCost() { return averageCost; }
	float getRank() { return rank; }
	std::vector<std::string> getComments() { return comments; }
	std::vector<Department*> getDepartments() { return departments; }

private:
	std::string hospitalName;
	std::string location;
	std::string contact;
	unsigned int hospitalID;
	int averageCost;
	float rank;
	std::vector<std::string> comments;
	std::vector<Department*> departments;
};

