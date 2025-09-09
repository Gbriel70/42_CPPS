#include "Bureaucrat.hpp"

int main()
{
	tryCreateBureaucrat("A", 13);
	std::cout << "-----------------------------------\n" << std::endl;
	tryCreateBureaucrat("B", 150);
	std::cout << "-----------------------------------\n" << std::endl;
	tryCreateBureaucrat("C", 0);
	std::cout << "-----------------------------------\n" << std::endl;
	tryCreateBureaucrat("D", 500);
	return 0;
}
