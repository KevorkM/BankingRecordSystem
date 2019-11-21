#include "BankingRecordSystem.h"

using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::ios;


void account_query::ReadData()
{
	cout << "\n Enter you Account ID:";
	cin >> account_number;

	cout << "Enter your first name:";
	cin >> firstName;

	cout << "Enter your last name:";
	cin >> lastName;

	cout << "Enter Balance";
	cin >> TotalBalance;
	cout << endl;
}

void account_query::ShowData()
{
	cout <<" Account number: "<<account_number<<endl;
	cout <<" First name: " << firstName << endl;
	cout <<" Last Name: " << lastName << endl;
	cout << " Current balance is: Rs." << TotalBalance << endl;
	
}

void account_query::WriteRec()
{
	ofstream outfile;
	outfile.open("record.bank", ios::binary | ios::app);
	ReadData();
	outfile.write(reinterpret_cast<char*>(this), sizeof(*this));
	outfile.close();
}

void account_query::ReadRec()
{
	ifstream infile;
	infile.open("record.bank", ios::binary);
	if (!infile)
	{
		cout << "Error in Opening! File Not Found!!" << endl;
		return;
	}
	cout << "\n****Data from file****" << endl;
	while (!infile.eof())
	{
		if (infile.read(reinterpret_cast<char*>(this), sizeof(*this)) > 0)
		{
			ShowData();
		}
	}
	infile.close();
}

void account_query::SearchRec()
{
	int n;
	ifstream infile;
	infile.open("record bank", ios::binary);

	if (!infile) {
		cout << "\n Error in opening! File not Found!!" << endl;
		return;
	}
	infile.seekg(0, ios::end);
	int count = infile.tellg() / sizeof(*this);
	cout << "\n There are " << count << " record in the file";
	cout << "\n Enter Record Number to Search: ";
	cin >> n;
	infile.seekg((n - 1) * sizeof(*this));
	infile.read(reinterpret_cast<char*>(this), sizeof(*this));
	ShowData();
}

void account_query::EditRec()
{
	int n;
	fstream iofile;

	iofile.open("record.bank", ios::in | ios::binary);

	if (!iofile) {
		cout << "\n Error in opening! File not found!!" << endl;
		return;
	}
	iofile.seekg(0, ios::end);
	int count = iofile.tellg() / sizeof(*this);
	cout << "\n There are" << count << "record in the file";
	cout << "\n Enter Record Number to Edit: ";
	cin >> n;
}

void account_query::DeleteRec()
{
	int n;
	ifstream infile;
	infile.open("record.bank", ios::binary);

	if (!infile) {
		cout << "\n Error in opening! \n File not found!!" << endl;
		return;
	}
	infile.seekg(0, ios::end);
	int count = infile.tellg() / sizeof(*this);
	cout << "There are " << count << "record in the file";
	cout << "\n  Enter record number to delete: ";
	cin >> n;

	fstream tmpfile;
	tmpfile.open("tmpfile.bank", ios::out | ios::binary);
	infile.seekg(0);

	for (int i = 0; i < count; i++) {
		infile.read(reinterpret_cast<char*>(this), sizeof(*this));
		if (1 == (n - 1))
			continue;
			tmpfile.write(reinterpret_cast<char*>(this), sizeof(*this));
		
		}
	infile.close();
	tmpfile.close();
	remove("record.bank");
	rename("tmpfile.bank", "record.bank");
}
