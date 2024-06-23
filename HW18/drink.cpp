#include "drink.h"


int drink::GetCost() const
{
	return m_Cost;
}

std::string drink::GetName() const
{
	return m_Name;
}

void black_tea::Prepare()
{
	std::cout
		<< "Heating fresh water to a rolling boil 100°C." << std::endl
		<< "Swirling boiling water in the tea cup." << std::endl
		<< "Placing tea leaves in the tea cup." << std::endl
		<< "Pouring boiling water over the tea." << std::endl
		<< "Steeping for 3-5 minutes." << std::endl
		<< "Removing the tea leaves." << std::endl;
}

black_tea::black_tea(drink_size DrinkSize)
{
	m_DrinkSize = DrinkSize;
	if (m_DrinkSize == drink_size::M)
	{
		m_Cost = 25;
		m_Name = "medium size black tea";
	}
	else if (m_DrinkSize == drink_size::L)
	{
		m_Cost = 35;
		m_Name = "large size black tea";
	}


}

void green_tea::Prepare()
{
	std::cout
		<< "Heating fresh water to a rolling boil 80-85°C." << std::endl
		<< "Swirling boiling water in the tea cup." << std::endl
		<< "Placing tea leaves in the tea cup." << std::endl
		<< "Pouring boiling water over the tea." << std::endl
		<< "Steeping for 2-3 minutes." << std::endl
		<< "Removing the tea leaves." << std::endl;
}

green_tea::green_tea(drink_size DrinkSize)
{
	m_DrinkSize = DrinkSize;
	if (m_DrinkSize == drink_size::M)
	{
		m_Cost = 25;
		m_Name = "medium size green tea";
	}
	else if (m_DrinkSize == drink_size::L)
	{
		m_Cost = 35;
		m_Name = "large size green tea";
	}
}

void espresso::Prepare()
{
	std::cout
		<< "Grinding coffee, ensuring the espresso machine is preheated." << std::endl
		<< "Placing ground coffee into the portafilter." << std::endl
		<< "Tamping the coffee evenly with firm pressure." << std::endl
		<< "Inserting and locking the portafilter into the machine." << std::endl
		<< "Starting the extraction process." << std::endl
		<< "Pouring the espresso into a pre-warmed cup." << std::endl;
}

espresso::espresso()
{
	m_Cost = 25;
	m_DrinkSize = drink_size::S;
	m_Name = "espresso";
}

void americano::Prepare()
{
	std::cout
		<< "Making a single shot of espresso." << std::endl
		<< "Heating water to near boiling." << std::endl
		<< "Pouring hot water into the cup with the espresso." << std::endl
		<< "Stiring gently" << std::endl;
}

americano::americano(drink_size DrinkSize)
{
	m_DrinkSize = DrinkSize;
	if (m_DrinkSize == drink_size::M)
	{
		m_Cost = 30;
		m_Name = "medium size americano";
	}
	else if (m_DrinkSize == drink_size::L)
	{
		m_Cost = 40;
		m_Name = "large size americano";
	}
}

void cappuccino::Prepare()
{
	std::cout
		<< "Making a single shot of espresso."
		<< "Steaming milk until it's frothy and reaches about 65°C."
		<< "Pouring the steamed milk into the cup with the espresso, holding back the foam with a spoon."
		<< "Spooning a small amount of milk foam on top." << std::endl;
}

cappuccino::cappuccino(drink_size DrinkSize)
{
	m_DrinkSize = DrinkSize;
	if (m_DrinkSize == drink_size::M)
	{
		m_Cost = 40;
		m_Name = "medium size cappuccino";
	}
	else if (m_DrinkSize == drink_size::L)
	{
		m_Cost = 60;
		m_Name = "large size cappucino";
	}
}

void latte::Prepare()
{
	std::cout
		<< "Making a single shot of espresso." << std::endl
		<< "Steaming milk until it's frothy and reaches about 65°C." << std::endl
		<< "Pouring the steamed milk into the cup with the espresso, holding back the foam with a spoon." << std::endl
		<< "Spooning a small amount of milk foam on top." << std::endl;
}

latte::latte(drink_size DrinkSize)
{
	m_DrinkSize = DrinkSize;
	if (m_DrinkSize == drink_size::M)
	{
		m_Cost = 40;
		m_Name = "medium size latte";
	}
	else if (m_DrinkSize == drink_size::L)
	{
		m_Cost = 60;
		m_Name = "large size latte";
	}
	else if (m_DrinkSize == drink_size::XL)
	{
		m_Cost = 75;
		m_Name = "extra large size latte";
	}
}

