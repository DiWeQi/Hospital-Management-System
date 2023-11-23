#include "Hospital.h"
using namespace std;

Hospital::Hospital(string hospitalName, string location, int availableBed,
	float rating, string contact, string doctorName, int price):
	hospitalName(hospitalName), location(location), availableBed(availableBed),
	rating(rating), contact(contact), doctorName(doctorName), price(price){}

vector<pair<string, int>> Hospital::getHospitalInformation()
{
	vector<pair<string, int>>information = {
		{hospitalName, 20}, {location, 20}, {to_string(availableBed), 20},
		{to_string(rating), 20}, {contact, 20}, {doctorName, 20}, {to_string(price), 20}
	};
	return information;
}
