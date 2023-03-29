#ifndef UTILS_HPP
# define UTILS_HPP
# define TOKEN "+ - / *"
# define DELIMITER " "
# define DELIMITER_LENGTH 1
# include <iostream>
# include <stdlib.h>


bool	isExpressionOk(std::string expression);
bool	isAnOperationSign(std::string token);
bool	isTokenOk(std::string token);
bool	isValidNumber(std::string token);
int		returnError(void);

#endif