#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>

using namespace std;

#define udiv ":"
#define div ";"

extern int curNum;

struct userInfo
{
	string username, password;
};

struct orderInfo
{
	int orderNum, timeToArrived, price;
	string customerName, destination, curDestination, status;
};

extern userInfo curUser;

#endif
