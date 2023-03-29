#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <iostream>
# include "Utils.hpp"
# include <iterator>
# include <time.h>

class PmergeMe
{
	private:
		PmergeMe & operator=(PmergeMe const & rhs);
		PmergeMe(PmergeMe const & src);
		PmergeMe();

		std::vector<int>	_vect;
		std::deque<int>		_deque;

		bool	initializeVect(int argc, char *numberList[]);
		bool	initializeDeque(int argc, char *numberList[]);
		void	insertSortDeque(int first, int end);
		void	mergeDeque(int first, int median,int end);
		void	sortDeque(int first, int end);
		void	insertSortVect(int first, int end);
		void	mergeVect(int first, int median,int end);
		void	sortVect(int first, int end);
		double	performDeque(int argc, char *argv[]);
		double	performVector(int argc, char *argv[]);
		void	displayTimeElapsed(double timeDeque, double timeVect);

	public:
		PmergeMe(int argc, char* argv[]);
		~PmergeMe();
		std::deque<int> getDeque(void) const;
		std::vector<int> getVect(void) const;

	class PmergeMeException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("PmergeMeException catch");
			}
	};

	class IncorrectNumberException : public PmergeMeException
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Error: Wrong number in argument");
			}
	};
};

#endif