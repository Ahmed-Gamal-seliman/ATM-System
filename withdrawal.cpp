#include "withdrawal.h"
#include "Screen.h"
#include "BankDatabase.h"
#include "Keypad.h"
#include "CashDispenser.h"

static const int CANCELED = 6;

withdrawal::withdrawal(int userAccountNumber, Screen& atmScreen, BankDatabase& atmBankDatabase, Keypad& atmkeypad, CashDispenser& atmCashDispenser)
	: Transaction(userAccountNumber, atmScreen, atmBankDatabase) , keypad(atmkeypad), cashDispenser(atmCashDispenser)
{

}

void withdrawal::execute()
{
	bool cashDispensed = false;
	bool transactionCanceled = false;

	BankDatabase& bankDatabase = getBankDatabase();
	Screen& screen = getScreen();

	do {
		int selection = displayMenuOfAmounts();
		if (selection != CANCELED)
		{
			amount = selection;
			double availableBalance = bankDatabase.getAvailableBalance(getAccountNumber());

			if (amount <= availableBalance)
			{
				if (cashDispenser.isSufficientCashAvailable(amount))
				{
					bankDatabase.debit(getAccountNumber(), amount);

					cashDispenser.dispenseCash(amount);

					cashDispensed = true;

					screen.dispalyMessageLine("\nplease take your cash from the cash dispenser.");
				}//end if
				else
				{
					screen.dispalyMessageLine(
						"\nIn sufficient cash available in the ATM."
						"\n\nplease choose a smaller amount.");
				}
			}//end if
			else
			{
				screen.dispalyMessageLine("\nIn sufficient funds in your account." "\n\nplease choose a smaller amount.");
			}//end else

		}//end if
		else
		{
			screen.dispalyMessageLine("\nCanceling transaction...");
			transactionCanceled = true;
		}//end else


	} while (!cashDispensed && !transactionCanceled);
}//end function execute


int withdrawal::displayMenuOfAmounts() const
{
	int userChoice = 0;
	Screen& screen = getScreen();

	int amounts[] = { 0,20,40,60,100,200 };

	while (userChoice == 0)
	{
		screen.dispalyMessageLine("\nWithdrawal options:");
		screen.dispalyMessageLine("1 - $20");
		screen.dispalyMessageLine("2 - $40");
		screen.dispalyMessageLine("3 - $60");
		screen.dispalyMessageLine("4 - $100");
		screen.dispalyMessageLine("5 - $200");
		screen.dispalyMessageLine("6 - Cancel transaction");
		screen.dispalyMessageLine("\nChoose a withdrawal option (1-6): ");

		int input = keypad.getInput();

		switch (input)
		{
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
				userChoice = amounts[input];
				break;
			case CANCELED:
				userChoice = CANCELED;
				break;
			default:
				screen.dispalyMessageLine(
					"\nInvalid selection. Try again");

		}//end switch
	}//end while
	return userChoice;
}

	 