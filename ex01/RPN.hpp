#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>

class RPN
{
	private:
		RPN();
		RPN(const RPN & src);
		RPN &	operator=(RPN const & rhs);
		int		performCalculation(std::string expression);
		bool	performOneOperation(std::string token);

		std::stack<long>	_stack;

	public:
		RPN(std::string expression);
		~RPN();
};

#endif