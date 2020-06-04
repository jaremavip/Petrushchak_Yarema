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
	cout << "Введіть ім'я користувача: ";
	cin >> authUser.username;
	cout << "Введіть пароль: ";
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
		cout << "Неправильне ім'я користувача або пароль";
		mainMenu();
	}
	usersData.clear();
	menu();
};

void output::menu()
{
	taxi taxiOr;
	cout << endl << "Виберіть дію:" << endl;
	cout << "1. Викликати таксі" << endl;
	cout << "2. Переглянути статус виклику" << endl;
	cout << "3. Скасувати виклик" << endl;
	if (curUser.username == "admin")
	{
		cout << "4. Переглянути акаунти" << endl;
		cout << "5. Видалити акаунт" << endl;
		cout << "6. Переглянути усі виклики" << endl;
	}
	cout << "7. Назад" << endl;
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
	cout << endl << "Виберіть дію:" << endl;
	cout << "1. Увійти в акаунт" << endl;
	cout << "2. Зареєструватися" << endl;
	cout << "3. Вихід" << endl;
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
	cout << "Введіть ім'я користувача: ";
	cin >> addUser.username;
	cout << "Придумайте пароль: ";
	cin >> addUser.password;
	ofstream file("users.txt", ios_base::app);
	file << addUser.username << udiv << addUser.password << endl;
	file.close();
	mainMenu();
};
