#pragma once
#include "Hospital.h"
#include "Patient.h"
#include <vector>

class ManagementSystem
{
public:
	// Initialization
	ManagementSystem();
	void readHospitalInformation(); // read hospital informations
	void readPatientInformation(); // read patient informations

	// Print information
	void printHospitalsInformation(); // Print Hospitals Data 
	void PrintPatientInformation(); // Print Patients Data

	void sortByName(); // sort hospitals by name
	void sortByBedsPrice(); // sort hospitals by bed price
	void sortByRating(); // sort hospitals by rating
	void sortByAvailableBed(); //sort hospitals by available bed

private:
	std::vector<Hospital> hospitals;
	std::vector<Patient> patients;
};

