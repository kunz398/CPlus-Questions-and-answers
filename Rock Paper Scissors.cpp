

# include <iostream>//Header that defines the standard input/output stream objects
# include <cstdlib>//This header defines several general purpose functions including random number genration,searching, sorting and converting.
# include <cmath> //declares a set of functions to compute common mathematical operations and transformations:
# include <ctime> //This header file contains definitions of functions to get and manipulate date and time information.


using namespace std;

char readchoice();//prototype  for validates user input and askes user to make a choice
char random4rps();//prototype  for Random Function
void evaluatechoices(char user_choice, char cpu_choice, int& tie,int& win, int& loss);//prototype for function to compare winning conditions and lossing condtions
char selectRPS(int rocks,int papers ,int scissors);//prototype for function selects R, P or S based on the counters rocks, papers and scissors. 
void add2list(char element,char array[],int capacity,int& used);//prototype  for  function inserts a new element at position 0 of an array of size capacity, and update the number of used element in the array accordingly 
char make_choice(char longlist[],int usedlong,char shortlist[],int usedshort);//prototype  for function to compares the short list with the long list, to be able to choose whether to play R, P or S next

int main()
{
	srand(time(0)); //use current time as seed for random generator
	char user_choice;	//variables for user selection
	char cpu_choice =random4rps();//the first pc choice intilized to random.
		
	//Declare a long array of size 100, and a companion variable for the number of used elements.	
	const int LONG_ARRAY = 100;
	char longarray[LONG_ARRAY];
 	int usedlong = 0;
 
	//Declare a short array of size 4, and a companion variable for the number of used elements.
	const int SHORT_ARRAY = 4;
	char shortarray [SHORT_ARRAY];
	int usedshort = 0;

	//Declare the counters 
    int tie_count = 0;//stores the number of ties
    int cpu_win_count = 0;//stores the number of wins by the cpu
    int user_win_count = 0;//stores the number of losses by the cpu or the number of wins by the user
	
    	 //Print a welcome message
    	 cout << "\t**************************" <<endl;
    	 cout << "\t*Rock, Paper and Scissors*" <<endl;
    	 cout << "\t**************************" <<endl;
      
   	 	user_choice= readchoice(); //validates user input and askes user to make a choice
     
    	 while (user_choice!= 'Q')//While the user does not enter Q
     {
     	evaluatechoices(user_choice,cpu_choice, tie_count,cpu_win_count, user_win_count);//Compares user and pc choice to declare the winner, and update the counters.
        	 
         	//Add the user choice to the long and short array.
		 	add2list(user_choice,  longarray, LONG_ARRAY, usedlong);//long array
		 	add2list(user_choice, shortarray, SHORT_ARRAY, usedshort);//short array
		 
			cpu_choice= make_choice(longarray, usedlong, shortarray,usedshort);//Make a new choice for the next round.
         
     		user_choice=readchoice();//validates user input and askes user to make a choice
	}     //End While
		system("COLOR 71");//changes screen to white so that it is visble that the User pressed Q
		system("CLS");//clears screen
     	cout << "\n\t\tTHANK YOU FOR PLAYING :)" <<endl;//prints thank you note
return 0;
}//end of function main

//FUNCTIONS

char readchoice() //validates user input and askes user to make a choice
{
	char user_choice;
	
		system ("color 0F");//Color White signifies that input is valid
	
		cout << "\nMake your choice [R,P,S]. Enter Q to Quit. "; //askes user to make choice
		cin >> user_choice;//promotes user to enter a choice 

		//Validating input to R,S,P and Q
		while (user_choice != 'R'&& user_choice != 'P' && user_choice != 'S'&& user_choice != 'Q')
		{
				system ("color 0C");//Color Red signifies that input is invalid
				cout << "\nInvalid option. Please Try Again.\n"; 
				cout << "\nMake your choice [R,P,S]. Enter Q to Quit. ";
				cin  >> user_choice;//promotes user to enter a choice 
		
		}
return user_choice;
}//end of readchoice
	
