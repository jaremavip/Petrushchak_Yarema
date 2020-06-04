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
	cout << "������ ����� ";
	cin >> num;
	loadU();
	usersData.erase(usersData.begin() + num);
	saveU();
	usersData.clear();
}

void admin::showAccounts()
{
	loadU();
	cout << setw(6) << "�����" << setw(18) << "��'� �����������" << endl;
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
	cout << setw(10) << "�����" << setw(20) << "��� �� ��������" << setw(8) << "ֳ��" << setw(40) << "������� ����������������" << setw(30) << "����� ��������" << setw(10) << "������" << setw(15) << "��'� �볺���" << endl;
	for (unsigned int i = 0; i < ordersData.size() - 1; i++)
	{
		cout << setw(10) << ordersData[i].orderNum << setw(17) << ordersData[i].timeToArrived << " ��" << setw(6) << ordersData[i].price << " ���" << setw(38) << ordersData[i].curDestination << setw(30) << ordersData[i].destination << setw(10) << ordersData[i].status << setw(15) << ordersData[i].customerName << endl;
	}
	ordersData.clear();
}
