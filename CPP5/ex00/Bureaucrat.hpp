#include <iostream>

#define RED "\033[31m"
#define RESET "\033[0m"
#define GREEN "\033[32m"

class Bureaucrat 
{
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat(const std::string& name, int grade);
		~Bureaucrat();
		const std::string& getName() const;
		int getGrade() const;
		int setGrade(int newGrade);
		void incrementGrade();
		void decrementGrade();
};

void tryCreateBureaucrat(const std::string& name, int grade);