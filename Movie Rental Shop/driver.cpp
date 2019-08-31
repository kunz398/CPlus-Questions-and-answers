/*
	|-------------------------------|	
	|	             				|
	|	Kunal Singh - S11110926		|
	|	                            |
	|-------------------------------|
					
	*************************************************************************************************************************				
	*Please Read me:	When The Colour of the program goes Red this means the User Input is invalid , while the user input *
	*					is valid the colour of the program will remain white												*
	*************************************************************************************************************************
*/

/*importing libraries*/
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <iomanip>
#include "Rental.h"
#include "Movie.h"
#include "Customer.h"
#include "Date.h"

using namespace std;//The built in C++ library routines are kept in the standard namespace.like cin cout.. etc	

const int MAX_SIZE = 200;

/*--------------------------------------ProtoType----------------------------------------------------------*/
void discard_line(ifstream &FileName);
void Print(Rental rentobj[], int size);
void SearchBYrentalNum (Rental rentobj[], int size);
void SearchBYMovieNum (Rental rentobj[], int size);
void datedif(Rental rentObj[],int size);
/*--------------------------------------ProtoType----------------------------------------------------------*/
int main(){
	system("color 07");
	/*Declaring Varibles*/
	string tempRental_id;
	string tempCus_id;
	string temp_Fname;
	string temp_Lname;
	string tempCus_contact;
	string tempMoive_id;
	string tempMovie_name;
	string tempMovie_genre;
	float tempMovie_cost;
	string  tempMovie_rating;
	string tempMovie_year;
	string  tempMovie_Director;
	string  tempPur_date;
	string tempRet_date;
	string day;
	int day_Pur,month_Pur,year_Pur;
	int day_Ret,month_Ret,year_Ret;
	int choice = 0;
	int total_records = 0;
	/*Declaring Varibles ENDS HERE*/

	/*Declaring Object*/
	Customer customerObject;
	Movie movieObject;
	Date dateObject;
	Date dateObjectPur;
	Date dateObjectRet;
	Rental rentalObject[MAX_SIZE];
	/*Declaring Object Ends Here*/
	cout<<fixed; cout<<setprecision(2);	
	
		ifstream DataFile ("Data.txt"); /*opening file*/
		
		/*If DataFile file fails*/		
		if(DataFile.fail()) 
		{
			system("COLOR 84"); //Color Red signifies that input is invalid
			cerr <<" \n\n\t\tError opening File Please Check to see if you have specified correct File Location. :("<<endl;
			exit(1); //exiting the loop
		}

			double day_diff = 0;
		double x ,y ,z = 0;
		double a,b,c = 0;
		double total;

	discard_line(DataFile); //Ignoring the First Line the in txt File
	while (!DataFile.eof()) 
	{
			/*Temp Varibles*/
			DataFile>>tempRental_id>>tempCus_id>>temp_Fname>>temp_Lname>>
			tempCus_contact>>tempMoive_id>>tempMovie_name>>tempMovie_genre>>
			tempMovie_cost>>tempMovie_rating>>tempMovie_year>>tempMovie_Director>>tempPur_date>>tempRet_date;
			/*----->>Temp Varibles Ends Here  <<-----*/
			customerObject.setCustomer(tempCus_id,temp_Fname,temp_Lname,tempCus_contact);
			movieObject.setMovie(tempMoive_id,tempMovie_name,tempMovie_genre,tempMovie_cost,tempMovie_rating,tempMovie_year,tempMovie_Director);
	
				/*If the first Second Char */
			 if (tempPur_date.substr(1,1) == "/" ) 
			 {
				 	day_Pur = atoi(tempPur_date.substr(0,1).c_str());
				 	month_Pur = atoi(tempPur_date.substr(2,2).c_str());
				 	year_Pur = atoi(tempPur_date.substr(5,4).c_str());
			 	
			
			 }else {
			 		day_Pur = atoi(tempPur_date.substr(0,2).c_str());
			 		month_Pur = atoi(tempPur_date.substr(3,2).c_str());
			 		year_Pur = atoi(tempPur_date.substr(6,4).c_str());
			 		}
			 	if (tempRet_date.substr(1,1) == "/")
				 {
					day_Ret = atoi(tempRet_date.substr(0,1).c_str());
				 	month_Ret = atoi(tempRet_date.substr(2,2).c_str());
				 	year_Ret = atoi(tempRet_date.substr(5,4).c_str());
			 	}else{	
					 	day_Ret = atoi(tempRet_date.substr(0,2).c_str());
					 	month_Ret = atoi(tempRet_date.substr(3,2).c_str());
					 	year_Ret = atoi(tempRet_date.substr(6,4).c_str());
				 	}
		
	dateObjectPur.setDate(day_Pur,month_Pur,year_Pur);
		dateObjectRet.setDate(day_Ret,month_Ret,year_Ret);
	
				
			day_diff = dateObjectRet.getDay() -  dateObjectPur.getDay();
			

			 if ( dateObjectRet.getYear() == dateObjectPur.getYear() )
			 { 
				 if(dateObjectRet.getMonth() == dateObjectPur.getMonth() )
				 { 
					 if  (day_diff <3)
					{
						 total = movieObject.getCost() * day_diff;
						 b=0;
					}else if (day_diff >=3)
					 {
							x = 2 * movieObject.getCost();
						    y = 0.50 +  movieObject.getCost(); 
							a = day_diff - 2;
							b = a * y;
							total = b + x;
					 }
				}
		
			 }

	rentalObject[total_records].setRental(tempRental_id,&customerObject,&movieObject,&dateObjectPur,&dateObjectRet,total,b);
	total_records++;
}

	DataFile.close();	

	while(choice <5){
			
			cout <<	"\n\t\tMain Menu"<<endl;
			cout <<	"\n\t\t1- Exit"	<<endl;
			cout <<	"\t\t2- Display All Charges"	<<endl;
			cout <<	"\t\t3- Search By Rental Number"	<<endl;
			cout <<	"\t\t4- Search By Movie Number"	<<endl;
			cin>>choice;
			
			while(cin.fail() || choice < 1 || choice > 4)
			{
				system("color 04");
				cerr <<	"\n\t\tERROR"<<endl;
				cerr<< "\tPlease Enter Correct Option: ";
				cin.clear();
				cin.ignore();
				cin>>choice;
			}

			if(choice==1)
			{
				cout<< "EXIT"<<endl;
				exit(1);

			}else if(choice==2)
					{
						system("color 07");
						system("cls");
						cout <<	"\n\t\tDisplay All Charges"<<endl;
						Print(rentalObject,total_records);

					}else if(choice==3)
							{
								system("color 07");
								system("cls");
								cout <<	"\n\t\tSearch By Rental Number"<<endl;
								
								SearchBYrentalNum(rentalObject,total_records);

								}else if(choice==4)
										{
											system("color 07");
											system("cls");
											cout <<	"\n\t\tSearch By Movie Number"<<endl;
											SearchBYMovieNum(rentalObject,total_records);

													}
		
	}
			

    system("pause");
    return 0;
}

