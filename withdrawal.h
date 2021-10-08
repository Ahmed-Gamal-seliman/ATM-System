#pragma once

#include "Transaction.h"
#include "Screen.h"
#include "BankDatabase.h"
#include "Keypad.h"
#include "CashDispenser.h"

//class CashDispenser;
//class Keypad;

class withdrawal: public Transaction
{
private:
	double amount;
	CashDispenser& cashDispenser;
	Keypad& keypad;
	int displayMenuOfAmounts() const;
public:
	withdrawal(int, Screen&, BankDatabase&, Keypad&, CashDispenser&);
	virtual void execute() override;


};

