#include "global.h"

class taxi
{
private:

public:
	std::vector <orderInfo> ordersData;
	std::vector <orderInfo> curUserOrders;
	taxi();
	~taxi();
	void call();
	void getStat();
	void load();
	void save();
	void cancel();
	void sort();
};
