#include <string>
#include <iostream>
#include "Stack.h"
#include "ExpressionSolver.h"

int main() {  
	

	ExpressionSolver solver;

	double solution = solver.eval("( 4 ^ 3 + 2 / 8 ) * 5 + 3");  

	std::cout << solution << std::endl;

}