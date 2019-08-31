/*including libraries*/
#include <iostream> //I/O header file for C++
#include <stdlib.h> //Defines four variable types, several macros, and various functions for performing general functions.
using namespace std; //The built in C++ library routines are kept in the standard namespace.like cin cout.. etc

class base{
	public:
		void override(){
			cout<<"`override()` overridden From BASE"<<endl;
		}
		virtual void virtual_override()
		{
			cout<<"`virtual_overide()` overridden From BASE"<<endl;
		}
};
//inhirting from BASE
	class derived :public base{
		public:
			void override()
				{
					cout<<"`override()` overridden From derived"<<endl; //this wont be called because the base class has no virtual keyword
				}
					 void virtual_override() //virtual function  inhireted from base
					{
						cout<<"`virtual_overide()` overridden From derived"<<endl;
					}
	};
	
	void  without_virtual_polymorphism(base* b)
	{ 
	b->override(); //no virtual key word
	} 
	
	void virtual_polymorphism(base* b)
	{ 
	b->virtual_override();
	}


	int main ()
	{

		derived d1;//making object for derived class
		
		without_virtual_polymorphism(&d1); //no polymoriphism  //no virtual keyword here
		
		virtual_polymorphism(&d1); //polymorphism 
	
	  return 0;
	}

