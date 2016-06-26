#include <iostream>

class BankAccount
{
public:
	double balance;
};

class Person
{
public:
	BankAccount bankAccount;
};

class MoneyCollector : private Person
{
public:
	MoneyCollector()
	{
		this->bankAccount.balance = 0;
	}

	friend class MoneyWaster;
	friend void addMoneyToCard(double amount, MoneyCollector &moneyCollector);
};

class MoneyWaster : private Person
{
public:
	MoneyWaster() {}
	MoneyWaster &operator=(MoneyCollector &moneyCollector)
	{
		this->bankAccount.balance = moneyCollector.bankAccount.balance;
		moneyCollector.bankAccount.balance = 0;

		return *this;
	}

	void wasteMoney();
};

void MoneyWaster::wasteMoney()
{
	this->bankAccount.balance = 0;
}

void addMoneyToCard(double amount, MoneyCollector &moneyCollector)
{
	moneyCollector.bankAccount.balance += amount;
}

int main()
{
	MoneyCollector ragnaTheBloodedge = MoneyCollector();
	addMoneyToCard(200, ragnaTheBloodedge);

	MoneyWaster taokaka = MoneyWaster();
	taokaka = ragnaTheBloodedge;
	taokaka.wasteMoney();

	return 0;
}