void discard_line(ifstream &FileName){
    char c;
    do
   	    FileName.get(c);
    while (c!='\n');
}

	/*void datedif(Rental rentObj[],int size)
	{
		double day_diff = 0;
		int x ,y ,z = 0;
		int a,b,c = 0;
		int total = 0;

		 for (int i = 0; i<size; i++)
		 {
				
		  }
	}
	*/


	void Print(Rental rentobj[], int size)
	{
	

		cout<<"\n\n\t--------------------------------------------------------------------"<<endl;
		cout<<"\tRental Number\tCustomer Number\t\tMovie Charge"<<endl;
		cout<<"\t--------------------------------------------------------------------"<<endl;
		
		for (int i=0; i <size; i++)
		{
			cout<<"\t"<<rentobj[i].getID()<<"\t\t	"<<rentobj[i].getCustomer().getCID()<<"\t\t"<<rentobj[i].getMovieCost()<<"	"<<rentobj[i].getFine() <<endl;

		}
	}
	//Option 3
	void SearchBYrentalNum (Rental rentobj[], int size)
	{
		int occur = NULL;
		string search;
		bool flag = false;
		string option ;
		do{
			cout<<"Enter Rental Number to Search ";
			cin>>search;
			system("cls");
			cout<<"\n\tYou Searched For: "<<search<<endl;	
			cout<<"\n\n\t--------------------------------------------------------------------"<<endl;
			cout<<"\tRental Number\tCustomer Number\t\tMovie Charge"<<endl;
			cout<<"\t--------------------------------------------------------------------"<<endl;
			for(int i=0; i<size; i++)
			{
				if(search == rentobj[i].getID())
				{
					flag = true;
					if (flag ==true)
					{
						cout<<"\t"<<rentobj[i].getID()<<"\t\t"<<rentobj[i].getCustomer().getFname()<<" "<<rentobj[i].getCustomer().getLname()<<"\t\t"<<"--"<<endl;
					}
				}
			}
				if (flag ==false)
				{
					cout<<"\t\tNO RECORDS FOUND PLEASE TRY AGAIN"<<endl;
				}
			cout<<"\n\n\tTo Search For Another Record Press [Y] or Press [Any-Key] to Return To Main Menu: ";
			cin>>option;
		}while(option=="Y" ||option=="y");
	}
	//Option 4
	void SearchBYMovieNum (Rental rentobj[], int size)
	{
		string search;
		string option ;
		bool flag = false;
	do{	
			cout<<"Enter Movie Number to Search ";
			cin>>search;
			cout<<endl;
			//Converting each character typed in to Upper case since movie Name stored is in Upper Case
			for (int i = 0; i <search.length();i++)
				{
					search[i] = toupper(search[i]);
					
				}
			system("cls");
			cout<<"\n\tYou Searched For: "<<search<<endl;
			cout<<"\n\n\t--------------------------------------------------------------------"<<endl;
			cout<<"\tCustomer Number\t\tMovie Purchase Date"<<endl;
			cout<<"\t--------------------------------------------------------------------"<<endl;
			for(int i=0; i<size; i++)
			{
				if(search == rentobj[i].getMovie().getID())
				{
					flag = true;
					if (flag ==true)
						{
							cout<<"\t\t"<<rentobj[i].getCustomer().getCID()<<"\t\t";
							cout << rentobj[i].getDPurchase().getDay() <<"/" 
							<<rentobj[i].getDPurchase().getMonth() << "/" 
							<< rentobj[i].getDPurchase().getYear() << endl;
						}
				}
			}	
				if (flag ==false)
				{
				cout<<"\t\tNO RECORDS FOUND PLEASE TRY AGAIN"<<endl;
				}
			
			cout<<"\n\n\tTo Search For Another Record Press [Y] or Press [Any-Key] to Return To Main Menu: ";
			cin>>option;
				
		}while(option=="Y" ||option=="y");
	}
