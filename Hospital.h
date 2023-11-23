#pragma once
#include <string>
#include <unordered_map>
// Store the data of Hospital 

class Hospital {
public:
	Hospital(std::string hospitalName, std::string location, int availableBed,
			float rating, std::string contact, std::string doctorName, int price); // initialization
	std::vector<std::pair<std::string, int>> getHospitalInformation(); // Return processed hospital's information
	std::string getName(){ return hospitalName; } 
	int getPrice(){ return price; }
	int getAvailableBed() { return availableBed; }
	float getRating() { return rating; }
	

private:
	std::string hospitalName;
	std::string location;
	int availableBed;
	float rating;
	std::string contact;
	std::string doctorName;
	int price;
};

