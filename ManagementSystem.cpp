#include <iostream>
#include "ManagementSystem.h"
#include "Tool.h"
using namespace std;

ManagementSystem::ManagementSystem() {
	PMS = new PatientManagementSystem();
	HMS = new HospitalManagementSystem();
	UMS = new UserManagementSystem();
	identityCode = 0;
	verified = 0;
	identityBindP = NULL;
	identityBindD = NULL;
	EUI = new UI();
}

ErrorHandle ManagementSystem::userLogin() {
	string userName, password;
	EUI->loginInterface(userName, password);
	currentUser = UMS->userLogin(userName, password);
	if (!currentUser == NULL) {
		verified = 1;
		bindIdentity();
		return ErrorHandle();
	}
	return ErrorHandle("Login failed");
}

ErrorHandle ManagementSystem::userLogout() {
	PMS->updateInformation();
	HMS->updateInformation();
	UMS->updateInformation();
	verified = 0;
	return ErrorHandle();
}

ErrorHandle ManagementSystem::bindIdentity() {
	identityBindD = NULL;
	identityBindP = NULL;
	identityCode = (int)currentUser->getIdentityCode();
	if (identityCode == 0) 
		identityBindP = PMS->getPatient(currentUser->getIdentityCode());
	else 
		identityBindD = HMS->getDoctor(currentUser->getIdentityCode());
	return ErrorHandle();
}

ErrorHandle ManagementSystem::userRegister() {
	string name, contact, userName, password, code, secret, des;
	EUI->registerInterface(name, contact, userName, password, code, secret, des);
	if (!checkBasicInformation(contact, password, name, code))
		return ErrorHandle("User information is invalid, registration failed");
	if (stoi(code)) {
		unsigned int ID = HMS -> doctorRegister(name, secret);
		UMS->userRegister(1, userName, password, ID);
	}
	else {
		unsigned int ID = PMS->patientRegister(name, contact);
		UMS->userRegister(0, userName, password, ID);
	}
	return ErrorHandle();
}

ErrorHandle ManagementSystem::getPatientList() {
	string page = EUI->patientListInterface(PMS->getPatientList(identityBindD->getDoctorID()));
	pages.push_back(page);
	return ErrorHandle();
}

ErrorHandle ManagementSystem::sendBill() {
	unsigned int ID;
	float fee;
	EUI->sendBill(ID, fee);
	return PMS->sendBill(ID, fee);
}

ErrorHandle ManagementSystem::modifyDoctorInformation() {
	string newContact, newPassword, newDescription;
	EUI->modifyDoctorInformation(newContact, newPassword, newDescription);
	if(newContact != " ")identityBindD->modifyContact(newContact);
	if (newPassword != " ")currentUser->modifyPassword(newPassword);
	if(newDescription != " ")identityBindD->modifyDescription(newDescription);
	return ErrorHandle();
}

ErrorHandle ManagementSystem::getHospitalList() {
	string page = EUI->hospitalListInterface(HMS->getHospitalList());
	pages.push_back(page);
	return ErrorHandle();
}

ErrorHandle ManagementSystem::sortHospitalList() {
	string mode = EUI->sortHospitalInterface();
	HMS->sortHospitalList(mode);
	getHospitalList();
	return ErrorHandle();
}

ErrorHandle ManagementSystem::getCommentList() {
	unsigned int ID = EUI->commentListInterface();
	string page = HMS->getCommentList(ID);
	EUI->separateLine(100);
	if (page == "") {
		cout << "The hospital does not exist";
		return ErrorHandle("The hospital does not exist");
	}
	cout << page;
	pages.push_back(page);
	return ErrorHandle();
}

ErrorHandle ManagementSystem::getDepartmentList() {
	unsigned int ID = EUI->departmentListInterface();
	string page = HMS->getDepartmentList(ID);
	EUI->separateLine(120);
	if (page == "") {
		cout << "The department does not exist";
		return ErrorHandle("The department does not exist");
	}
	cout << page;
	pages.push_back(page);
	return ErrorHandle();
}

ErrorHandle ManagementSystem::addEvaluate() {
	unsigned int ID;
	string comment;
	EUI->addEvaluateInterface(ID, comment);
	Hospital* hospital = HMS->getHospital(ID);
	if (hospital == NULL) return ErrorHandle("The hospital does not exist");
	return hospital->addEvaluate(comment);
}

ErrorHandle ManagementSystem::makeAppointment() {
	unsigned int ID = EUI->makeAppointmentInterface();
	Doctor* doctor = HMS->getDoctor(ID);
	if (doctor == NULL) return ErrorHandle("The doctor does not exist");
	identityBindP->modifyBind(ID);
	return ErrorHandle();
}

ErrorHandle ManagementSystem::charge() {
	float amount = EUI->chargeInterface();
	if (!checkBalance(amount)) return ErrorHandle("The amount cannot be less than 0");
	currentUser->modifyBlance(amount);
	return ErrorHandle();
}

ErrorHandle ManagementSystem::pay() {
	if (!EUI->payInterface(identityBindP->getUnpaidFee(), currentUser->getBalance()))
		return ErrorHandle("Payment failed");
	currentUser->modifyBlance(-1 * identityBindP->getUnpaidFee());
	identityBindP->setUnpaidFee(0);
	return ErrorHandle();
}

ErrorHandle ManagementSystem::modifyUserInformation() {
	int index;
	string newInformation;
	EUI->modifyUserInformation(newInformation, index);
	if (index == 1)return identityBindP->modifyContact(newInformation);
	if (index == 2)return currentUser->modifyPassword(newInformation);
	else return ErrorHandle("Invalid choice");
}