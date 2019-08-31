
#include <string>
using namespace std;
#ifndef CUSTOMER_H //preprocessor to avoid multiple declarations of date class
#define CUSTOMER_H

class Customer{
      
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
      void setCustomer(string CID, string Fname, string Lname, string Contact);
//   void setCID(string CID);
//   void setFname(string Fname);
//   void setLname(string Lname);
//   void setContact(string Contact);
};
#endif
