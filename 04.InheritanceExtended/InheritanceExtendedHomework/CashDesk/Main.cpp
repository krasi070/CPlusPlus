#include <iostream>
#include <string>
#include <iomanip>

class Item
{
public:
	Item() {}
	Item(const Item &item)
	{
		this->price = item.price;
	}

	Item(std::string id, float price) : id(id), price(price) {}
	float price;
	friend std::string getItemPriceById(Item inventory[], int length, std::string id);
	friend bool idExists(Item inventory[], int length, std::string id);
	friend void changeItemPrice(Item inventory[], int length, std::string id, double newPrice);
private:
	std::string id;
};

class Purchase
{
public:
	Purchase() {}
	Purchase(double totalValue, double givenMoney, double change) :
		totalValue(totalValue), givenMoney(givenMoney), change(change)
	{
	}

	double totalValue;
	double givenMoney;
	double change;
};

std::string getItemPriceById(Item inventory[], int length, std::string id);
void changeItemPrice(Item inventory[], int length, std::string id, double newPrice);
Purchase executeTransaction(double totalValue);
bool idExists(Item inventory[], int length, std::string id);
std::string enterItemId();

int main()
{
	double totalValue = 0;
	Item inventory[100];
	int inventoryLength = 5;
	inventory[0] = Item("0000000001", 12);
	inventory[1] = Item("0000000002", 100);
	inventory[2] = Item("0000000003", 1);
	inventory[3] = Item("0123456789", 12.99);
	inventory[4] = Item("9876543210", 49.99);
	Purchase purchases[100];
	int purchasesLength = 0;
	while (true)
	{
		std::cout << "POSSIBLE COMMANDS:" << std::endl << 
			"--Enter 10-digit ID to add item price--" << std::endl <<
			"--Enter C to clear the total value--" << std::endl <<
			"--Enter T to display the total value--" << std::endl <<
			"--Enter G to execute transaction--" << std::endl <<
			"--Enter P to change item price--" << std::endl <<
			"--Enter I to display customer info--" << std::endl << 
			"--Enter E to exit program--" << std::endl << ">";

		std::string input;
		getline(std::cin, input);
		system("cls");
		Purchase purchase;
		std::string id;
		if (input.length() == 1)
		{
			switch (input[0])
			{
			case 'C':
			case 'c':
				totalValue = 0;
				std::cout << "Total value cleared!" << std::endl;
				break;
			case 'T':
			case 't':
				std::cout << std::fixed << std::setprecision(2) << "Total value: " << totalValue << " leva" << std::endl;
				break;
			case 'G':
			case 'g':
				if (totalValue > 0)
				{
					purchase = executeTransaction(totalValue);
					totalValue = 0;
					purchases[purchasesLength] = purchase;
					purchasesLength++;
				}
				else
				{
					std::cout << "Nothing has been bought yet." << std::endl;
				}
				break;
			case 'P':
			case 'p':
				id = enterItemId();
				if (idExists(inventory, inventoryLength, id))
				{
					std::cout << "Enter new price: ";
					double newPrice;
					std::cin >> newPrice;
					std::cin.ignore();
					changeItemPrice(inventory, inventoryLength, id, newPrice);
				}
				else
				{
					std::cout << "Item not found!" << std::endl;
				}
				break;
			case 'I':
			case 'i':
				if (purchasesLength > 0)
				{
					std::cout << std::fixed << std::setprecision(2) << 
						"CandyShop" << std::endl <<
						"BIC: 12345678" << std::endl <<
						"Address: idk" << std::endl <<
						"Purchases: " << purchases[purchasesLength - 1].totalValue << " leva" << std::endl <<
						"Given: " << purchases[purchasesLength - 1].givenMoney << " leva" << std::endl <<
						"Change: " << purchases[purchasesLength - 1].change << " leva" << std::endl;
				}
				else
				{
					std::cout << "No purchases have been made yet." << std::endl;
				}
				break;
			case 'E':
			case 'e':
				return 0;
				break;
			default:
				continue;
				break;
			}
		}
		else if (input.length() == 10)
		{
			std::string price = getItemPriceById(inventory, inventoryLength, input);
			if (price != "")
			{
				totalValue += std::stod(price);
				std::cout << std::fixed << std::setprecision(2) << "Price: " << std::stod(price) << " leva" << std::endl;
			}
			else
			{
				std::cout << "Item not found!" << std::endl;
			}
		}

		std::cout << "PRESS ANY KEY TO CONTINUE";
		std::cin.ignore();
		system("cls");
	}

	return 0;
}

void changeItemPrice(Item inventory[], int length, std::string id, double newPrice)
{
	for (int i = 0; i < length; i++)
	{
		if (inventory[i].id == id)
		{
			inventory[i].price = newPrice;
		}
	}
}

std::string getItemPriceById(Item inventory[], int length, std::string id)
{
	for (int i = 0; i < length; i++)
	{
		if (inventory[i].id == id)
		{
			return std::to_string(inventory[i].price);
		}
	}

	return "";
}

Purchase executeTransaction(double totalValue)
{
	std::cout << "Please enter the given amount of money: ";
	double givenMoney;
	std::cin >> givenMoney;
	std::cin.ignore();
	while (givenMoney < totalValue)
	{
		std::cout << "Not enough money!" << std::endl;
		std::cout << "Please enter the given amount of money: ";
		std::cin >> givenMoney;
		std::cin.ignore();
	}

	double change = givenMoney - totalValue;
	std::cout << std::fixed << std::setprecision(2) << "Change: " << change << std::endl;

	return Purchase(totalValue, givenMoney, change);
}

bool idExists(Item inventory[], int length, std::string id)
{
	for (int i = 0; i < length; i++)
	{
		if (inventory[i].id == id)
		{
			return true;
		}
	}

	return false;
}

std::string enterItemId()
{
	std::cout << "Enter item ID: ";
	std::string id;
	getline(std::cin, id);
	while (id.length() != 10)
	{
		std::cout << "ID must be 10-digit long! Enter item ID: ";
		getline(std::cin, id);
	}

	return id;
}