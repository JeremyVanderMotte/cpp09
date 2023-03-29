#include "BitcoinExchange.hpp"

void	displayMap(std::map<std::string, float> const mapToDisplay)
{
	std::map<std::string, float>::const_iterator it_begin;
	std::map<std::string, float>::const_iterator it_end;
	it_begin = mapToDisplay.begin();
	it_end = mapToDisplay.end();
	while (it_begin != it_end)
	{
		std::cout << it_begin->first;
		std::cout << "-";
		std::cout << it_begin->second << std::endl;
		it_begin++;
	}
}
int main(int argc, char *argv[])
{
	(void)argv;
	(void)argc;
	if (argc != 2)
	{
		std::cout << "Error: could not open file" << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange btc((std::string(argv[1])));
	}
	catch(BitcoinExchange::BitcoinExchangeException & e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