drink_type ChoseType()
{
	int CustomerChoice;
	std::cout << "Hello, what would you like coffee or tea?" << std::endl;
	std::cout << "Enter the corresponding number: 1 - coffee, 2 - tea." << std::endl;
	std::cin >> CustomerChoice;
	if (CustomerChoice == 1)
	{
		std::cout
			<< "Here are the coffee types we have:" << std::endl
			<< "1 - Espresso 2 - Americano 3 - Latte 4 - Cappuccino" << std::endl
			<< "Please enter corresponding number: ";
		std::cin >> CustomerChoice;
		CustomerChoice += 1;
		if ((drink_type)CustomerChoice > drink_type::GreenTea && (drink_type)CustomerChoice <= drink_type::Latte)
		{
			return (drink_type)CustomerChoice;
		}
		else
		{
			return drink_type::InvalidType;
		}
	}
	else if (CustomerChoice == 2)
	{
		std::cout
			<< "Here are the tea types we have:" << std::endl
			<< "1 - BlackTea 2 - GreenTea" << std::endl
			<< "Please enter corresponding number: ";
		std::cin >> CustomerChoice;
		CustomerChoice -= 1;
		if ((drink_type)CustomerChoice < drink_type::Espresso)
		{
			return (drink_type)CustomerChoice;
		}
		else
		{
			return drink_type::InvalidType;
		}
	}
	else
	{
		return drink_type::InvalidType;
	}

}

drink_size ChoseSize(drink_type DrinkType)
{
	int DrinkSize;
	switch (DrinkType)
	{
	case drink_type::Americano:
	{
		std::cout 
			<< "What size would you like ?" << std::endl
			<< "1 - M 2 - L" << std::endl
			<< "Please enter corresponding number: ";
		break;
	}
	case drink_type::BlackTea:
	{
		std::cout
			<< "What size would you like ?" << std::endl
			<< "1 - M 2 - L" << std::endl
			<< "Please enter corresponding number: ";
		break;
	}
	case drink_type::GreenTea:
	{
		std::cout
			<< "What size would you like ?" << std::endl
			<< "1 - M 2 - L" << std::endl
			<< "Please enter corresponding number: ";
		break;
	}
	case drink_type::Latte:
	{
		std::cout
			<< "What size would you like ?" << std::endl
			<< "1 - M 2 - L 3 - XL" << std::endl
			<< "Please enter corresponding number: ";
		break;
	}
	case drink_type::Cappuccino:
	{
		std::cout
			<< "What size would you like ?" << std::endl
			<< "1 - M 2 - L" << std::endl
			<< "Please enter corresponding number: ";
		break;
	}
	case drink_type::Espresso:
	{
		return drink_size::S;
	}
	}
	std::cin >> DrinkSize;
	return (drink_size)DrinkSize;
}

drink* CreateDrink(drink_type DrinkType)

{
	if (DrinkType == drink_type::InvalidType)
	{
		return nullptr;
	}
	drink* NewDrink = nullptr;
	drink_size DrinkSize = ChoseSize(DrinkType);
	switch (DrinkType)
	{
	case drink_type::Americano:
	{
		if (DrinkSize == drink_size::M || DrinkSize == drink_size::L)
		{
			NewDrink = new americano(DrinkSize);
		}
		else
		{
			std::cout << "Please chose valid size!" << std::endl;
		}
		break;
	}
	case drink_type::BlackTea:
	{
		if (DrinkSize == drink_size::M || DrinkSize == drink_size::L)
		{
			NewDrink = new black_tea(DrinkSize);
		}
		else
		{
			std::cout << "Please chose valid size!" << std::endl;
		}
		break;
	}
	case drink_type::GreenTea:
	{
		if (DrinkSize == drink_size::M || DrinkSize == drink_size::L)
		{
			NewDrink = new green_tea(DrinkSize);
		}
		else
		{
			std::cout << "Please chose valid size!" << std::endl;
		}
		break;
	}
	case drink_type::Cappuccino:
	{
		if (DrinkSize == drink_size::M || DrinkSize == drink_size::L)
		{
			NewDrink = new cappuccino(DrinkSize);
		}
		else
		{
			std::cout << "Please chose valid size!" << std::endl;
		}
		break;
	}
	case drink_type::Espresso:
	{
		NewDrink = new espresso();
		break;
	}
	case drink_type::Latte:
	{
		if (DrinkSize == drink_size::M || DrinkSize == drink_size::L || DrinkSize == drink_size::XL)
		{
			NewDrink = new latte(DrinkSize);
		}
		else
		{
			std::cout << "Please chose valid size!" << std::endl;
		}
		break;
	}
	default:
	{
		std::cout << "Invalid drink type!" << std::endl;
		return nullptr;
	}
	}
	return NewDrink;
}


