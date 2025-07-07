#include "Fixed.hpp"


int main()
{
    Fixed default_contructor;
    cout << "---------------------------------------------------------------------------"<< endl;
    Fixed copy_contructor(default_contructor);
    cout << "---------------------------------------------------------------------------"<< endl;
    Fixed default_contructor2;
    cout << "---------------------------------------------------------------------------"<< endl;

    default_contructor2 = copy_contructor;


    cout << "default_contructor.getRawBits() = " << default_contructor.getRawBits() << endl;
    cout << "---------------------------------------------------------------------------"<< endl;
    cout << "copy_contructor.getRawBits() = " << copy_contructor.getRawBits() << endl;
    cout << "---------------------------------------------------------------------------"<< endl;
    cout << "default_contructor2.getRawBits() = " << default_contructor2.getRawBits() << endl;
    cout << "---------------------------------------------------------------------------"<< endl;

    default_contructor2.setRawBits(42);
    Fixed default_contructor3;
    default_contructor3 = default_contructor2;
    cout << "default_contructor3.getRawBits() = " << default_contructor3.getRawBits() << endl;
    cout << "---------------------------------------------------------------------------"<< endl;


    
    return 0;
}