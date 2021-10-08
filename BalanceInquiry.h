#pragma once

#include "Transaction.h"
#include "Screen.h"
#include "BankDatabase.h"

class BalanceInquiry: public Transaction
{
public:
	BalanceInquiry(int, Screen&, BankDatabase&);
	virtual void execute();

};

