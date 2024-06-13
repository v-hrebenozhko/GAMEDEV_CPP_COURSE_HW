#include "Coffee.h"
#include "Rectangle.h"

int main()
{
	const int CoffeeShopTables = 30;
	coffee_shop CoffeeShop("WakeCup",CoffeeShopTables);
	int Customers[CoffeeShopTables];

	for (int i = 0; i < 30; i++)
	{
		Customers[i] = CoffeeShop.TakePlace();
	}

	CoffeeShop.Order(Customers[5]);
	CoffeeShop.Prepare(Customers[5]);
	CoffeeShop.GetReceipt(Customers[5]);

	CoffeeShop.Prepare(Customers[4]);
	CoffeeShop.GetReceipt(Customers[4]);

	int Table = CoffeeShop.TakePlace();
	CoffeeShop.Order(Table);
	CoffeeShop.Prepare(Table);
	CoffeeShop.GetReceipt(Table);
}