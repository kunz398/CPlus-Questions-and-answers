#ifndef DATE_H //preprocessor to avoid multiple declarations of date class
#define DATE_H
class Date{
      
  private:
  int day;
  int month;
  int year;        
  
  public:
   Date();  
 //  ~Date();
   int getDay();
   int getMonth();
   int getYear();
   void setDate(int day, int month, int year);
   int DateDifference(Date dateobject);//get the difference of two dates in terms of number of days
   
   
   bool isLeapYear();  
};
#endif
