#ifndef __EXPRESSION_SOLVER_H__
#define __EXPRESSION_SOLVER_H__

#include <iostream>
#include <string>
#include "Stack.h"
#include "OperatorToken.h"

#define OPERATORS_LENGTH 5

class ExpressionSolver
{
private:

	OperatorToken operators[OPERATORS_LENGTH];

	std::string toPostfix(std::string infix);

	int getPrecedence(char token);

public:

	ExpressionSolver();

	double eval(std::string infix);




};

#endif

