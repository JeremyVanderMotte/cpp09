#include "Utils.hpp"

/*
* Check if the expression is ok. If the token doesn't match the rule 
* it willl return false
*/
bool	isExpressionOk(std::string expression)
{
	size_t		pos = 0;
	std::string	token;

	std::string tokenList = TOKEN;
	//Split a string by using delimiter and check every token.
	while ((pos = expression.find(DELIMITER)) != std::string::npos)
	{
		token = expression.substr(0, pos);
		if (!isTokenOk(token))
			return (false);
		expression.erase(0, pos + DELIMITER_LENGTH);
	}
	if (!isTokenOk(expression))
		return (false);
	return (true);
}

/*
* Check if the operator is valid.
* Check if it's a predefined list
*/
bool	isAnOperationSign(std::string token)
{
	std::string const tokenList = TOKEN;

	if (token.length() > 1) return (false);
	if (tokenList.find(token) != std::string::npos) return (true);
	return (false);
}

/*
* Check if the number is valid.
* He needs to be positive and not higher than 10.
*/
bool	isValidNumber(std::string token)
{
	int number;

	if (token.length() > 2) return (false);
	std::string::const_iterator it = token.begin();
	while (it != token.end() && std::isdigit(*it))
	{
		++it;
	}
	if (!token.empty() && it != token.end())
		return (false);
	number = std::atoi(token.c_str());
	if (number >= 10 || number < 0) return (false);
	return (true);
}

/*
* Check if the token is neither a valid operator nor a valid number.
*/
bool	isTokenOk(std::string token)
{
	if (token.length() == 1)
	{
		if (!isAnOperationSign(token))
			return (isValidNumber(token));
		return (true);
	}
	return (isValidNumber(token));
}

/*
* Return an int to quit the programm and display the Error message.
*/
int	returnError(void)
{
	std::cout << "Error" << std::endl;
	return (1);
}