#include <string>
#include <iostream>
#include "UI.h"
#include "Tool.h"
using namespace std;

void UI::loginInterface(string &userName, string &password) {
	separateLine(100);
	cout << "Enter username here: ";
	cin >> userName;
	cout << "Enter password here: ";
	cin >> password;
}

void UI::registerInterface(std::string& name, std::string& contact,
	std::string& password, std::string& userName, string& code, string& secret, string& des) {
	separateLine(100);
	cout << "Enter name here: ";
	cin >> name;
	cout << "Enter contact here: ";
	cin >> contact;
	cout << "Enter username here: ";
	cin >> userName;
	cout << "Enter password here: ";
	cin >> password;
	cout << "Enter identity here(0: patient; 1:doctor): ";
	cin >> code;
	if (stoi(code) == 1) {
		cout << "Enter your description: ";
		cin >> des;
		cout << "Enter secret code here: ";
		cin >> secret;
	}
	else {
		code = "-1";
	}
}

string UI::patientListInterface(vector<vector<string>> patientList) {
	separateLine(50);
	string page = "";
	page += patientLine("ID", "Name", "Contact", "Unpaid Fee");
	for (vector<string> patient : patientList) {
		page += patientLine(patient[(int)patientIndex::ID], patient[(int)patientIndex::name],
			patient[(int)patientIndex::contact], patient[(int)patientIndex::unpaidfee]);
	}
	separateLine(50);
	cout << page;
	return page;
}

void UI::sendBill(unsigned int& ID, float& fee) {
	separateLine(100);
	cout << "Enter ID here: ";
	cin >> ID;
	cout << "Enter fee here: ";
	cin >> fee;
}

void UI::modifyDoctorInformation(string& newContact, string& newPassword, string& des) {
	separateLine(100);
	cout << "If you don't want to modify a certain content, enter a space and press enter." << endl;
	cout << "Enter new password: ";
	cin >> newContact;
	cout << "Enter new contact: ";
	cin >> newPassword;
	cout << "Enter new description: ";
	cin >> des;
}

string UI::hospitalListInterface(vector<vector<string>> hospitalList) {
	string page = fillStr("-", 55) + "\n";
	page += hospitalLine("Hospital", "Contact", "Location", "Rank");
	for (vector<string> hospital : hospitalList) {
		page += hospitalLine(hospital[(int)hospitalIndex::name], hospital[(int)hospitalIndex::contact],
			hospital[(int)hospitalIndex::location], hospital[(int)hospitalIndex::rank]);
	}
	separateLine(55);
	cout << page;
	return page;
}

string UI::sortHospitalInterface() {
	string type;
	separateLine(100);
	cout << "1.Sort by rank     2.Sort by name      3.Sort by cost      4.Default" << endl;
	cout << "Enter type of sort: ";
	cin >> type;
	if (type == "1")return "rank";
	if (type == "2") return "name";
	if (type == "3") return "cost";
	return "default";
}

unsigned int UI::commentListInterface() {
	unsigned int ID;
	separateLine(100);
	cout << "Enter the hospital ID: ";
	cin >> ID;
	return ID;
}

unsigned int UI::departmentListInterface() {
	unsigned int ID;
	separateLine(100);
	cout << "Enter the department ID: ";
	cin >> ID;
	return ID;
}

void UI::separateLine(int length) {
	cout << fillStr("-", length) << endl;
}

void UI::addEvaluateInterface(unsigned int& ID, string& comment) {
	separateLine(100);
	cout << "Enter the hospital ID: ";
	cin >> ID;
	cout << "Enter the comment: ";
	cin >> comment;
}

unsigned int UI::makeAppointmentInterface() {
	unsigned int ID;
	separateLine(100);
	cout << "Enter the doctor ID: ";
	cin >> ID;
	return ID;
}

float UI::chargeInterface() {
	float money;
	separateLine(100);
	cout << "Enter the amount: ";
	cin >> money;
	return money;
}

bool UI::payInterface(float fee, float balance) {
	if (fee > balance) return false;
	string paid;
	separateLine(100);
	cout << "Enter Y to ensure: ";
	cin >> paid;
	if (paid == "Y") return true;
	return false;
}

void UI::modifyUserInformation(string& newContext, int& index) {
	separateLine(100);
	cout << "1.Contact   2.Password" << endl;
	cout << "Enter choice here: ";
	cin >> index;
	"Enter new information here: ";
	cin >> newContext;
}