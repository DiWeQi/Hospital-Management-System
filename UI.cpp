#include <string>
#include <iostream>
#include "UI.h"
#include "Tool.h"
using namespace std;

void UI::loginInterface(string &userName, string &password) {
	separateLine(100);
	cout << "Enter username here: ";
	getline(cin, userName);
	cout << "Enter password here: ";
	getline(cin, password);
}

void UI::registerInterface(std::string& name, std::string& contact,
	std::string& userName, std::string& password, string& code, string& secret, string& des) {
	separateLine(100);
	cout << "Enter identity here(0: patient; 1:doctor): ";
	getline(cin, code);
	cout << "Enter username here: ";
	getline(cin, userName);
	cout << "Enter password here: ";
	getline(cin, password);
	cout << "Enter name here: ";
	getline(cin, name);
	if (code == "0") {
		cout << "Enter contact here: ";
		getline(cin, contact);
	}
	else if (code == "1") {
		cout << "Enter secret code here: ";
		getline(cin, secret);
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
	separateLine(50);
	return page;
}

void UI::sendBill(string& ID, string& fee) {
	separateLine(100);
	cout << "Enter ID here: ";
	getline(cin, ID);
	cout << "Enter fee here: ";
	getline(cin, fee);
	separateLine(100);
}

void UI::modifyDoctorInformation(string& newContact, string& newPassword, string& des) {
	separateLine(100);
	cout << "If you don't want to modify a certain content, enter 'NA'." << endl;
	cout << "Enter new password: ";
	getline(cin, newContact);
	cout << "Enter new contact: ";
	getline(cin, newPassword);
	cout << "Enter new description: ";
	getline(cin, des);
	separateLine(100);
}

string UI::hospitalListInterface(vector<vector<string>> hospitalList) {
	separateLine(70);
	string page = "";
	page += hospitalLine("Hospital", "Contact", "Location", "Rank");
	for (vector<string> hospital : hospitalList) {
		page += hospitalLine(hospital[(int)hospitalIndex::name], hospital[(int)hospitalIndex::contact],
			hospital[(int)hospitalIndex::location], hospital[(int)hospitalIndex::rank]);
	}
	separateLine(70);
	cout << page;
	separateLine(70);
	return page;
}

string UI::sortHospitalInterface() {
	string type;
	separateLine(100);
	cout << "1.Sort by rank     2.Sort by name      3.Sort by cost      4.Default" << endl;
	cout << "Enter type of sort: ";
	getline(cin, type);
	separateLine(100);
	if (type == "1")return "rank";
	if (type == "2") return "name";
	if (type == "3") return "cost";
	return "default";
}

string UI::commentListInterface() {
	string ID;
	separateLine(100);
	cout << "Enter the hospital ID: ";
	getline(cin, ID);
	separateLine(100);
	return ID;
}

string UI::departmentListInterface() {
	string ID;
	separateLine(100);
	cout << "Enter the department ID: ";
	getline(cin, ID);
	separateLine(100);
	return ID;
}

void UI::separateLine(int length) {
	cout << fillStr("-", length) << endl;
}

void UI::addEvaluateInterface(string& ID, string& comment) {
	separateLine(100);
	cout << "Enter the hospital ID: ";
	getline(cin, ID);
	cout << "Enter the comment: ";
	getline(cin, comment);
	separateLine(100);
}

string UI::makeAppointmentInterface() {
	string ID;
	separateLine(100);
	cout << "Enter the doctor ID: ";
	getline(cin, ID);
	separateLine(100);
	return ID;
}

string UI::chargeInterface() {
	string money;
	separateLine(100);
	cout << "Enter the amount: ";
	getline(cin, money);
	separateLine(100);
	return money;
}

bool UI::payInterface(float fee, float balance) {
	if (fee > balance) return false;
	string paid;
	separateLine(100);
	cout << "Enter Y to ensure: ";
	getline(cin, paid);
	separateLine(100);
	if (paid == "Y") return true;
	return false;
}

void UI::modifyUserInformation(string& newContext, string& index) {
	separateLine(100);
	cout << "1.Contact   2.Password" << endl;
	cout << "Enter choice here: ";
	getline(cin, index);
	cout << "Enter new information here: ";
	getline(cin, newContext);;
	separateLine(100);
}

ErrorHandle UI::mainInterface() {
	separateLine(100);
	string index;
	cout << "1.Login  2.Register  3.Quit" << endl;
	cout << "Enter choice here: ";
	getline(cin, index);
	separateLine(100);
	if (index != "1" && index != "2" && index != "3") return ErrorHandle("Invalid choice");
	return ErrorHandle(index);
}

ErrorHandle UI::patientInterface() {
	separateLine(150);
	string index;
	cout << "1.Hospital List   2.Sort Hospital List   3.Comment List   4.Department Information   5.Add Evaluate   6.Make Appointment   7.Modify Information   8.Charge  9.Pay   10.Quit" << endl;
	cout << "Enter choice here: ";
	getline(cin, index);
	if (index != "1" && index != "2" && index != "3" && index != "4" && index != "5"
		&& index != "6" && index != "7" && index != "8" && index != "9" && index != "10")
		return ErrorHandle("Invalid choice");
	separateLine(150);
	return ErrorHandle(index);
}

ErrorHandle UI::doctorInterface() {
	separateLine(100);
	string index;
	cout << "1.Patient List     2.Send Bill     3.Modify Information     4.Quit" << endl;
	cout << "Enter choice here: ";
	getline(cin, index);
	separateLine(100);
	if (index != "1" && index != "2" && index != "3" && index != "4") return ErrorHandle("Invalid choice");
	return ErrorHandle(index);
}