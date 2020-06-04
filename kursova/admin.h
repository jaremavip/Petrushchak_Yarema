#include "users.h"
#include "taxi.h"

class admin : public users, public taxi
{
public:
	admin();
	~admin();
	void delUser();
	void getAllStat();
	void save();
	void showAccounts();
};
