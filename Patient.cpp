#include "Patient.h"
using namespace std;

Patient::Patient(string patientName, int patientID, string contact, string doctorName, int cost):
	patientName(patientName), patientID(patientID), contact(contact), doctorName(doctorName), cost(cost)
{}

vector<pair<string, int>> Patient::getPatientInformation()
{
	vector<pair<string, int>>information = {
		{patientName, 20}, {to_string(patientID), 20}, {contact, 20},
		{doctorName, 20}, {to_string(cost), 20}
	};
	return information;
}