#include <iomanip>  
#include <sstream> 
#include "Patient.h"
#include "Check.h"
using namespace std;

Patient::Patient(string _patientName, string _contact, unsigned int _patientID, float _unpaidFee){
	patientName = _patientName;
	contact = _contact;
	patientID = _patientID;
	unpaidFee = _unpaidFee;
}

std::vector<std::string> Patient::getPatientInformation(){
	ostringstream stream;
	stream << std::fixed << std::setprecision(2) << unpaidFee;
	vector<string> information = { patientName, contact, to_string(patientID), stream.str() };
	return information;
}

bool Patient::modifyContact(std::string newContact){
	if(!checkContact(newContact)) return false;
	contact = newContact;
	return true;
}

bool Patient::modifyFee(float newFee){
	if (!checkBalance(newFee)) return false;
	unpaidFee += newFee;
	return true;
}