char random4rps() //Function for Random Function
{
	int random_choice; //intilizing random choice to int
	char cpu_choice;//intilizing cpu choice to char
	
		random_choice = rand() % 3;//randomnizes numbers between 0 to 3
		
		if (random_choice == 0)
		{
			cpu_choice = 'R';
		}
		
		else if (random_choice == 1)
		{
			cpu_choice = 'P';
		}
			
		else
		{
			cpu_choice = 'S';
		}
return cpu_choice;
}//end of random4rps function
	
void evaluatechoices(char user_choice, char cpu_choice, int& tie_count,int& cpu_win_count, int& user_win_count)//function to compare winning conditions and lossing condtions
{
		cout <<"My Choice was : " <<cpu_choice; // printing program choice
	
		if (user_choice == cpu_choice) //Tie Condtion if cpu and user selects the same thing
		{
			cout <<" Its a Tie"<<endl;//printing tie
			tie_count ++;//counting the number of ties 
		}
		
		else if (user_choice == 'R' && cpu_choice == 'P') //Program Win Condition if user selects rock and cpu paper
		{
			cout << " I win!" << endl;//Printing win for cpu
			cpu_win_count ++;//counting the number of wins for cpu 
		}
		
		else if (user_choice =='P' && cpu_choice == 'S')//Program Win Condition if user selects paper and cpu Scissors
		{
			cout << " I win!" << endl;//Printing win for cpu
			cpu_win_count ++;//counting the number of wins for cpu 
		}
		
		else if (user_choice == 'S' && cpu_choice == 'R')//Program Win Condition if user selects scissors and cpu rock
		{
			cout << " I win!" << endl;//Printing win for cpu
			cpu_win_count ++;//counting the number of wins for cpu 
		} 
		
		else//User Win Condition 
		{
			cout << ". You Win!" << endl;//Printing win for User
			user_win_count ++;//counting the number of wins for user 
		}
					// printing our Scores
	cout << "\nMy Score is :"<<cpu_win_count<<" Wins";
	cout << "," <<tie_count<<" Ties";
	cout << ","<<user_win_count<<" Losses.";
	cout<<endl;

}//end of evaluatechoices function

char selectRPS(int rocks,int papers ,int scissors)//This function selects R, P or S based on the counters rocks, papers and scissors. 
{

char cpu_choice;

	
		if (rocks==papers && rocks==scissors)//(a == b && a == c) transitivity rule
		{	
			srand(time(0));//use current time as seed for random generator
			cpu_choice=random4rps();// cpu choice intilized to random function	
		}

	   	else if (rocks>=papers && rocks>=scissors) 
	 		{
	 			cpu_choice='P';
			}	
		
		else if (papers >=scissors && papers>=rocks )
		{
			cpu_choice='S';
		}
		
		else
		{
			cpu_choice='R';
		}
		
return cpu_choice;
} //end of function selectRPS
					
void add2list(char element,char array[],int capacity,int& used)//This function inserts a new element at position 0 of an array of size capacity, and update the number of used element in the array accordingly
{
  	for (int i = capacity -1; i<0; i--)//For index i from capacity - 1 to 1 copy element i-1 to element i. 
 	
	 {
 		array[i] = array[i-1];
	
		if (used< capacity)
	
		{
		 used++;
		}	
 	
	 }
 	
}//end of function add2 list

char make_choice(char longlist[],int usedlong,char shortlist[],int usedshort)//Function to compares the short list with the long list, to be able to choose whether to play R, P or S next
{

    int rockcounter = 0;//rock counter
    int papercounter = 0;//paper counter
    int scissorscounter = 0;//scissors counter
     
    do{                
     
         for(int i = 1; i< (usedlong-usedshort+1);i++){
             bool match = true; 
             
                     
             for(int j=0;j<usedshort;j++){            
                if(shortlist[j]!=longlist[i+j]){
                    match = false;                
                }           
            }//endfor
        
            if(match){
                if(longlist[i-1]=='R'){
                    rockcounter++;
                }
                else if(longlist[i-1]=='P'){
                    papercounter++;
                }
                else {
                    scissorscounter++;
                }
            }//endif
         }//endfor
         
         usedshort--;//Try with a shorter short list;
         
    }while(usedshort>0 &&  rockcounter == 0 &&  papercounter == 0 &&  scissorscounter == 0);
     
    char user_choice = selectRPS(rockcounter,papercounter,scissorscounter);//calling selectrps function 

    return user_choice;//returns user choice
}	
