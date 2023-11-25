#include <iostream> 
#include <vector>
#include <algorithm>
#include "Patient.h"
#include "Doctor.h"
#include "UserManagementSystem.h"
#include "PatientManagementSystem.h"
#include "HospitalManagementSystem.h"

using namespace std;
// Driver Code 
int main()
{
	HospitalManagementSystem HMS;
	cout << "-------------д╛хо-------------" << endl;
	for (vector<string> hospital : HMS.getHospitalList()) {
		for (string str : hospital) {
			cout << str << " ";
		}
		cout << endl;
	}
	cout << "-------------rank-------------" << endl;
	HMS.sortHospitalList("rank");
	for (vector<string> hospital : HMS.getHospitalList()) {
		for (string str : hospital) {
			cout << str << " ";
		}
		cout << endl;
	}
	cout << "-------------name-------------" << endl;
	HMS.sortHospitalList("name");
	for (vector<string> hospital : HMS.getHospitalList()) {
		for (string str : hospital) {
			cout << str << " ";
		}
		cout << endl;
	}
	cout << "-------------cost-------------" << endl;
	HMS.sortHospitalList("cost");
	for (vector<string> hospital : HMS.getHospitalList()) {
		for (string str : hospital) {
			cout << str << " ";
		}
		cout << endl;
	}
	cout << "-------------д╛хо-------------" << endl;
	HMS.sortHospitalList("111");
	for (vector<string> hospital : HMS.getHospitalList()) {
		for (string str : hospital) {
			cout << str << " ";
		}
		cout << endl;
	}
	HMS.updateInformation();
	return 0;
}
