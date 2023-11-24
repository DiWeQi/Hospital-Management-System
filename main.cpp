#include <iostream> 
#include <vector>
#include <algorithm>
#include "Patient.h"
#include "Doctor.h"
#include "UserManagementSystem.h"
#include "PatientManagementSystem.h"

using namespace std;
// Driver Code 
int main()
{
	PatientManagementSystem PMS;
	for (auto patientInfor : PMS.getPatientList(1)) {
		for (auto info : patientInfor) {
			cout << info << " ";
		}
		cout << endl;
	}
	cout << (PMS.sendBill(1, -60)).getErrorInfo() << endl;
	cout << (PMS.sendBill(1, 60)).getErrorInfo() << endl;
	for (auto patientInfor : PMS.getPatientList(1)) {
		for (auto info : patientInfor) {
			cout << info << " ";
		}
		cout << endl;
	}
	PMS.updateInformation();
	return 0;
}
