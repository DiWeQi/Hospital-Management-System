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
	currentUser = NULL;
	identityBindP = NULL;
	identityBindD = NULL;
	EUI = new UI();
}

void ManagementSystem::updateInformation() {
	UMS->updateInformation();
	HMS->updateInformation();
	PMS->updateInformation();
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
	currentUser = NULL;
	identityBindP = NULL;
	identityBindD = NULL;
	return ErrorHandle();
}

ErrorHandle ManagementSystem::bindIdentity() {
	identityBindD = NULL;
	identityBindP = NULL;
	identityCode = (int)currentUser->getIdentityCode();
	if (identityCode == 0) 
		identityBindP = PMS->getPatient(currentUser->getUserID());
	else 
		identityBindD = HMS->getDoctor(currentUser->getUserID());
	return ErrorHandle();
}

ErrorHandle ManagementSystem::userRegister() {
	string name, contact, userName, password, code, secret, des;
	EUI->registerInterface(name, contact, userName, password, code, secret, des);
	if (code == "0") {
		if (!checkBasicInformation(contact, password, name, code))
			return ErrorHandle("User information is invalid, registration failed");
		unsigned int ID = PMS->patientRegister(name, contact);
		UMS->userRegister(0, userName, password, ID);
	}
	else if (code == "1") {
		unsigned int ID = HMS -> doctorRegister(name, secret);
		if (ID == -1) return ErrorHandle("The doctor does not exit");
		return UMS->userRegister(1, userName, password, ID);
	}
	else {
		return ErrorHandle("Invalid indentity code");
	}
	return ErrorHandle();
}

ErrorHandle ManagementSystem::getPatientList() {
	string page = EUI->patientListInterface(PMS->getPatientList(identityBindD->getDoctorID()));
	pages.push_back(page);
	return ErrorHandle();
}

ErrorHandle ManagementSystem::sendBill() {
	string ID, fee;
	EUI->sendBill(ID, fee);
	if (!checkContact(ID))return ErrorHandle("Invalid ID");
	if (!checkFloat(fee)) return ErrorHandle("Invalid amount");
	return PMS->sendBill(stoi(ID), stof(fee), identityBindD->getDoctorID());
}

ErrorHandle ManagementSystem::modifyDoctorInformation() {
	string newContact, newPassword, newDescription;
	EUI->modifyDoctorInformation(newContact, newPassword, newDescription);
	if(newContact != "NA")identityBindD->modifyContact(newContact);
	if (newPassword != "NA")currentUser->modifyPassword(newPassword);
	if(newDescription != "NA")identityBindD->modifyDescription(newDescription);
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
	string ID = EUI->commentListInterface();
	if (!checkContact(ID))return ErrorHandle("Invalid ID");
	string page = HMS->getCommentList(stoi(ID));
	EUI->separateLine(100);
	if (page == "") {
		return ErrorHandle("The hospital does not exist");
	}
	cout << page;
	EUI->separateLine(100);
	pages.push_back(page);
	return ErrorHandle();
}

ErrorHandle ManagementSystem::getDepartmentList() {
	string ID = EUI->departmentListInterface();
	if (!checkContact(ID))return ErrorHandle("Invalid ID");
	string page = HMS->getDepartmentList(stoi(ID));
	EUI->separateLine(120);
	if (page == "") {
		return ErrorHandle("The department does not exist");
	}
	cout << page;
	EUI->separateLine(120);
	pages.push_back(page);
	return ErrorHandle();
}

ErrorHandle ManagementSystem::addEvaluate() {
	string ID, comment;
	EUI->addEvaluateInterface(ID, comment);
	if (!checkContact(ID)) return ErrorHandle("Invalid ID");
	Hospital* hospital = HMS->getHospital(stoi(ID));
	if (hospital == NULL) return ErrorHandle("The hospital does not exist");
	return hospital->addEvaluate(comment);
}

ErrorHandle ManagementSystem::makeAppointment() {
	string ID = EUI->makeAppointmentInterface();
	if (!checkContact(ID)) return ErrorHandle("Invalid ID");
	Doctor* doctor = HMS->getDoctor(stoi(ID));
	if (doctor == NULL) return ErrorHandle("The doctor does not exist");
	identityBindP->modifyBind(stoi(ID));
	return ErrorHandle();
}

ErrorHandle ManagementSystem::charge() {
	string amount = EUI->chargeInterface();
	if (!checkFloat(amount)) return ErrorHandle("Invalid amount");
	if (!checkBalance(stof(amount))) return ErrorHandle("The amount cannot be less than 0");
	currentUser->modifyBlance(stof(amount));
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
	string index, newInformation;
	EUI->modifyUserInformation(newInformation, index);
	if (!checkContact(index)) return ErrorHandle("Invalid ID");
	if (stoi(index) == 1)return identityBindP->modifyContact(newInformation);
	if (stoi(index) == 2)return currentUser->modifyPassword(newInformation);
	else return ErrorHandle("Invalid choice");
}