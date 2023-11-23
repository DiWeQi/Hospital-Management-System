#pragma warning(disable : 4996)
#include "ManagementSystem.h"
#include "Output.h"
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

const vector<pair<string, int>> tableHeaderOfHospital({
	{"Hospital Name" , 20}, {"Location", 20}, {"Beds Available", 20},
	{"Rating", 20}, {"Hospital Contact", 20}, {"DoctorName", 20}, {"Price PerBed", 20}
});

const vector<pair<string, int>> tableHeaderOfPatient({
	{"Patient Name", 20}, {"Patient ID", 20}, {"Patient Contact", 20}, {"Alloted Hospital", 20},
	{"Patient Expenditure", 20}
});

ManagementSystem::ManagementSystem()
{
	readHospitalInformation();
	readPatientInformation();
}

void ManagementSystem::readHospitalInformation()
{
	ifstream hospitalInformation;
	hospitalInformation.open("HospitalData.txt", ios::in);
	string data;
	char readData1[100], readData2[100], readData3[100], readData4[100], readData5[100], readData6[100], readData7[100];
	while (getline(hospitalInformation, data)) {
		sscanf(data.c_str(), "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,]",
			readData1, readData2, readData3, readData4, readData5, readData6, readData7);
		string hospitalName(readData1), location(readData2), availableBed(readData3);
		string rating(readData4), contact(readData5), doctorName(readData6), price(readData7);
		Hospital H(hospitalName, location, stoi(availableBed), stof(rating), contact, doctorName, stoi(price));
		hospitals.push_back(H);
	}
	hospitalInformation.close();
}

void ManagementSystem::readPatientInformation()
{
	ifstream patientInformation;
	patientInformation.open("PatientData.txt", ios::in);
	string data;
	char readData1[100], readData2[100], readData3[100], readData4[100], readData5[100];

	while (getline(patientInformation, data)) {
		sscanf(data.c_str(), "%[^,],%[^,],%[^,],%[^,],%[^,]",
			readData1, readData2, readData3, readData4, readData5);
		string patientName(readData1), patientID(readData2), contact(readData3), doctorName(readData4), cost(readData5);
		Patient P(patientName, stoi(patientID), contact, doctorName, stoi(cost));
		patients.push_back(P);
	}
	patientInformation.close();
}

void ManagementSystem::printHospitalsInformation()
{
	//打印列表头
	cout << "Hospitals Data:" << endl;
	outPutRepeat("-", 141);
	cout << "|";
	outPutList(tableHeaderOfHospital);
	cout << endl;
	outPutRepeat("-", 141);
	// 打印各医院信息
	for (auto hospital: hospitals) {
		cout << "|";
		outPutList(hospital.getHospitalInformation());
		cout << endl;
		outPutRepeat("-", 141);
	}
	cout << endl << endl;
}

void ManagementSystem::PrintPatientInformation()
{
	// 打印表头
	cout << "Patients Data:" << endl;
	outPutRepeat("-", 101);
	cout << "|";
	outPutList(tableHeaderOfPatient);
	cout << endl;
	outPutRepeat("-", 101);
	// 打印患者信息
	for (auto patient : patients) {
		cout << "|";
		outPutList(patient.getPatientInformation());
		cout << endl;
		outPutRepeat("-", 101);
	}
	cout << endl << endl;
}

void ManagementSystem::sortByName()
{
	sort(hospitals.begin(), hospitals.end(), [](Hospital A, Hospital B) {return A.getName() < B.getName();});
	cout << "The hospital information has been sorted by hospital name" << endl << endl;
}

void ManagementSystem::sortByBedsPrice()
{
	sort(hospitals.begin(), hospitals.end(), [](Hospital A, Hospital B) {return A.getPrice() < B.getPrice();});
	cout << "The hospital information has been sorted by bed fee" << endl << endl;
}

void ManagementSystem::sortByRating()
{
	sort(hospitals.begin(), hospitals.end(), [](Hospital A, Hospital B) {return A.getRating() > B.getRating();});
	cout << "The hospital information has been sorted by rating" << endl << endl;
}

void ManagementSystem::sortByAvailableBed()
{
	sort(hospitals.begin(), hospitals.end(), [](Hospital A, Hospital B) {return A.getAvailableBed() > B.getAvailableBed();});
	cout << "The hospital information has been sorted by available bed" << endl << endl;
}