#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# define CSV_FILE "data.csv"

# include <iostream>
# include <map>

class BitcoinExchange
{
	private:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange & src);
		std::map<std::string, float> _bitcoinPrices;
		std::map<std::string, float> _storingPrices;
		void	extractBitcoinPrices(void);
		void	extractStoringPrices(std::string filename);
		void	checkErrorInput(std::string date, int count, double amount, size_t pos, std::string s);

	public:
		~BitcoinExchange();
		BitcoinExchange(std::string filename);
		BitcoinExchange & operator=(BitcoinExchange const & rhs);

		void	printExchange(std::string date, float amount) const;


	//Exceptions
	class BitcoinExchangeException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("BitcoinExchangeException catch");
			}
	};

	class FileNotOpenException : public BitcoinExchange::BitcoinExchangeException
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Error: could not open file");
			}
	};

	class FirstLineFileNotGoodFormatException : public BitcoinExchange::BitcoinExchangeException
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Error: first line of file doesn't match 'date | value'");
			}
	};

	class FirstLineCSVNotGoodFormatException : public BitcoinExchange::BitcoinExchangeException
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Error: first line of file doesn't match 'date,exchange_rate'");
			}
	};
};

#endif