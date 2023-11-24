#include "Hospital.h"
#include "Tool.h"
using namespace std;

Hospital::Hospital(string _hospitalName, string _location, string _contact, unsigned int _hospitalID,
	int _averageCost, float _rank, vector<string> _comments, vector<Department*> _departments) {
	hospitalName = _hospitalName;
	location = _location;
	contact = _contact;
	hospitalID = _hospitalID;
	averageCost = _averageCost;
	rank = _rank;
	comments = _comments;
	departments = _departments;
}

void Hospital::addEvaluate(std::string newComment) {
	comments.push_back(newComment);
}

std::vector<std::string> Hospital::getCommentList() {
	int orderOfComment = 1;
	vector<string> commentList;
	for (string comment : comments) {
		commentList.push_back(to_string(orderOfComment) + "£º" + comment);
	}
	return commentList;
}

std::vector<std::string> Hospital::getDepartmentList() {
	vector<string>departmentList;
	for (Department* department: departments) {
		departmentList.push_back(department->getName());
	}
	return departmentList;
}