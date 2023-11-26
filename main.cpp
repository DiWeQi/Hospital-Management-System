#include <iostream> 
#include <vector>
#include "ManagementSystem.h"

using namespace std;
// Driver Code 
int main()
{
	ManagementSystem MS;
	while (true) {
		//δ��½���ȵ�½��ע��
		if (!MS.getVerified()) {
			string choice = (MS.EUI->mainInterface()).getErrorInfo();
			cout << "\033[2J\033[1;1H";
			if (choice == "1") cout << (MS.userLogin()).getErrorInfo() << endl; //��½
			else if (choice == "2") cout << (MS.userRegister()).getErrorInfo() << endl; //ע��
			else if (choice == "3") {
				cout << (MS.userLogout()).getErrorInfo(); //�ر�
				break;
			}
			else {
				//������
				MS.EUI->separateLine(100);
				cout << choice << endl;
			}
		}
		else {
			if (MS.getIndentityCode() == 0) { //������ݵ�¼
				while (true)
				{
					string choice = (MS.EUI->patientInterface()).getErrorInfo();
					cout << "\033[2J\033[1;1H";
					if (choice == "1") cout << (MS.getHospitalList()).getErrorInfo() << endl; //�鿴ҽԺ�б�
					else if (choice == "2") cout << (MS.sortHospitalList()).getErrorInfo() << endl; //ҽԺ����
					else if (choice == "3") cout << (MS.getCommentList()).getErrorInfo() << endl; //�鿴ҽԺ����
					else if (choice == "4") cout << (MS.getDepartmentList()).getErrorInfo() << endl; //�鿴ĳ����
					else if (choice == "5") cout << (MS.addEvaluate()).getErrorInfo() << endl; //�������
					else if (choice == "6") cout << (MS.makeAppointment()).getErrorInfo() << endl; //ԤԼ
					else if (choice == "7") cout << (MS.modifyUserInformation()).getErrorInfo() << endl; //�޸ĸ�����Ϣ
					else if (choice == "8") cout << (MS.charge()).getErrorInfo() << endl; //��ֵ
					else if (choice == "9") cout << (MS.pay()).getErrorInfo() << endl;
					else if (choice == "10") {
						cout << (MS.userLogout()).getErrorInfo() << endl; //�ر�
						break;
					}
					else {
						//������
						MS.EUI->separateLine(100);
						cout << choice << endl;
					}
				}
			}
			else { //ҽ����ݵ�¼
				while (true)
				{
					string choice = (MS.EUI->doctorInterface()).getErrorInfo();
					cout << "\033[2J\033[1;1H";
					if (choice == "1") cout << (MS.getPatientList()).getErrorInfo() << endl; //�鿴�����б�
					else if (choice == "2") cout << (MS.sendBill()).getErrorInfo() << endl; //���㻼�߷���
					else if (choice == "3") cout << (MS.modifyDoctorInformation()).getErrorInfo() << endl; //�޸ĸ�����Ϣ
					else if (choice == "4") {
						cout << (MS.userLogout()).getErrorInfo() << endl; //�ر�
						break;
					}
					else {
						//������
						MS.EUI->separateLine(100);
						cout << choice << endl;
					}
				}
			}
		} 
		MS.updateInformation(); //�����ļ���Ϣ
	}
	
	return 0;
}
