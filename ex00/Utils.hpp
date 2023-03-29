#ifndef UTILS_HPP
# define UTILS_HPP

//# include <ctime>
# include <iostream>

# define TXT_LINE "date | value"
# define CSV_LINE "date,exchange_rate"

bool	correctDateFormat(std::string date);
void	parseDate(std::string date, std::string* year, std::string* month, std::string* day);
bool	checkFirstLineFile(std::string const & line, std::string const & format);
#endif