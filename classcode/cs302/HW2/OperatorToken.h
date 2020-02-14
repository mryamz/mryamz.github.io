#ifndef __OPERATOR_TOKEN_H__
#define __OPERATOR_TOKEN_H__


class OperatorToken
{

private:
	int precedence;
	char token;
	

public:

	OperatorToken();
	OperatorToken(char token);
	char getToken();

};

#endif