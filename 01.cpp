#include <iostream>
#include <fstream>
#include <string>


bool isValidWord(const std::string& word, const std::string& wordfile) {
	std::ifstream file{wordfile};
	std::string n;

	while (file >> n) {
		if (word == n) {
			return true;
		}
	}

	return false; 
}

bool isOneDiff(const std::string& word1, const std::string& word2) {
	if (word1.length() != word2.length()) {
		return false; 
	}

	int countDiff = 0;
	for (int i = 0; i < word1.length(); ++i) {
		if (word1[i] != word2[i]) {
			countDiff++;

			if (countDiff > 1) return false; 
		}
	}
	return countDiff == 1; 
}


int main(int argc, char* argv[]) {
	if (argc != 4) {
		std::cerr << "Usage: <starting_word> <ending_word> <wordfile>" << std::endl; 
		return 1;
	}

	std::string startWord = argv[1];
	std::string endWord = argv[2];
	std::string wordFile = argv[3]; 

	if (!(isValidWord(startWord, wordFile)) || !(isValidWord(endWord, wordFile))) {
		std::cerr << "Error: starting word or ending word not found in word file" << std::endl;
		return 1; 
	}

	int bestScore = INT_MAX;
	std::string currentWord, previousWord;
	int currentScore;

	while (true) {
		std::cout << "Starting Word: " << startWord << std::endl;
		previousWord = startWord;
		currentScore = 0;

		while (std::cin >> currentWord) {
			if (currentWord == endWord) {
				if (isOneDiff(previousWord, currentWord)) {
					std::cout << "Congratulations! Your Score: " << currentScore;

					if (currentScore < bestScore) {
						bestScore = currentScore;
						std::cout << ", Best Score: " << bestScore << std::endl;
						break;
					} else {
						std::cout << ", Best Score: " << bestScore << std::endl;
					}

					break;
				} else {
					std::cerr << "Error: " << currentWord << " does not differ from" << previousWord << " by exactly one character." << std::endl;
				}

			} else if (!isValidWord(currentWord, wordFile)) {
				std::cerr << "Error: " << currentWord << " does not belong to word file." << std::endl;
				break;
			} else if (!isOneDiff(previousWord, currentWord)) {
				std::cerr << "Error: " << currentWord << " does not differ from " << previousWord << " by exactly one character." << std::endl;
				break;
			} else {
				previousWord = currentWord;
				currentScore++;
			}	

		}

		if (std::cin.eof()) {
			break;
		}
	}

	return 0;
}