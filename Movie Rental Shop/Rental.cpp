/*including libraries*/
#include <iostream> //I/O header file for C++
#include <stdlib.h> //Defines four variable types, several macros, and various functions for performing general functions.
#include "Rental.h"
#include "Movie.h"
#include "Date.h"
#include "Customer.h"
using namespace std; //The built in C++ library routines are kept in the standard namespace.like cin cout.. etc

	Rental::Rental(){;}
  
  void Rental::setRental(string Id,Customer *cus, Movie *m, Date *Purchase,Date *Return, float movie_cost, float overdue_fine)
  //set the rental data
  {
		this->Id = Id;

		this->cus.setCustomer(cus->getCID(),cus->getFname(),cus->getLname(),cus->getContact());
		this->m.setMovie(m->getID(),m->getMname(),m->getGenre(),m->getCost(),m->getRating(),m->getYearRelease(),m->getDirector());
		this->Purchase.setDate(Purchase->getDay(),Purchase->getMonth(),Purchase->getYear());
		this->Return.setDate(Return->getDay(),Return->getMonth(),Return->getYear());

		this->movie_cost = movie_cost; 
		this->overdue_fine = overdue_fine;
   }
  
  //GETtERS
  	string Rental::getID()
  	{
  		return this->Id;	
	}
	Customer Rental::getCustomer()
	{
	return this->cus;
	}
	Movie Rental::getMovie()
	{
		return this->m;
	}
	float Rental::getMovieCost()
	{
		return this->movie_cost;
	}
	float Rental::getFine()
	{
		return this->overdue_fine;
	}
	
	Date Rental::getDPurchase()
	{
		return this->Purchase;
	}
	Date Rental::getDReturn()
	{
		return this->Return;
	}
	