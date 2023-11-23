#pragma once
#include <string>
#include <unordered_map>
// Store the data of Patient

class Patient{
public:
	Patient(std::string patientName, int patientID, std::string contact, std::string doctorName, int cost);  // initialization
	std::vector<std::pair<std::string, int>> getPatientInformation(); // Return processed patient's information

private:
	std::string patientName;
	int patientID;
	std::string contact;
	std::string doctorName;
	int cost;
};

