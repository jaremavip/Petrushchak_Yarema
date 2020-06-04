#include "output.h"



output::output()
{
}


output::~output()
{
}


void output::auth()
{
	userInfo authUser;
	bool correct = 0;
	cout << "������ ��'� �����������: ";
	cin >> authUser.username;
	cout << "������ ������: ";
	cin >> authUser.password;
	loadU();
	for (unsigned int i = 0; i < usersData.size(); i++)
	{
		if (usersData[i].username == authUser.username && usersData[i].password == authUser.password)
		{
			curUser.username = usersData[i].username;
			curUser.password = usersData[i].password;
			correct = 1;
			menu();
			break;
		}
	}
	if (correct == 0)
	{
		cout << "����������� ��'� ����������� ��� ������";
		mainMenu();
	}
	usersData.clear();
	menu();
};

void output::menu()
{
	taxi taxiOr;
	cout << endl << "������� ��:" << endl;
	cout << "1. ��������� ����" << endl;
	cout << "2. ����������� ������ �������" << endl;
	cout << "3. ��������� ������" << endl;
	if (curUser.username == "admin")
	{
		cout << "4. ����������� �������" << endl;
		cout << "5. �������� ������" << endl;
		cout << "6. ����������� �� �������" << endl;
	}
	cout << "7. �����" << endl;
	int ch;
	cin >> ch;
	if (curUser.username != "admin" && ch > 3 && ch < 7)
	{
		ch = 0;
	}
	switch (ch)
	{
	case 1:
	{
		taxiOr.call();
		menu();
	}
	case 2:
	{
		taxiOr.getStat();
		break;
	}
	case 3:
	{
		taxiOr.cancel();
		break;
	}
	case 4:
	{
		showAccounts();
		break;
	}
	case 5:
	{
		delUser();
		break;
	}
	case 6:
	{
		getAllStat();
		menu();
		break;
	}
	case 7:
	{
		mainMenu();
		break;
	}
	default:
		menu();
	}
};

void output::mainMenu()
{
	cout << endl << "������� ��:" << endl;
	cout << "1. ����� � ������" << endl;
	cout << "2. ��������������" << endl;
	cout << "3. �����" << endl;
	int ch;
	cin >> ch;
	switch (ch)
	{
	case 1:
	{
		auth();
		break;
	}
	case 2:
	{
		newUser();
		break;
	}
	case 3:
	{
		exit(0);
		break;
	}
	default:
		mainMenu();
	}
}

void output::newUser()
{
	userInfo addUser;
	cout << "������ ��'� �����������: ";
	cin >> addUser.username;
	cout << "���������� ������: ";
	cin >> addUser.password;
	ofstream file("users.txt", ios_base::app);
	file << addUser.username << udiv << addUser.password << endl;
	file.close();
	mainMenu();
};
