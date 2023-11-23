#include <iostream>
#include <string>
#include <vector>
#include "Output.h"
using namespace std;

void outPutInformation(string information,int totalSpace)
{
	cout << information;
	int lengthToBeFill = totalSpace - information.length() - 1;
	for (int cnt = 0; cnt < lengthToBeFill; cnt++) cout << " ";
	cout << "|";
}

void outPutList(std::vector<pair<std::string, int>> informations)
{
	for (auto information : informations) {
		outPutInformation(information.first, information.second);
	}
}

void outPutRepeat(std::string str, int times)
{
	for (int cnt = 0; cnt < times; cnt++) cout << str;
	cout << endl;
}
