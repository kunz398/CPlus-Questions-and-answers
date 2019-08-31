/*including libraries*/
#include <iostream> //I/O header file for C++
#include <stdlib.h> //Defines four variable types, several macros, and various functions for performing general functions.
#include "Movie.h"
using namespace std; //The built in C++ library routines are kept in the standard namespace.like cin cout.. etc
 
	 Movie::Movie(){;} //Cons
	 
	 //Setter
	 void Movie::setMovie(string ID, string Mname,string Genre,float Cost,string Rating,string Year_Release,string Director)
	 {
	 	this->ID = ID;
	 	this->Mname = Mname;
		this->Genre = Genre;
		this->Cost = Cost;
		this->Rating = Rating;
		this->Year_Release = Year_Release;
		this->Director = Director;
	 	
	 }
// 	void Movie::setID(string ID)
//   {
//	   	this->ID = ID;
//   }
//   void Movie::setMname(string Mname)
//   {
//   	this->Mname = Mname;
//   }
//   void Movie::setGenre(string Genre)
//   {
//   	 this->Genre =Genre;
//   }
//   void Movie::setCost(float Cost)
//   {
//   	 this->Cost = Cost;
//   }
//   void Movie::setRating(string Rating)
//   {
//   	 this->Rating = Rating;
//   }
//   void Movie::setYearRelease(string Year_Release)
//   {
//   	 this->Year_Release =Year_Release;
//   }
//   void Movie::setDirector(string Director)
//   {
//   	 this->Director = Director;
//   }
	 //getters
   string Movie::getID()
   {
	   	return this->ID;
   }
   string Movie::getMname()
   {
   	return this->Mname;
   }
   string Movie::getGenre()
   {
   	return this->Genre;
   }
   float Movie::getCost()
   {
   	return this->Cost;
   }
   string Movie::getRating()
   {
   	return this->Rating;
   }
   string Movie::getYearRelease()
   {
   	return this->Year_Release;
   }
   string Movie::getDirector()
   {
   	return this->Director;
   }
	
	

