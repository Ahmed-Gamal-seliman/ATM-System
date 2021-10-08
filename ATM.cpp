#include "ATM.h"

enum MenuOption {BALANCE_INQUIRY=1, WITHDRAWAL, DEPOSIT, EXIT};


ATM::ATM(): userAuthenticated(false),
			currentAccountNumber(0)
{
	
}

void ATM::Run() {
	while (true) {
		while (!userAuthenticated)
		{
			screen.dispalyMessageLine("\nWelcome!");
			authenticateUser();
		}//end while
		
		perfromTransactions();
		userAuthenticated = false;
		currentAccountNumber = 0;
		screen.dispalyMessageLine("\nThank you! Goodbye!");

	}//end while
}//end function run

void ATM::authenticateUser() {
	screen.displayMessage("\nplease enter your account number: ");
	int accountNumber = keypad.getInput();

	screen.displayMessage("\nEnter you PIN: ");
	int pin = keypad.getInput();

	userAuthenticated = bankDatabase.authenticateUser(accountNumber, pin);

	if (userAuthenticated)
	{
		currentAccountNumber = accountNumber;
	}
	else
		screen.dispalyMessageLine("Invalid account number or PIN. please try again.");

}

void ATM::perfromTransactions() {
	Transaction* currentTransactionPtr;

	bool userExited = false;

	while (!userExited)

	{
		int mainMenuSelection = displayMainMenu();

		switch (mainMenuSelection)
		{
		case BALANCE_INQUIRY:
		case WITHDRAWAL:
		case DEPOSIT:

			currentTransactionPtr = createTransaction(mainMenuSelection);
			
			currentTransactionPtr->execute();

			delete currentTransactionPtr;

			break;

		case EXIT:
			screen.dispalyMessageLine("\nExiting the system...");
			userExited = true;
			break;
			
		default:
			screen.dispalyMessageLine("\nyou did not enter a valid selection. Try again.");
			break;
		
		}//end switch

	}//end while
}//end function performTransactions


int ATM::displayMainMenu() const{
	screen.dispalyMessageLine("\nMainMenu:");
	screen.dispalyMessageLine("1- view my balance");
	screen.dispalyMessageLine("2- withdraw cash");
	screen.dispalyMessageLine("3- Deposit funds");
	screen.dispalyMessageLine("4- Exit\n");
	screen.dispalyMessageLine("Enter a choice: ");
	return keypad.getInput();
}// end function displayMainMenu


Transaction* ATM::createTransaction(int type)
{
	Transaction* tempPtr{ NULL };

	switch (type)
	{//(currentAccountNumber, keypad, cashDispenser)
	case BALANCE_INQUIRY:
		tempPtr = new BalanceInquiry(currentAccountNumber, screen, bankDatabase);
		break;

	case WITHDRAWAL:
		tempPtr = new withdrawal(currentAccountNumber, screen, bankDatabase, keypad, cashDispenser);
		break;

	case DEPOSIT:
		tempPtr = new Deposit(currentAccountNumber, screen, bankDatabase, keypad, depositSlot);
		break;
	}//end type
	
	if(tempPtr != NULL)
		return tempPtr;
	return NULL;
	
}//end function createTransaction