#include "Form.hpp"

void testBureaucratValidConstruction() {
    std::cout << "\n=== TESTING BUREAUCRAT VALID CONSTRUCTION ===" << std::endl;
    
    Bureaucrat *b1 = tryCreateBureaucrat("Alice", 1);
    Bureaucrat *b2 = tryCreateBureaucrat("Bob", 75);
    Bureaucrat *b3 = tryCreateBureaucrat("Charlie", 150);

    delete b1;
    delete b2;
    delete b3;
}

void testBureaucratInvalidConstruction() {
    std::cout << "\n=== TESTING BUREAUCRAT INVALID CONSTRUCTION ===" << std::endl;

    Bureaucrat *b1 = tryCreateBureaucrat("TooHigh", 0);
    Bureaucrat *b2 = tryCreateBureaucrat("TooLow", 151);
    Bureaucrat *b3 = tryCreateBureaucrat("Negative", -5);

    delete b1;
    delete b2;
    delete b3;
}

void testFormValidConstruction() {
    std::cout << "\n=== TESTING FORM VALID CONSTRUCTION ===" << std::endl;
    
    Form *f1 = tryCreateForm("TaxForm", 50, 25);
    Form *f2 = tryCreateForm("TopSecret", 1, 1);
    Form *f3 = tryCreateForm("Public", 150, 150);
    Form *f4 = tryCreateForm("Mixed", 1, 150);
    
    delete f1;
    delete f2;
    delete f3;
    delete f4;
}

void testFormInvalidConstruction() {
    std::cout << "\n=== TESTING FORM INVALID CONSTRUCTION ===" << std::endl;
    
    Form *f1 = tryCreateForm("InvalidSign1", 0, 50);
    Form *f2 = tryCreateForm("InvalidSign2", 151, 50);
    Form *f3 = tryCreateForm("InvalidExec1", 50, 0);
    Form *f4 = tryCreateForm("InvalidExec2", 50, 151);
    Form *f5 = tryCreateForm("BothInvalid", 0, 0);	   
    
    delete f1;
    delete f2;
    delete f3;
    delete f4;
    delete f5;
}

void testFormBeSigned() {
    std::cout << "\n=== TESTING FORM beSigned() METHOD ===" << std::endl;
    
    Form *form = tryCreateForm("SignTest", 60, 40);
    if (form) {
        Bureaucrat *goodBureaucrat = tryCreateBureaucrat("GoodGuy", 50);
        Bureaucrat *badBureaucrat = tryCreateBureaucrat("BadGuy", 70);
        
        if (goodBureaucrat && badBureaucrat) {
            std::cout << "\n--- Testing successful beSigned ---" << std::endl;
            std::cout << "Before: " << *form << std::endl;
            try {
                form->beSigned(*goodBureaucrat);
                std::cout << "After: " << *form << std::endl;
            } catch (const std::exception &e) {
                std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
            }
            
            std::cout << "\n--- Testing failed beSigned (insufficient grade) ---" << std::endl;
            Form *form2 = tryCreateForm("StrictForm", 60, 40);
            if (form2) {
                std::cout << "Before: " << *form2 << std::endl;
                try {
                    form2->beSigned(*badBureaucrat);
                    std::cout << "✗ Should have thrown exception!" << std::endl;
                } catch (const std::exception &e) {
                    std::cout << "✓ Correctly caught: " << e.what() << std::endl;
                }
                delete form2;
            }
        }
        
        delete goodBureaucrat;
        delete badBureaucrat;
        delete form;
    }
}

