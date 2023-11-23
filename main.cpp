#include "Hospital.h"
#include "Patient.h"
#include "ManagementSystem.h"
#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
// Driver Code 
int main()
{
	ManagementSystem HM;
	HM.printHospitalsInformation();
	HM.sortByName();
	HM.printHospitalsInformation();
	HM.sortByBedsPrice();
	HM.printHospitalsInformation();
	HM.sortByAvailableBed();
	HM.printHospitalsInformation();
	HM.sortByRating();
	HM.printHospitalsInformation();
	HM.PrintPatientInformation();
	return 0;
}
