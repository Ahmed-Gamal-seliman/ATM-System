#include "Screen.h"

void Screen::displayMessage(std::string message) const {
	std::cout << message;
}

void Screen::dispalyMessageLine(std::string message) const {
	std::cout << message << std::endl;
}

void Screen::displayDollarAmount(double amount) const {
	std::cout << std::fixed << std::setprecision(2) << "$" <<amount<< std::endl;
}