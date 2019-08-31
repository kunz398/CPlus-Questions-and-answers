    /*including libraries*/
    #include <iostream> //I/O header file for C++
    #include <stdlib.h> //Defines four variable types, several macros, and various functions for performing general functions.
    #include "tut43.h"
    /*
    #include <cmath> //math functions
    #include <string> // string library
    #include <ctime> // Time Related Library
    #include <iomanip> //setting precision points
    #include <fstream> //accessing folders
    #include <stdlib> //general purposes like converstion and sorting etc
    #include <cstdlib> //c standard library
    */

     using namespace std; //The built in C++ library routines are kept in the standard namespace.like cin cout.. etc

    int main ()
    {

        tut43 tutObject;
         tut43 *tutPointer = &tutObject;


        tutObject.printsomthing();
        tutPointer->printsomthing();
        return 0;
    }
