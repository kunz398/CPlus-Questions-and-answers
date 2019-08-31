
#include "Customer.h"
#include "Movie.h"
#include "Date.h"
#include <string>
using namespace std;
#ifndef RENTAL_H //preprocessor to avoid multiple declarations of date class
#define RENTAL_H
class Rental{
      
  private:
  string Id;
  Customer cus;
  Movie m;
  Date Purchase;
  Date Return;
  float movie_cost;//total cost of movie including the overdue fine
  float overdue_fine;// stores the overdue fine
  
  public:
  Rental();
  void setRental(string Id,Customer *cus, Movie *m, Date *Purchase,Date *Return, float movie_cost, float overdue_fine);//set the rental data
  
  float getMovieCost();
  float getFine();
  string getID();
  Customer getCustomer();
  Movie getMovie();
  Date getDPurchase();
  Date getDReturn();
};
#endif
