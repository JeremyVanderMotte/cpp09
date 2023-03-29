#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <limits>
# include <list>
# include <vector>

# define NBR_GROUP 5
# define DEQUE 1
# define VECTOR 2

bool				isValidNumber(std::string token);
int					returnError(void);
std::vector<int>	initializeVector(int argc, char *argv[]);

/*
* Template method used to print the elements of a container.
*/
template <typename T>
void printContainer (T const& container)
{
	typename T::const_iterator begin;  // iterator to iterate over coll
	typename T::const_iterator end;  // end position

	begin = container.begin();
	end = container.end();
	while (begin != end)
	{
		std::cout << *begin << ' ';
		begin++;
	}
	std::cout << std::endl;
}

/*
* Template method to check if a container is sorted.
*/
template <typename T>
bool isContainerSorted(T const & container)
{
	typename T::const_iterator	beginIt;
	typename T::const_iterator	middleIt;
	typename T::const_iterator	endIt;

	beginIt = container.begin();
	endIt = container.end();
	while (beginIt != endIt)
	{
		middleIt = beginIt;
		middleIt++;
		while (middleIt != endIt)
		{
			if (*beginIt > *middleIt)
				return (false);
			middleIt++;
		}
		beginIt++;
	}
	return (true);

}
#endif