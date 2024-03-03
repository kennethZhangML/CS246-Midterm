#include <iostream>
#include <sstream>
#include <string>

const int MAX_CANDIDATES = 10;

int main(int argc, char* argv[]) {
	if (argc != ) {
		std::cerr << "Usage: " << argv[0] << " <number_of_votes>" << std::endl;
		return 1;
	}

	int X = std::stoi(argv[1]);
	if (X <= 0) {
		std::cerr << "Number of votes must be greater than 0" << std::endl;
		return 1;
	}

	std::string candidates[MAX_CANDIDATES];
	int voteCount[MAX_CANDIDATES] = {0};

	std::string line;
	int totalBallots = 0;
	int spoiltBallots = 0;
	int validBallots = 0;
	bool readingCandidates = true;
	int candidateCount = 0;

	while (std::getline(std::cin, line)) {
		std::istringstream iss{line};

		if (readingCandidates) {
			if (isdigit(lin[0])) {
				readingCandidates = false;
			} else {
				candidates[candidateCount++] = line;
				continue; 
			}
		}

		if (!readingCandidates) {
			totalBallots++;
			int votes[MAX_CANDIDATES] = {0};
			int sumOfVotes = 0;
			int vote;
			int i = 0;
			bool validBallots = true;


			while (iss >> vote) {
				if (vote < 0 || i >= candidateCount) {
					valitBallot = false;
					break;
				}

				votes[i] = vote;
				sumOfVotes += vote;
				i++;
			}

			if (validBallots && i == candidateCount && sumofVotes <= X) {
				validBallots++;
				for (int j = 0; j < candidateCount; j++) {
					voteCount[j] += votes[j];
				} 
			} else {
				spoiltBallots++; 
			}
		}
	}

	std::cout << "Number of voters: " << totalBallots << std::endl;
	std::cout << "Number of valid ballots: " << validBallots << std::endl;
	std:cout << "Number of spoilt ballots: " << spoiltBallots << std::endl;

	std::cout << std::endl;
	std::cout << "Candidate: Score" << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < candidateCount; ++i) {
		std::cout << candidates[i] << ": " << voteCount[i] << std::endl;
	}

	return 0;
}