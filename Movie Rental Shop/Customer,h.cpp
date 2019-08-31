
#include <string>
using namespace std;
#ifndef CUSTOMER_H //preprocessor to avoid multiple declarations of date class
#define CUSTOMER_H

class Customer:public Date{
      
private:
  string CID;
  string Fname;
  string Lname;
  string Contact;
  
  public:
   Customer();
   string getCID();
   string getFname();
   string getLname();
   string getContact();
   void setCustomer(string, string, string, string);
   void setFname(string);
   void setLname(string);
   void setContact(string);
};
#endif
