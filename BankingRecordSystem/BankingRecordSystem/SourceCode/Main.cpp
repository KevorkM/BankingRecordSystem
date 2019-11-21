#include "BankingRecordSystem.cpp"

int main()
{
	account_query A;
	int choice;
	cout << "***Acount Information System***" << endl;
	while (true)
	{
		cout << "Select one option below ";
		cout << "\n\t1-->Add record to file";
		cout << "\n\t2-->Show record from file";
		cout << "\n\t3-->Search Record from file";
		cout << "\n\t4-->Update Record";
		cout << "\n\t5-->Delete Record";
		cout << "\n\t6-->Quit";
		cout << "\nEnter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			A.WriteRec();
			break;
		case 2:
			A.ReadRec();
			break;
		case 3:
			A.SearchRec();
			break;
		case 4:
			A.EditRec();
			break;
		case 5:
			A.DeleteRec();
			break;
		case 6:
			exit(0);
			break;
		default:
			cout << "\nEnter corret choice";
			exit(0);
		}
	}
	system("pause");
	return 0;
}

