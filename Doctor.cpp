#include "Doctor.h"
#include "Tool.h"
using namespace std;

Doctor::Doctor(string _doctorName, string _contact, unsigned int _doctorID, string _description, string _secretCode){
	doctorName = _doctorName;
	contact = _contact;
	doctorID = _doctorID;
	description = checkLimitSize(_description, 80);
	secretCode = _secretCode;
}

vector<string> Doctor::getDoctorInformation() {
	vector<string>information = { doctorName, contact, to_string(doctorID), description };
	return information;
}

ErrorHandle Doctor::modifyContact(string newContact) {
	if (!checkContact(newContact)) return ErrorHandle("�����Ƿ��ַ�����Ч�ֻ���");
	contact = newContact;
	return ErrorHandle();
}

ErrorHandle Doctor::modifyDescription(string newDescription) {
	if (!checkSize(newDescription))return ErrorHandle("��������Ϊ��");
	description = checkLimitSize(newDescription, 80);
	return ErrorHandle();
}