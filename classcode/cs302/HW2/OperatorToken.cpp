#include "OperatorToken.h"

#ifndef __OPERATOR_TOKEN_CPP__
#define __OPERATOR_TOKEN_CPP__


OperatorToken::OperatorToken()
{
}

OperatorToken::OperatorToken(char token) : token(token)
{
}

char OperatorToken::getToken()
{
	return token;
}

#endif