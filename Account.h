#pragma once
class Account
{
private:
	int accountNumber;
	int pin;
	double availableBalance;
	double totalBalance;

public:
	Account(int, int, double, double);
	bool validatePin(int) const;
	double getAvailableBalance() const;
	double getTotalBalance() const;
	void credit(double);//adds an amount of money to an Account as part of a deposit transaction adds the amount only to data member totalBalance
	void debit(double);
	int getAccountNumber() const;
};

