#include "Utils.hpp"

/*
* Check If a token is a valid number.
*/
bool	isValidNumber(std::string token)
{
	float number;

	//Check if size of char* greater than INT_MAX length
	if (token.size() > 10) return (false);
	std::string::const_iterator it = token.begin();
	while (it != token.end() && std::isdigit(*it))
	{
		++it;
	}
	if (!token.empty() && it != token.end())
		return (false);
	number = std::atof(token.c_str());
	if (number > INT_MAX || number < 0) return (false);
	return (true);
}

/*
* print Error on cout and return an error code.
*/
int	returnError(void)
{
	std::cout << "Error" << std::endl;
	return (1);
}

/*
* Initialize a vector. Used to print the unsorted Vector at the beginning
*/
std::vector<int> initializeVector(int argc, char *numberList[])
{
	int	i = -1;
	std::vector<int> vect;
	while (++i < argc)
	{
		vect.push_back(std::atoi(numberList[i]));
	}
	return (vect);
}
