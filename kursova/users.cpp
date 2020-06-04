#include "users.h"
#include "taxi.h"
#include "func.h"

using namespace std;

userInfo curUser;

users::users()
{
}

users::~users()
{
}

void users::saveU()
{
	ofstream file("users.txt");
	for (unsigned int i = 0; i < usersData.size() - 1; i++)
	{
		file << usersData[i].username << udiv << usersData[i].password << endl;
	}
	file.close();
}

void users::loadU()
{
	int i = 0;
	usersData.clear();
	string temp;
	vector <string> buff;
	ifstream file("users.txt");
	while (file.eof() != 1)
	{
		file >> temp;
		buff = split(temp, udiv);
		usersData.resize(usersData.size() + 1);
		usersData[i].username = buff[0];
		usersData[i].password = buff[1];
		i++;
	}
};
