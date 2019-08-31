/*including libraries*/
#include <iostream> //I/O header file for C++
#include <stdlib.h> //Defines four variable types, several macros, and various functions for performing general functions.
#include "Customer.h"
using namespace std; //The built in C++ library routines are kept in the standard namespace.like cin cout.. etc
 		//classname :: construstor name
	 Customer::Customer(){;}
	 
	 //datatype ClassName::functionname()
	 void Customer:: setCustomer(string CID, string Fname, string Lname, string Contact)
	 {
	 	this->CID = CID;
	 	this->Fname = Fname;
	 	this->Lname = Lname;
	 	this->Contact = Contact;
	 }

	 //Setters
//	 void Customer:: setCID(string CID)
//	 {
//	 	this->CID = CID;
//	 }
//   void Customer:: setFname(string Fname)
//   {
//   	this->Fname = Fname;
//   }
//   void Customer:: setLname(string Lname)
//   {
//   	this->Lname = Lname;
//   }
//   void Customer:: setContact(string Contact)
//   {
//   	this->Contact = Contact;
//   }
   //Gettters
    string Customer:: getCID()
    {
    	return this->CID;
	}
   string Customer:: getFname()
   {
   	return this->Fname;
   }
   string Customer:: getLname()
   {
   	return this->Lname;
   }
   string Customer:: getContact()
   {
   	return this->Contact;
   }
   
