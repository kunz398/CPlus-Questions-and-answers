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
	#include <iostream> //I/O header file for C++
	#include <cstdlib> //Defines four variable types, several macros, and various functions for performing general functions.
	#include <fstream> //accessing folders 
	#include <string>
	using namespace std; //The built in C++ library routines are kept in the standard namespace.like cin cout.. etc	
	
	//Global Variblesd
	const int SIZE =50;
	
	// First, Mid and Annual Test out of 
	const int  FIRST_TEST_TOTAL = 60;
	const int  MID_TEST_TOTAL = 50;
	const int  ANNUAL_TEST_TOTAL = 100;
	
	//Percentage Allocated to each Test 
	const double  PERCENTAGE_FIRST_AND_MID = 0.30;
	const double PERCENTAGE_ANNUAL = 0.40;
	
	//Varibles To store total to the calculated Percentage 
	double first_test_percentage;
	double mid_test_percentage;
	double annual_test_percentage;
	double total_percentage;
	//End of Global Varibles
	
	/*Structure*/
	struct student_info
	{
		string first_name;
		string last_name;
		double first_test; // out of 60 
		double mid_test; // out of 50
		double annual_test; // out of 100
	};
	
	
	/*--------------------------------------ProtoType----------------------------------------------------------*/
	
	void search(student_info student_Detail[],string userInput,int size);//function For Searching for Students
	void print_marks(student_info student_Details[],int size);//function For Printing out marks of students
	double total_perc(student_info student_Details[],int array_location);//Function to calculate Total Percetage 
	void Analysis_lowest_highest(student_info student_Details[], double analysis[], int size); //Function to calulate hihest and lowest mark
	void Cal_average(double analysis[],int size); //Function to calulate Average
	void Cal_percentage_pass(student_info student_Details[],int total_records);//function to calulate Percentage Pass and Fail Rate
	
	/*---------------------------------------Main Function------------------------------------------------*/
	int main ()
	{
		/*Declaring Varibles*/
			student_info student_details[SIZE];//Setting a object and declaring Structure Varible as array
			//other varibles: arrays, choice , search
			int total_records = 0;
			int choice;
			string searchValue;
			double analysis[SIZE];
			bool valid = false;
		/*Declaring Varibles ENDS HERE*/
		
		ifstream studentfile ("Data.txt"); /*opening file*/
		
		/*If Opening file fails*/		
		if(studentfile.fail()) 
		{
			system("COLOR 84"); //Color Red signifies that input is invalid
			cerr <<" \n\n\t\tError opening File Please Check to see if you have specified correct File Location. :("<<endl;
			exit(1); //exiting the loop
		}
		
		/*storing first name, last name, first test, mid test and final test in a array*/
		while (!studentfile.eof()) 
		{
			studentfile>>student_details[total_records].first_name;
			studentfile>>student_details[total_records].last_name;
			studentfile>>student_details[total_records].first_test;
			studentfile>>student_details[total_records].mid_test;
			studentfile>>student_details[total_records].annual_test;
			total_records++; //x=x+1
		}
		
		system("COLOR 07"); //Color White signifies that input is valid
		do{		
			cout <<	"\n\t\t1- Exit"	<<endl;
			cout <<	"\t\t2- Print Total percentage mark for each student"	<<endl;
			cout <<	"\t\t3- Print Analysis"	<<endl;
			cout <<	"\t\t4- Search By Student"	<<endl;
			cin>>choice;
			
				if(choice==1)
				{
					system("color 71");//changes screen to white so that it is visble that the User pressed Has Exited The Program
					system("cls");
					cout <<"\n\n\n\t\tExit"<<endl;
					exit(1);
				}
				else if (choice==2)
				{
					system("CLS"); //Clears Screen
					system("COLOR 07"); //Color White signifies that input is valid 
					cout<<"\n\t\t************************************************"<<endl;
					cout <<	"\t\t* Print Total percentage mark for each student *"<<endl;
					cout<<"\t\t************************************************\n\n"<<endl;
					print_marks(student_details,total_records);
					cout<<"\t---------------------------------------"<<endl;
				}else if(choice==3)// Perform Analysis of the marks 
					{
						system("CLS");
						system("COLOR 07"); //Color White signifies that input is valid 
						cout<<"\n\t\t\t*******************"<<endl;
						cout<<"\t\t\t* Print Analysis  *"<<endl;
						cout<<"\t\t\t*******************\n\n"<<endl;
					
					 	Analysis_lowest_highest(student_details,analysis,total_records);
						Cal_average(analysis,total_records);
						Cal_percentage_pass(student_details,total_records);
						cout<<"\t\t---------------------------------------"<<endl;
					}
					else if (choice==4)
					{	
						system("CLS"); //Clears Screen
						system("COLOR 07"); //Color White signifies that input is valid 
						cout<<"\n\t\t\t*********************"<<endl;
						cout<<"\t\t\t* Search By Student *"<<endl;
						cout<<"\t\t\t*********************\n\n"<<endl;
						
						search(student_details,searchValue,total_records);
						cout<<"\t\t--------------------------------------------------------------"<<endl;
					}else
						{
							system("COLOR 84"); //Color Red signifies that input is invalid
							cerr <<	"\tPlease enter a correct option: "; 
							cin.clear();
							string choice;
							cin>>choice;
						}
		}while(!cin.fail());
		
		system("COLOR 71");//changes screen to white so that it is visble that the User pressed Has Exited The Program
		system("pause");
		return 0;
}
	/*---------------------------------End of Main Function---------------------------------*/
	   
	/*1: Search Function*/
	void search(student_info student_Detail[],string userInput,int size)
	{
		int array_location; // to see from what location the Result is from eg 0,1,2..
		bool result = false; //bool varible result to false
		 
		cout <<	"\t\tEnter a Name to Search: ";
		cin >>userInput;
		
		for (int i=0; i<size; i++)
		{
			if (!(student_Detail[i].first_name==userInput||student_Detail[i].last_name==userInput )) //whatever user has input is not found in the array then FALSE
			{
			 result = false;
			}else{
					result = true;
					array_location = i; //sotring the location of the found result in the varible Array_Location
					break;
				}	
		} //FOR LOOP END
		
		if (result == true)
		{
			cout<<endl;
			cout  <<"\t\t"<<student_Detail[array_location].first_name<<" "
				      <<student_Detail[array_location].last_name<<" "
				      <<student_Detail[array_location].first_test<<" "
				      <<student_Detail[array_location].mid_test<<" "
				      <<student_Detail[array_location].annual_test<<"\t| "
					  <<total_perc(student_Detail,array_location)<<"%\n";//Calling Total_perc Function to display total Percentage.
		}else{
				system("COLOR 84"); //Color Red signifies that input is invalid
				cout <<"\t\tThe Name: ""\""<<	userInput	<<"\" Was not found Please Enter a different name.:"<<endl;
			 }
		
	}
	
	
	//3: Printing Marks Function
	void print_marks(student_info student_Details[],int size)
	{
		for (int i=0; i<size; i++)
		{
			cout<<"\t"
				<<student_Details[i].first_name<<" "<<student_Details[i].last_name<<": "
				<<student_Details[i].first_test<<" "
				<<student_Details[i].mid_test<<" "
				<<student_Details[i].annual_test<<"\t| "
				<<total_perc(student_Details,i)<<"%\n"; //Calling Total_perc Function to display total Percentage.. calling function 4 in function 3
				
		}
	}
	
	//4: Calculating  Total Percentage Function
	double total_perc(student_info student_Details[],int array_location)
	{
		first_test_percentage = ( student_Details[array_location].first_test / FIRST_TEST_TOTAL ) * PERCENTAGE_FIRST_AND_MID;
		mid_test_percentage = ( student_Details[array_location].mid_test / MID_TEST_TOTAL ) * PERCENTAGE_FIRST_AND_MID;
		annual_test_percentage = ( student_Details[array_location].annual_test / ANNUAL_TEST_TOTAL ) * PERCENTAGE_ANNUAL;
		total_percentage = (first_test_percentage + mid_test_percentage + annual_test_percentage) * 100;
		
		return total_percentage;
	}
	
	//Lowst / Higest
	void Analysis_lowest_highest(student_info student_Details[],double analysis[], int size)
	{
		double highest = 0;
		double lowest = 0;
		double temp = 0;
		
		for (int i=0; i<size; i++)
			{
			analysis[i] = total_perc(student_Details,i); //storing all percenatge Mark in the analyrsis array 
			}
		/* 
		Assigning Somthing to the smallest and largest varible so that we can compare it against.
		and we can assume that the first array is the lowest number and like wise for the highest number.
		*/
	 lowest = analysis[0];
	 highest = analysis[0]; 
	 
	 for (int i=1; i<size; i++) //i am starting from index '1' because i am comparing index '0' with the next one 
	 {
	 	temp = analysis[i];//assinging whatever number is being looped through to our temp varible 
	 	
	 	if (temp < lowest)
		 {
	 		lowest = temp;
		 }
		 
		 if (temp > highest)
		 {
		 	highest = temp;
		 }
	 }
	  	cout <<"\t\tHighest: "<<highest<<endl;
		cout <<"\t\tLowest: "<<lowest<<endl;
		
	}
	void Cal_average(double analysis[],int size){
		double sum = 0;
		double average;
			for (int i=0; i<size; i++){
			 		sum+=analysis[i];
				 }
				 average = sum / size;
				 cout << "\t\tAverage: "<<average<<endl;

	}	
	//5: Calulating Percentag Pass
	void Cal_percentage_pass(student_info student_Details[],int total_records){
		
		double pass=0;
		double fail=0;
		double pass_rate;
		double fail_rate;
		for (int i=0; i<total_records; i++)
		{
			if (total_perc(student_Details,i)>50.0)
			{
				pass++;
			}else
				{
					fail++;
				}
			
		}
		pass_rate = ( (pass / total_records) * 100);
		//fail_rate = ( (fail / total_records) * 100);
						
		//cout <<"\n\tAmount of Students That Passed: "<<pass<<endl;
		cout <<"\t\tpercentage Pass rate: "<<pass_rate<<"%"<<endl;
		//cout <<"\n\tAmount of Students That Failed: "<<pass<<endl;
		//cout <<"\tPercentage Fail rate: "<<fail_rate<<"%"<<endl;
		//cout <<"\tTotal Students: "<<total_records<<endl;						
	}
