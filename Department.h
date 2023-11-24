#pragma once
#include "Doctor.h"

enum class departmentIndex {
	name = 0,
	ID = 1
};

class Department{
public:
	Department(std::string _departmentName, unsigned int _departmentID, std::vector<Doctor*> _doctors);
	std::vector<std::vector<std::string>> getDoctorList(); //返回该科室下所有医生信息
	void addDoctor(std::string doctorName, std::string contact, unsigned ID, std::string description); //在该科室下添加医生

	std::string getName() { return departmentName; }
	unsigned int getDepartmentID() { return departmentID; }
	std::vector<Doctor*> getDoctors() { return doctors; }

private:
	std::string departmentName;
	unsigned int departmentID;
	std::vector<Doctor*> doctors; //指向科室下所有医生信息
};