void testBureaucratSignForm() {
    std::cout << "\n=== TESTING BUREAUCRAT signForm() METHOD ===" << std::endl;
    
    std::cout << "\n--- Testing successful signForm ---" << std::endl;
    Bureaucrat *manager = tryCreateBureaucrat("Manager", 30);
    Form *report = tryCreateForm("Report", 50, 25);
    
    if (manager && report) {
        std::cout << "Before signing: " << *report << std::endl;
        manager->signForm(*report);
        std::cout << "After signing: " << *report << std::endl;
    }
    
    std::cout << "\n--- Testing failed signForm (insufficient grade) ---" << std::endl;
    Bureaucrat *intern = tryCreateBureaucrat("Intern", 100);
    Form *classified = tryCreateForm("Classified", 25, 15);
    
    if (intern && classified) {
        std::cout << "Before signing attempt: " << *classified << std::endl;
        intern->signForm(*classified);
        std::cout << "After signing attempt: " << *classified << std::endl;
    }
    
    std::cout << "\n--- Testing signForm on already signed form ---" << std::endl;
    if (manager && report) {
        manager->signForm(*report);
    }
    
    delete manager;
    delete report;
    delete intern;
    delete classified;
}

void testBoundaryConditions() {
    std::cout << "\n=== TESTING BOUNDARY CONDITIONS ===" << std::endl;
    
    Bureaucrat *exactGrade = tryCreateBureaucrat("Exact", 50);
    Form *exactForm = tryCreateForm("ExactForm", 50, 25);
    
    if (exactGrade && exactForm) {
        std::cout << "Testing exact grade match (should succeed):" << std::endl;
        exactGrade->signForm(*exactForm);
    }
    
    Bureaucrat *oneOff = tryCreateBureaucrat("OneOff", 51);
    Form *strictForm = tryCreateForm("StrictForm", 50, 25);
    
    if (oneOff && strictForm) {
        std::cout << "Testing one grade insufficient (should fail):" << std::endl;
        oneOff->signForm(*strictForm);
    }
    
    delete exactGrade;
    delete exactForm;
    delete oneOff;
    delete strictForm;
}

void testBureaucratCopyAndAssignment() {
    std::cout << "\n=== TESTING BUREAUCRAT COPY AND ASSIGNMENT ===" << std::endl;
    
    Bureaucrat *original = tryCreateBureaucrat("Original", 42);
    if (original) {
        std::cout << "\n--- Testing copy constructor ---" << std::endl;
        Bureaucrat copy(*original);
        std::cout << "Original: " << *original << std::endl;
        std::cout << "Copy: " << copy << std::endl;
        
        std::cout << "\n--- Testing assignment operator ---" << std::endl;
        Bureaucrat assigned("TempName", 100);
        std::cout << "Before assignment: " << assigned << std::endl;
        assigned = *original;
        std::cout << "After assignment: " << assigned << std::endl;
        std::cout << "Note: Name doesn't change in assignment (const member)" << std::endl;
        
        delete original;
    }
}

// Test extreme scenarios
void testExtremeScenarios() {
    std::cout << "\n=== TESTING EXTREME SCENARIOS ===" << std::endl;
    
    Bureaucrat *supreme = tryCreateBureaucrat("Supreme", 1);
    if (supreme) {
        Form *f1 = tryCreateForm("AnyForm1", 150, 100);
        Form *f2 = tryCreateForm("AnyForm2", 75, 50);
        Form *f3 = tryCreateForm("AnyForm3", 1, 1);
        
        if (f1) supreme->signForm(*f1);
        if (f2) supreme->signForm(*f2);
        if (f3) supreme->signForm(*f3);
        
        delete f1;
        delete f2;
        delete f3;
    }
    
    Bureaucrat *lowest = tryCreateBureaucrat("Lowest", 150);
    if (lowest) {
        Form *topSecret = tryCreateForm("TopSecret", 1, 1);
        if (topSecret) {
            lowest->signForm(*topSecret);
            delete topSecret;
        }
    }
    
    delete supreme;
    delete lowest;
}

int main(void)
{
    testBureaucratValidConstruction();
    testBureaucratInvalidConstruction();
    testFormValidConstruction();
    testFormInvalidConstruction();
    testFormBeSigned();
    testBureaucratSignForm();
    testBoundaryConditions();
    testBureaucratCopyAndAssignment();
    testExtremeScenarios();

    return 0;
}