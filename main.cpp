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
	HMS.updateInformation();
	for (vector<string> hospital : HMS.getHospitalList()) {
		for (string str : hospital) {
			cout << str << " ";
		}
		cout << endl;
	}
	return 0;
}
