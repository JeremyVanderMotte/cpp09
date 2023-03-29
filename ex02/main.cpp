#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	if (argc < 2)
		return (returnError());
	try
	{
		PmergeMe plop(argc - 1, argv + 1);
		//if (isContainerSorted(plop.getDeque()))
		//	std::cout<<"deque sorted \n";
		//else
		//	std::cout<<" deque not sorted \n";
		//if (isContainerSorted(plop.getVect()))
		//	std::cout<<"vect sorted \n";
		//else
		//	std::cout<<"vect not sorted \n";
	}
	catch(const PmergeMe::PmergeMeException & e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
