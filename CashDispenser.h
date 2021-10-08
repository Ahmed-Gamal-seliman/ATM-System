#pragma once
class CashDispenser
{
public:
	CashDispenser();

	void dispenseCash(int);

	bool isSufficientCashAvailable(int) const;

private:
	static const int INITIAL_COUNT = 500;
	int count;
};

