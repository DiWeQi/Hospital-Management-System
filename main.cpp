#include <iostream> 
#include <vector>
#include "ManagementSystem.h"

using namespace std;
// Driver Code 
int main()
{
	ManagementSystem MS;
	while (true) {
		//未登陆则先登陆或注册
		if (!MS.getVerified()) {
			string choice = (MS.EUI->mainInterface()).getErrorInfo();
			cout << "\033[2J\033[1;1H";
			if (choice == "1") cout << (MS.userLogin()).getErrorInfo() << endl; //登陆
			else if (choice == "2") cout << (MS.userRegister()).getErrorInfo() << endl; //注册
			else if (choice == "3") {
				cout << (MS.userLogout()).getErrorInfo(); //关闭
				break;
			}
			else {
				//错误处理
				MS.EUI->separateLine(100);
				cout << choice << endl;
			}
		}
		else {
			if (MS.getIndentityCode() == 0) { //患者身份登录
				while (true)
				{
					string choice = (MS.EUI->patientInterface()).getErrorInfo();
					cout << "\033[2J\033[1;1H";
					if (choice == "1") cout << (MS.getHospitalList()).getErrorInfo() << endl; //查看医院列表
					else if (choice == "2") cout << (MS.sortHospitalList()).getErrorInfo() << endl; //医院排序
					else if (choice == "3") cout << (MS.getCommentList()).getErrorInfo() << endl; //查看医院评论
					else if (choice == "4") cout << (MS.getDepartmentList()).getErrorInfo() << endl; //查看某科室
					else if (choice == "5") cout << (MS.addEvaluate()).getErrorInfo() << endl; //添加评论
					else if (choice == "6") cout << (MS.makeAppointment()).getErrorInfo() << endl; //预约
					else if (choice == "7") cout << (MS.modifyUserInformation()).getErrorInfo() << endl; //修改个人信息
					else if (choice == "8") cout << (MS.charge()).getErrorInfo() << endl; //充值
					else if (choice == "9") cout << (MS.pay()).getErrorInfo() << endl;
					else if (choice == "10") {
						cout << (MS.userLogout()).getErrorInfo() << endl; //关闭
						break;
					}
					else {
						//错误处理
						MS.EUI->separateLine(100);
						cout << choice << endl;
					}
				}
			}
			else { //医生身份登录
				while (true)
				{
					string choice = (MS.EUI->doctorInterface()).getErrorInfo();
					cout << "\033[2J\033[1;1H";
					if (choice == "1") cout << (MS.getPatientList()).getErrorInfo() << endl; //查看患者列表
					else if (choice == "2") cout << (MS.sendBill()).getErrorInfo() << endl; //结算患者费用
					else if (choice == "3") cout << (MS.modifyDoctorInformation()).getErrorInfo() << endl; //修改个人信息
					else if (choice == "4") {
						cout << (MS.userLogout()).getErrorInfo() << endl; //关闭
						break;
					}
					else {
						//错误处理
						MS.EUI->separateLine(100);
						cout << choice << endl;
					}
				}
			}
		} 
		MS.updateInformation(); //更新文件信息
	}
	
	return 0;
}
