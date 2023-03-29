#include "RPN.hpp"
#include "Utils.hpp"

//====CONSTRUCTOR====
RPN::RPN(std::string expression)
{
	performCalculation(expression);
}

//====DESTRUCTOR====
RPN::~RPN()
{
	while (!this->_stack.empty())
		this->_stack.pop();
}

/*
* Perform all the calculation and siplay the final result on cout
*  if no errors are encountered.
*/
int	RPN::performCalculation(std::string expression)
{
	size_t			pos = 0;
	std::string		token;

	if (!isExpressionOk(expression))
		return (returnError());
	//Loop to split the string into token using a delimiter
	while ((pos = expression.find(DELIMITER)) != std::string::npos)
	{
		token = expression.substr(0, pos);
		if (!isAnOperationSign(token))
			this->_stack.push(std::atoi(token.c_str()));
		else
		{
			if (!performOneOperation(token))
				return (returnError());
		}
		expression.erase(0, pos + DELIMITER_LENGTH);
	}
	if (!performOneOperation(expression))
		return (returnError());
	//At the end if the size of the stack is higher or lower than 1. 
	// There is an error.
	if (this->_stack.size() != 1)
		return (returnError());
	std::cout << this->_stack.top() << std::endl;
	return (0);

}

/*
* If the token is a number, push it on the stack.
* If it's an operator, pop the two first element and make the operation
*  then push the result on the stack. 
*/
bool	RPN::performOneOperation(std::string token)
{
	long			first, second;

	if (this->_stack.empty() || this->_stack.size() < 2)
		return (false);
	second = this->_stack.top();
	this->_stack.pop();
	first = this->_stack.top();
	this->_stack.pop();
	if (!token.compare("-"))
		this->_stack.push(first - second);
	else if (!token.compare("+"))
		this->_stack.push(first + second);
	else if (!token.compare("/"))
	{
		if (second == 0)
			return (false);
		this->_stack.push(first / second);
	}
	else if (!token.compare("*"))
		this->_stack.push(first * second);
	else
		return (false);
	return (true);
}