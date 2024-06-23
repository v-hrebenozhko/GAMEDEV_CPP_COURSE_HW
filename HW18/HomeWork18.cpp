#include "coffee_shop.h"
#include "Rectangle.h"
#include "Vector2d.h"



int main()
{
	const int CoffeeShopTables = 10;
	coffee_shop WakeCup("WakeCup", CoffeeShopTables);
	WakeCup.RunCoffeeShop();
}