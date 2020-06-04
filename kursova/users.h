#include "global.h"

class users
{
private:

public:
	std::vector <userInfo> usersData;
	users();
	~users();
	void saveU();
	void loadU();
};
