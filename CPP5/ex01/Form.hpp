#include "Bureaucrat.hpp"

class Form
{
	private:
		std::string name;
		bool isSigned;
		int signGrade;
		int execGrade;

	public:
		Form(const std::string &name, int signGrade, int execGrade);
		~Form();

		const std::string &getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;

		void beSigned(const Bureaucrat &bureaucrat);
};