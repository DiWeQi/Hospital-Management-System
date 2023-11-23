#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "Doctor.h"

class Department{
public:
	Department(std::string _departmentName, unsigned int _departmentID, std::vector<Doctor*> _doctors);
	std::vector<std::vector<std::string>> getDoctorList(); //���ظÿ���������ҽ����Ϣ
	void addDoctor(std::string doctorName, std::string contact, unsigned ID, std::string description); //�ڸÿ��������ҽ��

private:
	std::string departmentName;
	unsigned int departmentID;
	std::vector<Doctor*> doctors; //ָ�����������ҽ����Ϣ
};

