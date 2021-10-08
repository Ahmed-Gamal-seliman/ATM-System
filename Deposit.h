#pragma once

#include "Transaction.h"
#include "Deposit.h" // Deposit class definition
#include "Screen.h" // Screen class definition
#include "BankDatabase.h" // BankDatabase class definition
#include "Keypad.h"
#include "DepositSlot.h"

//class Keypad;
//class DepositSlot;

class Deposit:public Transaction
{
public:
	Deposit(int, Screen&, BankDatabase&, Keypad&, DepositSlot&);
	virtual void execute();

private:
	double amount;
	Keypad& keypad;
	DepositSlot& depositSlot;
	double promptForDepositAmount() const;

};

