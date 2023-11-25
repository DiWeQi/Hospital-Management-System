#include "User.h"
#include "Tool.h"
using namespace std;

User::User(unsigned _userID, unsigned int _identityCode, string _userName,
	string _password, unsigned int _bindDoctor, float _balance) {
	userID = _userID;
	identityCode = _identityCode;
	userName = _userName;
	password = _password;
	bindDoctor = _bindDoctor;
	balance = _balance;
	identityBindingDoctor = NULL;
	identityBindingPatient = NULL;
}

vector<string> User::getUserInformation() {
	if (identityBindingDoctor) return identityBindingDoctor->getDoctorInformation();
	else return identityBindingPatient -> getPatientInformation();
}

ErrorHandle User::modifyPassword(string newPassword) {
	if (!checkSize(newPassword)) return ErrorHandle("ÃÜÂë²»ÄÜÎª¿Õ");
	password = newPassword;
	return ErrorHandle();
}

void User::modifyBlance(float _balance) {
	balance += _balance;
}