#include <iostream>
#include <limits>
#include <sstream>

int main() {
	
	std::cout << "Enter a sentence: " << std::endl;

	// 1. cin.ignore() => ignore input until delimiter 
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Input ignored till newline delimiter;" << std::endl;

	// 2. cin.eof() => end of file reached -> stop reading in input 
	std::cout << "Enter integers: " << std::endl;
	int num;
	while (!std::cin.eof()) { 
		std::cin >> num;
		std::cout << "Read: " << num << std::endl;
	}

	// 3. Clear State Buffer of 
	std::cin.clear(); // Clear EOF Flag 

	std::cout << "Enter an integer: ";
	std::cin.clear(); // Clear EOF flag
	std::cin >> num;
	std::cout << "Input after clearing EOF flag: " << num << std::endl;
	// std::cin.reset();

	std::cout << "Enter a non-integer: " << std::endl;
	std::cin >> num;
	if (std::cin.fail()) { 
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Input failed. Clearing error flags." << std::endl;
	} else {
		std::cout << "Input successfull." << std::endl;
	}

	std::cin.clear();

	std::string fs;
	std::ifstream file{"suite.txt"};
	while (file >> fs) {
		std::cout << s << std::endl;
	}

	std::string ns;
	int nnum; 
	while (std::cin >> nnum) {
		// inherited from ostream and istream => has << and >> with stringstream 
		if (std::istringstream iss{ns}; iss >> nnum) {
			std::cout << nnum << std::endl; 
		}
	}

	return 0;
}