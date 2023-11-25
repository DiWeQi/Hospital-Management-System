#include <iomanip>  
#include <sstream> 
#include "Patient.h"
#include "Tool.h"
using namespace std;

Patient::Patient(string _patientName, string _contact, unsigned int _patientID, float _unpaidFee, unsigned int _bind){
	patientName = _patientName;
	contact = _contact;
	patientID = _patientID;
	unpaidFee = _unpaidFee;
	bind = _bind;
}

std::vector<std::string> Patient::getPatientInformation(){
	ostringstream stream;
	stream << std::fixed << std::setprecision(2) << unpaidFee;
	vector<string> information = { patientName, contact, to_string(patientID), 
		stream.str(), to_string(bind) };
	return information;
}

ErrorHandle Patient::modifyContact(std::string newContact){
	if (!checkContact(newContact)) return ErrorHandle("�����Ƿ��ַ�����Ч�ֻ���");
	contact = newContact;
	return ErrorHandle();
}

ErrorHandle Patient::modifyFee(float newFee){
	if (!checkBalance(newFee)) return ErrorHandle("����С��0");
	unpaidFee += newFee;
	return ErrorHandle();
}

void Patient::setUnpaidFee(float unpaid) {
	unpaidFee = unpaid;
}

void Patient::modifyBind(unsigned int ID) {
	bind = ID;
}