#include "taxi.h"
#include "func.h"

using namespace std;

int curNum = 0;

taxi::taxi()
{
	ifstream file("curNum.txt");
	string temp;
	file >> temp;
	curNum = stoi(temp);
	file.close();
}

taxi::~taxi()
{
}

void taxi::call()
{
	orderInfo newOrder;
	newOrder.orderNum = curNum;
	newOrder.status = "Wait";
	newOrder.price = rand() % (99 - 10 + 1) + 10;
	newOrder.timeToArrived = newOrder.price * 1.3;
	cout << "Введіть ваше місцерозташування: ";
	cin >> newOrder.curDestination;
	cout << "Введіть пункт прибуття: ";
	cin >> newOrder.destination;
	newOrder.customerName = curUser.username;
	ofstream file("orders.txt", ios_base::app);
	file << newOrder.orderNum << div << newOrder.timeToArrived << div << newOrder.price << div << newOrder.curDestination << div << newOrder.destination << div << newOrder.customerName << div << newOrder.status << endl;
	file.close();
	curNum++;
	ofstream fileNum("curNum.txt");
	fileNum << curNum;
	fileNum.close();
}

void taxi::getStat()
{
	load();
	locale::global(locale(""));
	unsigned int j = 0;
	for (unsigned int i = 0; i < ordersData.size(); i++)
	{
		if (ordersData[i].customerName == curUser.username)
		{
			curUserOrders.resize(curUserOrders.size() + 1);
			curUserOrders[j] = ordersData[i];
			j++;
		}
	}
	cout << setw(10) << "Номер" << setw(20) << "Час до прибуття" << setw(8) << "Ціна" << setw(40) << "Поточне місцерозташування" << setw(30) << "Пункт прибуття" << setw(10) << "Статус" << endl;
	for (unsigned int i = 0; i < curUserOrders.size() - 1; i++)
	{
		cout << setw(10) << curUserOrders[i].orderNum << setw(17) << curUserOrders[i].timeToArrived << " хв" << setw(6) << curUserOrders[i].price << " грн" << setw(38) << curUserOrders[i].curDestination << setw(30) << curUserOrders[i].destination << setw(10) << curUserOrders[i].status << endl;
	}
	curUserOrders.clear();
	ordersData.clear();
}

void taxi::load()
{
	int i = 0;
	ordersData.clear();
	string temp;
	vector <string> buff;
	ifstream file("orders.txt");
	while (file.eof() != 1)
	{
		file >> temp;
		buff = split(temp, div);
		ordersData.resize(ordersData.size() + 1);
		ordersData[i].orderNum = stoi(buff[0]);
		ordersData[i].timeToArrived = stoi(buff[1]);
		ordersData[i].price = stoi(buff[2]);
		ordersData[i].curDestination = buff[3];
		ordersData[i].destination = buff[4];
		ordersData[i].customerName = buff[5];
		ordersData[i].status = buff[6];
		i++;
	}
}

void taxi::save()
{
	ofstream file("orders.txt");
	for (unsigned int i = 0; i < ordersData.size() - 1; i++)
	{
		file << ordersData[i].orderNum << div << ordersData[i].timeToArrived << div << ordersData[i].price << div << ordersData[i].curDestination << div << ordersData[i].destination << div << ordersData[i].customerName << div << ordersData[i].status << endl;
	}
	file.close();
}

void taxi::cancel()
{
	unsigned int num;
	getStat();
	cout << "Введіть номер виклику ";
	cin >> num;
	load();
	for (unsigned int i = 0; i < ordersData.size(); i++)
	{
		if (ordersData[i].orderNum == num)
		{
			ordersData.erase(ordersData.begin() + i);
			save();
		}
	}
	ordersData.clear();
	sort();
}

void taxi::sort()
{
	load();
	unsigned int i;
	for (i = 0; i < ordersData.size(); i++)
	{
		ordersData[i].orderNum = i;
	}
	save();
	ofstream fileNum("curNum.txt");
	curNum = i - 1;
	fileNum << i - 1;
	fileNum.close();
	ordersData.clear();
}
