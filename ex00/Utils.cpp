#include "Utils.hpp"

/*
* Check if the date format is correct or not.
*/
bool	correctDateFormat(std::string date)
{
	std::string	year, month, day, token;

	parseDate(date, &year, &month, &day);
	if (!day.size() || !month.size() || !year.size()) return (false);
	if (day.size() != 2 || month.size() != 2 || year.size() != 4) return (false);
	time_t now = time(0);
	tm *ltm = localtime(&now);
	if (atoi(month.c_str()) > 12 || atoi(day.c_str()) > 31) return (false);
	if (1900 + ltm->tm_year > atoi(year.c_str())) return (true);
	if (1900 + ltm->tm_year == atoi(year.c_str()))
	{
		if (1 + ltm->tm_mon > atoi(month.c_str())) return (true);
		if (1 + ltm->tm_mon == atoi(month.c_str()))
		{
			if (ltm->tm_mday > atoi(day.c_str())) return (true);
			return (false);
		}
	}
	return (false);
}

/*
* Parse the date and extract all the informations to see if all
*  the informations are correct
*/
void	parseDate(std::string date, std::string* year, std::string* month, std::string* day)
{
	std::string	token;
	size_t		pos = 0, count = 0;
	std::string	delimiter = "-";
	
	while ((pos = date.find(delimiter)) != std::string::npos)
	{
		token = date.substr(0, pos);
		date.erase(0, pos+delimiter.length());
		switch(count)
		{
			case 0:
				*year = token;
				break;
			case 1:
				*month = token;
				break;
			default:
				break;
		}
		count++;
	}
	*day = date;
}

/*
* Check if a line correspond to an another.
* This method is created to compare the first line of the csv and .txt file.
*/
bool	checkFirstLineFile(std::string const & line, std::string const & format)
{
	return (!line.compare(format));
}