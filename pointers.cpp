/*including libraries*/
#include <iostream> //I/O header file for C++
#include <stdlib.h> //Defines four variable types, several macros, and various functions for performing general functions.
using namespace std; //The built in C++ library routines are kept in the standard namespace.like cin cout.. etc
/*
#include <iomanip>//maniuplators
#include <cmath> //math functions
#include <ctime> // Time Related Library
#include <iomanip> //setting precision points
#include <fstream> //accessing folders
#include <stdlib> //general purposes like converstion and sorting etc
#include <cstdlib> //c standard library
*/



int main ()
{

	int i = 42;   
	int k = 80; 
	int *p1;   
	int *p2;  
	
	p1 = &i;  
	p2 = &k;  
	p1 = p2;   
//	*p1 = *p2;   
	
	cout << i <<"\t"<< k << endl; 
//	cout << &i <<"\t"<< &k << endl; 


  return 0;
}

