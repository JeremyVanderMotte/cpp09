#include "PmergeMe.hpp"
# include <iomanip>


/*
* ressources : https://iq.opengenus.org/merge-insertion-sort/amp/
*/
//====CONTSRUCTOR====
PmergeMe::PmergeMe(int argc, char* argv[])
{

	double	diffTimeDeque = PmergeMe::performDeque(argc, argv);
	double	diffTimeVect = PmergeMe::performVector(argc, argv);

	std::cout << "Before:\t";
	std::vector<int> vectBeforeSort = initializeVector(argc, argv);
	printContainer(vectBeforeSort);
	vectBeforeSort.clear();
	
	std::cout << "After:\t";
	printContainer(this->_vect);
	
	displayTimeElapsed(diffTimeDeque, diffTimeVect);
}

//====DESCTRUCTOR====
PmergeMe::~PmergeMe()
{
	this->_vect.clear();
	this->_deque.clear();
}

/*
* Display the time elapsed between the initialisation of both vector
* and the end of the sorting. The time is proper to each container.
*/
void	PmergeMe::displayTimeElapsed(double timeDeque, double timeVect)
{
	double elapsedVect, elapsedDeque;
	
	//Used to display something more lisible.
	elapsedDeque = timeDeque / CLOCKS_PER_SEC * 1000;
	//Set the precision to 6 digits.
	std::cout << std::fixed << std::setprecision(3);
	std::cout << "Time to process a range of "
		<< this->_deque.size() << " elements with std::deque : " << elapsedDeque
		<< " ms" << std::endl;
	elapsedVect =  timeVect / CLOCKS_PER_SEC * 1000;
	std::cout << "Time to process a range of "
		<< this->_vect.size() << " elements with std::vector : " << elapsedVect
		<< " ms" << std::endl;
}

//Perform the initialisation and the sorting of the Deque
double	PmergeMe::performDeque(int argc, char *argv[])
{
	std::clock_t startDeque = std::clock();
	if (!PmergeMe::initializeDeque(argc, argv))
		throw PmergeMe::IncorrectNumberException();
	PmergeMe::sortDeque(0, this->_deque.size() - 1);
	std::clock_t endDeque = std::clock();
	return (endDeque - startDeque);
}

//Perform the initialisation and the sorting of the Vector
double	PmergeMe::performVector(int argc, char *argv[])
{
	std::clock_t startVect = std::clock();
	if (!PmergeMe::initializeVect(argc, argv))
		throw PmergeMe::IncorrectNumberException();
	PmergeMe::sortVect(0, this->_deque.size() - 1);
	std::clock_t endVect = std::clock();
	return (endVect - startVect);
}

/*
* Initialize the deque and check if the number are valid.
*/
bool	PmergeMe::initializeDeque(int argc, char *numberList[])
{
	int	i = 0;

	while (i < argc)
	{
		if (!isValidNumber(numberList[i]))
			return (false);
		if (std::atoi(numberList[i]) < 0)
			return (false);
		this->_deque.push_back(std::atoi(numberList[i]));
		i++;
	}
	return (true);
}

/*
*	Initialize the vector and check if the number are valid.
*/
bool	PmergeMe::initializeVect(int argc, char *numberList[])
{
	int	i = -1;

	while (++i < argc)
	{
		if (!isValidNumber(numberList[i]))
			return (false);
		if (std::atoi(numberList[i]) < 0)
			return (false);
		this->_vect.push_back(std::atoi(numberList[i]));
	}
	return (true);
}

/*
*	Getter for the vector
*/
std::vector<int> PmergeMe::getVect(void) const
{
	return (this->_vect);
}

/*
*	Getter for the deque
*/
std::deque<int> PmergeMe::getDeque(void) const
{
	return (this->_deque);
}

//SORT ALGORITH DEQUE
void	PmergeMe::insertSortDeque(int first, int end)
{
	for(int i = first; i < end; i++)
	{
		int	temp = this->_deque[i + 1];
		int	j = i + 1;
		while (j > first && this->_deque[j - 1] > temp)
		{
			this->_deque[j] = this->_deque[j - 1];
			j--;
		}
		this->_deque[j] = temp;
	}
}

void	PmergeMe::mergeDeque(int left,int median, int right)
{
	int sideLeft = median - left + 1;
	int sideRight = right - median;
	std::deque<int> leftDeque(sideLeft), rightDeque(sideRight);
	int rightIndex = 0;
	int leftIndex = 0;

	for (int i = 0; i < sideLeft; i++)
	{
		leftDeque[i] = this->_deque[left + i];
	}
	for (int i = 0; i < sideRight; i++)
	{
		rightDeque[i] = this->_deque[median + 1 + i];
	}
	for (int i = left; i <= right; i++)
	{
		if (rightIndex == sideRight)
		{
			this->_deque[i] = leftDeque[leftIndex];
			leftIndex++;
		}
		else if (leftIndex == sideLeft)
		{
			this->_deque[i] = rightDeque[rightIndex];
			rightIndex++;
		}
		else if (rightDeque[rightIndex] > leftDeque[leftIndex])
		{
			this->_deque[i] = leftDeque[leftIndex];
			leftIndex++;
		}
		else
		{
			this->_deque[i] = rightDeque[rightIndex];
			rightIndex++;
		}
	}
}


void	PmergeMe::sortDeque(int first, int end)
{
	int median;

	if ((end - first) > NBR_GROUP)
	{
		median = (first + end) / 2;
		sortDeque(first, median);
		sortDeque(median + 1, end);
		mergeDeque(first, median, end);
	}
	else
	{
		insertSortDeque(first, end);
	}
}

//SORT ALGORITHM VECT
void	PmergeMe::insertSortVect(int first, int end)
{
	for(int i = first; i < end; i++)
	{
		int	temp = this->_vect[i + 1];
		int	j = i + 1;
		while (j > first && this->_vect[j - 1] > temp)
		{
			this->_vect[j] = this->_vect[j - 1];
			j--;
		}
		this->_vect[j] = temp;
	}
}

void	PmergeMe::mergeVect(int left, int median,int right)
{
	int leftSide = median - left + 1;
	int rightSide = right - median;
	std::vector<int> leftVector(leftSide), rightVector(rightSide);
	int rightIndex = 0;
	int leftIndex = 0;

	for (int i = 0; i < leftSide; i++)
	{
		leftVector[i] = this->_vect[left + i];
	}
	for (int i = 0; i < rightSide; i++)
	{
		rightVector[i] = this->_vect[median + 1 + i];
	}
	for (int i = left; i <= right; i++)
	{
		if (rightIndex == rightSide)
		{
			this->_vect[i] = leftVector[leftIndex];
			leftIndex++;
		}
		else if (leftIndex == leftSide)
		{
			this->_vect[i] = rightVector[rightIndex];
			rightIndex++;
		}
		else if (rightVector[rightIndex] > leftVector[leftIndex])
		{
			this->_vect[i] = leftVector[leftIndex];
			leftIndex++;
		}
		else
		{
			this->_vect[i] = rightVector[rightIndex];
			rightIndex++;
		}
	}
}

void	PmergeMe::sortVect(int first, int end)
{
	int	median;

	if ((end - first) > NBR_GROUP)
	{
		median = (first + end) / 2;
		sortVect(first, median);
		sortVect(median + 1, end);
		mergeVect(first, median, end);
	}
	else
	{
		insertSortVect(first, end);
	}
}