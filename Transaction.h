#pragma once

class Screen;
class BankDatabase;

class Transaction
{
private:
	int accountNumber;
	Screen& screen;
	BankDatabase& bankDatabase;
public:
	Transaction(int, Screen&, BankDatabase&);

	 int getAccountNumber() const;
	 Screen& getScreen() const;
	 BankDatabase& getBankDatabase() const;
	 
	 virtual void execute() = 0;

	virtual ~Transaction();
};

