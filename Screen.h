#pragma once

#include <string>
#include <iomanip>
#include <iostream>
class Screen
{
public:
	void displayMessage(std::string) const;
	void dispalyMessageLine(std::string) const;
	void displayDollarAmount(double) const;
};

