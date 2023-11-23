#pragma once
#include <string>
#include <vector>

//After printing the information, fill in blank spaces to align
void outPutInformation(std::string information, int totalSpace = 20);

//Print a whole line of information
void outPutList(std::vector<std::pair<std::string, int>> informations);

void outPutRepeat(std::string str, int times);