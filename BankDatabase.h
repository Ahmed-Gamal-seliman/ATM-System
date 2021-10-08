#pragma once

#include "Account.h"
#include <vector>

class BankDatabase
{
public:
	BankDatabase();

	bool authenticateUser(int, int);
	double getAvailableBalance(int);
	double getTotalBalance(int);
	void credit(int, double);
	void debit(int, double);

private:
	std::vector<Account> accounts;

	Account* getAccount(int);


};

