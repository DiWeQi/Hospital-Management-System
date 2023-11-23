#include "Doctor.h"
#include "Check.h"
using namespace std;

Doctor::Doctor(string _doctorName, string _contact, unsigned int _doctorID, string _description){
	doctorName = _doctorName;
	contact = _contact;
	doctorID = _doctorID;
	description = checkLimitSize(_description, 80);
}

vector<string> Doctor::getDoctorInformation() {
	vector<string>information = { doctorName, contact, to_string(doctorID), description };
	return information;
}

bool Doctor::modifyContact(string newContact) {
	if (!checkContact(newContact)) return false;
	contact = newContact;
	return true;
}

bool Doctor::modifyDescription(string newDescription) {
	if (!checkSize(newDescription))return false;
	description = checkLimitSize(newDescription, 80);
	return true;
}