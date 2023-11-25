#pragma once
#include "HospitalManagementSystem.h"
#include "PatientManagementSystem.h"
#include "UserManagementSystem.h"
#include "ErrorHandle.h"
#include "UI.h"

class ManagementSystem{
public:
	ManagementSystem();
	ErrorHandle userLogin();
	ErrorHandle userLogout();
	ErrorHandle bindIdentity();

	ErrorHandle userRegister();


	//ҽ����ؽӿ�
	ErrorHandle getPatientList();
	ErrorHandle sendBill();
	ErrorHandle modifyDoctorInformation();

	//������ؽӿ�
	ErrorHandle getHospitalList();
	ErrorHandle sortHospitalList();
	ErrorHandle getCommentList();
	ErrorHandle getDepartmentList();
	ErrorHandle addEvaluate();
	ErrorHandle makeAppointment();
	ErrorHandle modifyUserInformation();
	ErrorHandle charge();
	ErrorHandle pay();

private:
	User* currentUser;
	Patient* identityBindP;
	Doctor* identityBindD;
	int identityCode;
	int verified;
	PatientManagementSystem* PMS;
	HospitalManagementSystem* HMS;
	UserManagementSystem* UMS;
	UI* EUI;
	std::vector<std::string> pages;
};

