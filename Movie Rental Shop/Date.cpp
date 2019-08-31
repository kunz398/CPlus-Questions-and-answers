/*including libraries*/
#include <iostream> //I/O header file for C++
#include <stdlib.h> //Defines four variable types, several macros, and various functions for performing general functions.
#include "Date.h"
using namespace std; //The built in C++ library routines are kept in the standard namespace.like cin cout.. etc
	Date::Date()
	{
		day = 1;
		month =11;
		year = 2011;

	}
//	Date::~Date(){
//	};
	
	void Date::setDate(int day, int month, int year)
	{
		this->day=day;
		this->month=month;
		this->year=year;
	}
	
	int Date::getDay()
	{
		return this->day;
	}
	int Date::getMonth()
	{
		return this->month;
	}
	int Date::getYear()
	{
		return this->year;
	}
	 int Date::DateDifference(Date dateobject)//get the difference of two dates in terms of number of days
	 {
		return dateobject.getDay();
	 }

   bool Date::isLeapYear()
   {
   		if (getYear() %4 == 0)
   		{
   			return true;
		}else{
	   			return false;
			 }
   }
