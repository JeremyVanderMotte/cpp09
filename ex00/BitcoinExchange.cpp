#include "BitcoinExchange.hpp"
#include "Utils.hpp"
#include <fstream>

//date plus petite que premiere

//====Constructor====
BitcoinExchange::BitcoinExchange(std::string filename)
{
	BitcoinExchange::extractBitcoinPrices();
	BitcoinExchange::extractStoringPrices(filename);
}

//====Destructor====
BitcoinExchange::~BitcoinExchange()
{
	this->_bitcoinPrices.clear();
	this->_storingPrices.clear();
}

/*
*Used to extract all the data in de .csv file and store it in a std::map
*/
void	BitcoinExchange::extractStoringPrices(std::string filename)
{
	std::string		delimiter = " | ", s, token, date;
	std::fstream	file;
	float			amount;
	size_t			pos = 0, count;

	file.open(filename, std::ios::in);
	if (!file.is_open())
		throw BitcoinExchange::FileNotOpenException();
	//Check to delete the first line.
	//I consider the fact that the line must be : 'date | value'
	getline(file, s);
	if (!checkFirstLineFile(s, TXT_LINE))
		throw BitcoinExchange::FirstLineFileNotGoodFormatException();

	/*Loop to split the line by using the delimier : ' | '
	*The loop find the first occurence of the delimiter and then erase 
	*the beginning of the string.
	*/
	while (getline(file, s))
	{
		count = 0;
		while((pos = s.find(delimiter)) != std::string::npos)
		{
			token = s.substr(0, pos);
			s.erase(0, pos + delimiter.length());
			switch (count)
			{
			case 0:
				date = token;
				break;
			default:
				break;
			}
			count++;
		}
		if (count != 0)
		{
			//for (size_t i = 0; i < s.size(); i++)
			//{
			//	if (!isdigit(s[i]))
			//	{
			//		count++;
			//		break;
			//	}
			//}
			amount = atof(s.c_str());
			if (amount == 0)
				count++;

		}
		else
			date = s;
		BitcoinExchange::checkErrorInput(date, count, amount, pos, s);
	}
	file.close();
}

/*
* Function made to check if the input in .txtfile are correct
*/
void	BitcoinExchange::checkErrorInput(std::string date, int count,
	double amount, size_t pos, std::string s)
{
	if (!correctDateFormat(date))
			std::cout << "Error: bad input => " << date << std::endl;
		else if (count == 0 && pos == std::string::npos)
			std::cout << "Error: bad input => " << date << std::endl;
		else if (count > 1)
			std::cout << "Error: bad input => " << s << std::endl;
		else if (amount < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else if (amount >= 1000)
			std::cout << "Error: too large number." << std::endl;
		else
			BitcoinExchange::printExchange(date, amount);
}

/*
* I made no verification on the CSV file because it is given by the subject.
* So we must not modify this file.
*/
void	BitcoinExchange::extractBitcoinPrices(void)
{
	std::fstream	myfile;
	std::string		date, change;

	myfile.open(CSV_FILE, std::ios::in);
	if (!myfile.is_open())
		throw FileNotOpenException();
	//Get the first line of the csv file and check if
	// it's matching : 'date,exchange_rate'
	getline(myfile, date);
	if (!checkFirstLineFile(date, CSV_LINE))
		throw BitcoinExchange::FirstLineCSVNotGoodFormatException();
	while (getline(myfile, date, ','))
	{
		getline(myfile, change, '\n');
		this->_bitcoinPrices[date] = atof(change.c_str());
	}
	myfile.close();
}

/*
* Function used to print the amount. If the exact amount is found it will
*  print this one. If none is found it will print the one before the date passed.
*/
void	BitcoinExchange::printExchange(std::string date, float amount) const
{
	std::string first = (this->_bitcoinPrices.lower_bound(date))->first;
	std::string second = (--(this->_bitcoinPrices.lower_bound(date)))->first;
	size_t diff = abs(first.compare(date));
	if (date.compare((*this->_bitcoinPrices.begin()).first) < 0)
		std::cout << "Error: bad input => " << date << std::endl;
	else if (diff == 0)
		std::cout << date << " => " << amount << " = " << (this->_bitcoinPrices.lower_bound(date)->second * amount) << std::endl; 
	else
		std::cout << date << " => " << amount << " = " << (--(this->_bitcoinPrices.lower_bound(date)))->second * amount << std::endl; 
}
