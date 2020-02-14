#include "ExpressionSolver.h"
#include <cmath>
#ifndef __EXPRESSION_SOLVER_CPP__
#define __EXPRESSION_SOLVER_CPP__
//tavikosheredcode

#define DEBUG 1


ExpressionSolver::ExpressionSolver()
{
	operators[0] = OperatorToken('+');
	operators[1] = OperatorToken('-');
	operators[2] = OperatorToken('*');
	operators[3] = OperatorToken('/');
	operators[4] = OperatorToken('^');
}

std::string ExpressionSolver::toPostfix(std::string infix)
{
	std::string postfix;

	Stack<char> opStack;
	for (int i = 0; i < infix.length(); i++) {
		char token = infix[i];

#if DEBUG
		std::cout << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "(Pre) Index: " << i << ", Stack: " << opStack.toString() << std::endl;
		std::cout << "(Pre) Index: " << i << ", Postfix: " << postfix << std::endl;
		std::cout << token << std::endl;
#endif

		if (token == ' ')
			continue;

		if (token == '(') {
			opStack.push('(');
			continue;
		}

		
		bool isOp = token == '+' || token == '-' || token == '*' || token == '/' || token == '^';
		
#if DEBUG
		std::cout << isOp << std::endl;
#endif		
		if (isOp) {

			if (!opStack.isEmpty() && (opStack.peek() == '+' || opStack.peek() == '-' || opStack.peek() == '*' || opStack.peek() == '/' || opStack.peek() == '^')) {
				int peekPrecedence = getPrecedence(opStack.peek());
				if (peekPrecedence < getPrecedence(token)) {
					postfix += opStack.peek();
					postfix += ' ';
					opStack.pop();
				}
				
			} 
			opStack.push(token);
			
		}

		if (!isOp && token != ')') {
			postfix += token;
			postfix += ' ';
			
		}

		if (token == ')') {
			char peeked = opStack.peek();
			while (peeked != '(') {
				postfix += peeked;
				postfix += ' ';
				opStack.pop();
				peeked = opStack.peek();
			}
			opStack.pop();
		}
#if DEBUG

		std::cout << "(Post) Index: " << i << ", Stack: " << opStack.toString() << std::endl;
		std::cout << "(Post) Index: " << i << ", Postfix: " << postfix << std::endl;
		std::cout << std::endl;
#endif
	}

	while (!opStack.isEmpty()) {
		postfix += opStack.peek();
		postfix += ' ';
		opStack.pop();
	}
#if DEBUG

	std::cout << postfix << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
#endif


	return postfix;
}

int ExpressionSolver::getPrecedence(char token)
{

	if (token == '+' || token == '-') {
		return 400;
	}

	if (token == '*' || token == '/') {
		return 200;
	}

	if (token == '^') {
		return 100;
	}

	std::cout << "Bad token exception: '" << token << "'" << std::endl;
	return -1;
}


double ExpressionSolver::eval(std::string infix)
{
	std::string postfix = toPostfix(infix);

	Stack<std::string> stack;
	for (int i = 0; i < postfix.length(); i++) {
		char token = postfix[i];
		if (token == ' ')
			continue;

		bool isOp = token == '+' || token == '-' || token == '*' || token == '/' || token == '^';



		if (!isOp) {
			std::string s;
			s += token;
			stack.push(s);
		}

		if (isOp) {
#if DEBUG

			std::cout << stack.toString() << std::endl;
#endif
			double a = std::stod(stack.peek());
			stack.pop();

			double b = std::stod(stack.peek());
			stack.pop();
#if DEBUG
			std::cout << b << token << a << std::endl;
#endif
			if (token == '+') {
				stack.push(std::to_string(b + a));
			}

			if (token == '-') {
				stack.push(std::to_string(b - a));

			}

			if (token == '*') {
				stack.push(std::to_string(b * a));

			}

			if (token == '/') {
				stack.push(std::to_string(b / a));

			}

			if (token == '^') {
				stack.push(std::to_string(pow(b, a)));

			}

		}
	}
	return std::stod(stack.peek());
}

#endif 