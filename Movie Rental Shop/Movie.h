
#include <string>
using namespace std;
#ifndef MOVIE_H //preprocessor to avoid multiple declarations of date class
#define MOVIE_H
class Movie{
      
  private:
  string ID;
  string Mname;
  string Genre;
  float Cost;
  string Rating;
  string Year_Release;
  string Director;
  
  public:
   Movie();
   
   string getID();
   string getMname();
   string getGenre();
   float getCost();
   string getRating();
   string getYearRelease();
   string getDirector();
   
   void setMovie(string ID, string Mname,string Genre,float Cost,string Rating,string Year_Release,string Director);

//	void setID(string ID);
//	void setMname(string Mname);
//	void setGenre(string Genre);
//	void setCost(float Cost);
//	void setRating(string Rating);
//	void setYearRelease(string Year_Release);
//	void setDirector(string Director);   
};
#endif
