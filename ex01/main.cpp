# include "Utils.hpp"
# include "RPN.hpp"

int main (int argc, char *argv[])
{
	if (argc != 2 || !isExpressionOk(argv[1]))
		return (returnError());
	RPN calc(argv[1]);
	return (0);
}