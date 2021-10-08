#pragma once
#include "DepositSlot.h"
#include "Screen.h"
#include "Keypad.h"
#include "CashDispenser.h"
#include "BankDatabase.h"
#include "BalanceInquiry.h"
#include "withdrawal.h"
#include "Deposit.h"
#include "Transaction.h"
class Transaction;

class ATM
{
private:
	bool userAuthenticated;
	int currentAccountNumber;
	Screen screen;
	DepositSlot depositSlot;
	Keypad keypad;
	CashDispenser cashDispenser;
	BankDatabase bankDatabase;

	void authenticateUser();
	void perfromTransactions();
	int displayMainMenu() const;

	Transaction* createTransaction(int);
public:
	ATM();
	void Run();
};

