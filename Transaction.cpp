#include "Transaction.h"

Transaction::Transaction(int userAccountNumber, Screen& atmScreen, BankDatabase& atmBankDatabase)
	: accountNumber(userAccountNumber), screen(atmScreen), bankDatabase(atmBankDatabase)
{

}


int Transaction::getAccountNumber() const
{
	return accountNumber;
}

Screen& Transaction::getScreen() const
{
	return screen;
}

BankDatabase& Transaction::getBankDatabase() const
{
	return bankDatabase;
}


Transaction::~Transaction()
{

}

