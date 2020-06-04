#include "admin.h"



admin::admin()
{
}


admin::~admin()
{
}


void admin::delUser()
{
	unsigned int num;
	showAccounts();
	cout << "Введіть номер ";
	cin >> num;
	loadU();
	usersData.erase(usersData.begin() + num);
	saveU();
	usersData.clear();
}

void admin::showAccounts()
{
	loadU();
	cout << setw(6) << "Номер" << setw(18) << "Ім'я користувача" << endl;
	for (unsigned int i = 0; i < usersData.size() - 1; i++)
	{
		cout << i << " " << usersData[i].username << endl;
	}
	usersData.clear();
}

void admin::getAllStat()
{
	load();
	unsigned int j = 0;
	cout << setw(10) << "Номер" << setw(20) << "Час до прибуття" << setw(8) << "Ціна" << setw(40) << "Поточне місцерозташування" << setw(30) << "Пункт прибуття" << setw(10) << "Статус" << setw(15) << "Ім'я клієнта" << endl;
	for (unsigned int i = 0; i < ordersData.size() - 1; i++)
	{
		cout << setw(10) << ordersData[i].orderNum << setw(17) << ordersData[i].timeToArrived << " хв" << setw(6) << ordersData[i].price << " грн" << setw(38) << ordersData[i].curDestination << setw(30) << ordersData[i].destination << setw(10) << ordersData[i].status << setw(15) << ordersData[i].customerName << endl;
	}
	ordersData.clear();
}
