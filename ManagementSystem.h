#pragma once
#include "HospitalManagementSystem.h"
#include "PatientManagementSystem.h"
#include "UserManagementSystem.h"
#include "ErrorHandle.h"
#include "UI.h"

class ManagementSystem{
public:
	ManagementSystem();
	void updateInformation();
	ErrorHandle userLogin();
	ErrorHandle userLogout();
	ErrorHandle bindIdentity();

	ErrorHandle userRegister();


	//医生相关接口
	ErrorHandle getPatientList();
	ErrorHandle sendBill();
	ErrorHandle modifyDoctorInformation();

	//患者相关接口
	ErrorHandle getHospitalList();
	ErrorHandle sortHospitalList();
	ErrorHandle getCommentList();
	ErrorHandle getDepartmentList();
	ErrorHandle addEvaluate();
	ErrorHandle makeAppointment();
	ErrorHandle modifyUserInformation();
	ErrorHandle charge();
	ErrorHandle pay();

	int getVerified() { return verified; }
	int getIndentityCode() { return identityCode; }

	UI* EUI;

private:
	User* currentUser;
	Patient* identityBindP;
	Doctor* identityBindD;
	int identityCode;
	int verified;
	PatientManagementSystem* PMS;
	HospitalManagementSystem* HMS;
	UserManagementSystem* UMS;
	std::vector<std::string> pages;
};

