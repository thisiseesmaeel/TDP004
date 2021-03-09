// Denna fil ska innehålla deklarationer för de typer och funktioner
// som behövs

#ifndef TIME_H
#define TIME_H
#include <iostream>
#include <string>

// Komplettering: Det finns ingen funktion som kontrollerar om detta är ett giltigt klockslag

class Time {
private:

    // Komplettering: 7-1
   int hours{0};
   int minutes{0};
   int seconds{0};
		
public:
   Time() {};

    // Komplettering: Använd medlemsinitieringslistan för att initiera datamedlemmar
    // Undvik att göra tilldelningar i konstruktorns kropp
	 Time(int h, int m, int s) : hours{h}, minutes{m}, seconds{s} {
      // Komplettering: Kompilerar ej, ni verkar ha klistrat in något här.
	 }
	 
	 //is_valid()
	 bool is_valid() const;
	 
	 //hjälpfunktion till to_string()
	 std::string less_than_ten(int time_metric, std::string& time_metric_string) const;
	 
	 //to_string()
	 std::string to_string(bool b = 0) const;

    // Komplettering: operator+, operator- och ingen av jämförelse
    // operatorerna ska modifiera objektet, så dessa bör vara const.
    
   //operator overload "+"
   Time operator + (int n) const;
   
   //operator overload "-"
   Time operator - (int n) const; 
   
   //operator overload "++" (pre-increment)
   Time& operator ++ ();
 
   //operator overload "++" (post-increment)
   Time operator ++ (int);
  				
   //operator overload "--" (pre-increment)
   Time& operator -- ();
		
   //operator overload "--" (post-increment)
   Time operator -- (int);
		
   //operator overload "<"
   bool operator < (const Time &t) const;
	
   //operator overload ">"
   bool operator > (const Time &t) const;
  
   //operator overload "=="
   bool operator == (const Time& t) const; 
	
   //operator overload "!="
   bool operator != (const Time& t) const;
		
   //operator overload ">="
   bool operator >= (const Time &t) const;

   //operator overload "<="
   bool operator <= (const Time &t) const;
  
   //operator overload "<<"
   friend std::ostream& operator << (std::ostream&, const Time&);
 
   //operator overload ">>"
   friend std::istream& operator >> (std::istream&, Time&);
};
   
#endif

