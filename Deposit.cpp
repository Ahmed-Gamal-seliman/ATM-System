#include "Deposit.h"


static const int CANCELED = 0;


Deposit::Deposit(int userAccountNumber, Screen& atmScreen, BankDatabase& atmBankDatabase, Keypad& atmkeypad, DepositSlot& atmDepositSlot)
	: Transaction(userAccountNumber, atmScreen, atmBankDatabase), keypad(atmkeypad), depositSlot(atmDepositSlot)
{

}

void Deposit::execute()
{
	BankDatabase& bankDatabase = getBankDatabase();

	Screen& screen = getScreen();

	amount = promptForDepositAmount();

	if (amount != CANCELED)
	{
		screen.displayMessage(
			"\nPlease insert a deposit envelope containing ");
		screen.displayDollarAmount(amount);
		screen.dispalyMessageLine(" in the deposit slot.");

		bool envelopeReceived = depositSlot.isEnvelopeReceived();

		if (envelopeReceived)
		{
			screen.dispalyMessageLine("\nYour envelope has been received."
				"\nNOTE: The money deposited will not be available until we"
				"\nverify the amount of any enclosed cash, and any enclosed"
				"checks clear.");

			bankDatabase.credit(getAccountNumber(), amount);
		}//end if
		else
		{
			screen.dispalyMessageLine("\nYou did not insert an"
				"envelope, so the ATM has canceled your transaction.");
		}//end else
	}//end if

	else
	{
		screen.dispalyMessageLine("\nCanceling transaction...");
	}//end else
}//end function execute


double Deposit::promptForDepositAmount() const
{
	Screen& screen = getScreen();

	screen.displayMessage("\nPlease enter a deposit amount in"
		"CENTS (or 0 to cancel): ");

	int input = keypad.getInput();

	if (input == CANCELED)
		return CANCELED;
	else
	{
		return static_cast<double>(input) / 100;
	}//end else
}//end function promptForDepositAmount