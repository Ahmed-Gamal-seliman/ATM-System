#include "BalanceInquiry.h"
//	BalanceInquiry(int, Screen&, BankDatabase&);
//Transaction(int userAccountNumber, Screen& atmScreen, BankDatabase& atmBankDatabase)
BalanceInquiry::BalanceInquiry(int userAccountNumber, Screen& atmScreen, BankDatabase& atmBankDatabase)
	: Transaction(userAccountNumber, atmScreen, atmBankDatabase)
{

}

void BalanceInquiry::execute()
{
	BankDatabase& bankDatabase = getBankDatabase();
	Screen& screen = getScreen();
	double availableBalance = bankDatabase.getAvailableBalance(getAccountNumber());
	double totalBalance = bankDatabase.getTotalBalance(getAccountNumber());


	screen.dispalyMessageLine("\nBalance Information:");
	screen.displayMessage(" - Available balance: ");
	screen.displayDollarAmount(availableBalance);
	screen.displayMessage("\n - Total balance: ");
	screen.displayDollarAmount(totalBalance);
	screen.dispalyMessageLine("");

}

