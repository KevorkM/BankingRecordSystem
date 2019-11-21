#pragma once

#include <iostream>
#include <fstream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::ios;


class account_query {

private: 
	
	char account_number[20];
	char firstName[10];
	char lastName[10];
	float TotalBalance;

public:
	
	void ReadData();
	void ShowData();
	void WriteRec();
	void ReadRec();
	void SearchRec();
	void EditRec();
	void DeleteRec();
};
