#include <string>
#include <iostream>
#include "Stack.h"
#include "ExpressionSolver.h"

void doMenu(std::string& input, ExpressionSolver& solver, double& solution) {
	while (input[0] != 'q') {
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << "------------ Enter An Expression ------------" << std::endl;
		std::cout << "---------------------------------------------" << std::endl;

		std::cin >> input;
		solution = solver.eval(input);

		std::cout << "'" << input << "'" << std::endl;
		std::cout << solution << std::endl;

	}
}

int main() {  
	std::string input = "( 4 ^ 3 + 2 / 8 ) * 5 + 3";
	std::cout << "Enter a math expression like so, or press 'q' to exit: " << std::endl;
	std::cout << input << std::endl;

	ExpressionSolver solver;
	double solution = solver.eval(input);  
	std::cout << solution << std::endl;


	try {
		doMenu(input, solver, solution);
	}
	catch (...) {
		std::cout << "Uh-oh, it looks like the expression isn't exaclty formatted" << std::endl;
		std::cout << "Try again, please." << std::endl;
		doMenu(input, solver, solution);

	}

	std::cout << solution << std::endl;

}