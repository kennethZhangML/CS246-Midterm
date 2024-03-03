#include <iomanip>
#include <iostream>

int main() {

	int num;
	std::cout << "Enter an integer: " << std::endl;
	std::cin >> num;

	// Using setbase()
	std::cout << "Decimal: " << std::dec << num << std::endl;
	std::cout << "Hexadecimal: " << std::hex << num << std::endl;
	std::cout << "Octal: " << std::oct << num << std::endl;
	std::cout << std::endl;
	std::cout << "Using setfill() and setw()" << std::endl;
	std::cout << std::setw(10) << std::setfill('*') << num << std::endl;
	std::cout << std::setw(10) << std::setfill('#') << std::hex << num << std::endl;
    std::cout << std::setw(10) << std::setfill('@') << std::oct << num << std::endl;

    return 0;
}