#pragma once
#include "HospitalManagementSystem.h"
#include "PatientManagementSystem.h"
#include "UserManagementSystem.h"
#include "ErrorHandle.h"

class ManagementSystem{
public:
	ManagementSystem();
	ErrorHandle userLogin();
	ErrorHandle userRegister();

	//医生相关接口
	ErrorHandle getPatientList();
	ErrorHandle sendBill(unsigned int ID);
	ErrorHandle modifyDoctorInformation();

	//患者相关接口
	ErrorHandle getHospitalList();
	ErrorHandle sortHospitalList(std::string);
	ErrorHandle getCommentList();
	ErrorHandle getDepartmentList();
	ErrorHandle getDepartmentInformation(unsigned int);
	ErrorHandle addEvaluate(std::string);
	ErrorHandle makeAppointment(unsigned int);
	ErrorHandle modifyUserInformation(std::string newInformation, int index);
	ErrorHandle charge(float money);
	ErrorHandle pay();

private:
	User* currentUser;
	Patient* identityBindP;
	Doctor* identityBindD;
	int identityCode;

	PatientManagementSystem* PMS;
	HospitalManagementSystem* HMS;
};

