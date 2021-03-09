// I denna fil läggs definitionerna (implementationen) av de funktioner
// som deklarerats i Time.h

#include "Time.h"

// ----------------------------------------------------------------------

bool Time::is_valid() const {
	 if (hours >= 24 || hours < 0) {
      return false;
   }
   else if (minutes >= 60 || minutes < 0) {
      return false;
   }
   else if (seconds >= 60 || seconds < 0) {
      return false;
   }
   
   return true;
}

// ----------------------------------------------------------------------

//hjälpfunktion till to_string()
std::string Time::less_than_ten(int time_metric, std::string& time_metric_string) const {
	 if (time_metric < 10) {
      time_metric_string = "0" + time_metric_string;
      return time_metric_string;
   }
   
	 return time_metric_string;
}

// ----------------------------------------------------------------------

// Komplettering: Strängen är på fel format. Den ska skriva ut
// HH:MM:SS[ p] men ni skriver ut det på [HH:MM:SS[ p]]

std::string Time::to_string(bool b) const {
   std::string s, m, h;
			
   s = std::to_string(seconds);
   m = std::to_string(minutes);
   h = std::to_string(hours);

   // Komplettering: Detta är samma kod för s, m och h. Bryt ut det i en funktion
   less_than_ten(seconds, s);
   less_than_ten(minutes, m);
   less_than_ten(hours, h);

   // Komplettering: Kodupprepning, ta ut de gemensamma delarna för
   // alla fallen och gör bara if-satsen för de delarna som skiljer sig.
	 
	 std::string time = h + ":" + m + ":" + s;
	 
	 if (b == true) {
      if (hours < 12) {
         return time + " am";
      }
      else {
         return time + " pm";
      }
   }
   
	 return time;
}

// ----------------------------------------------------------------------

Time Time::operator + (int n) const {
   Time new_time = Time(hours, minutes, seconds + n);
			
   while (new_time.seconds >= 60) {
      new_time.minutes = new_time.minutes + 1;
      new_time.seconds = new_time.seconds - 60;
   }
			
   while (new_time.minutes >= 60) {
      new_time.hours = new_time.hours + 1;
      new_time.minutes = new_time.minutes - 60;
   }
			
   while (new_time.hours >= 24) {
      new_time.hours = new_time.hours - 24;
   }
	 
   return new_time;
}

// ----------------------------------------------------------------------

Time Time::operator - (int n) const {
   Time new_time = Time(hours, minutes, seconds - n);
			
   while (new_time.seconds < 0) {
      new_time.minutes = new_time.minutes - 1;
      new_time.seconds = new_time.seconds + 60;
   }
			
   while (new_time.minutes < 0) {
      new_time.hours = new_time.hours - 1;
      new_time.minutes = new_time.minutes + 60;
   }
			
   while (new_time.hours < 0) {
      new_time.hours = new_time.hours + 24;
   }
			
   return new_time;
}

// ----------------------------------------------------------------------

// Komplettering: Mer komplicerat än det behöver vara.
// Kan ni använda operator+ på något sätt för att försimpla detta?
Time& Time::operator ++ () {
   *this = *this + 1;
   return *this;
}

// ----------------------------------------------------------------------

// Kommentar: Mycket bra!
Time Time::operator ++ (int) {
	 const Time old(*this);
	 ++(*this);
   return old;
}

// ----------------------------------------------------------------------

// Komplettering: Samma som ovan: kan ni använda operator-?
Time& Time::operator -- () {
   *this = *this - 1;
   return *this;
}

// ----------------------------------------------------------------------

Time Time::operator -- (int) {
   const Time old(*this);
	 --(*this);
   return old;
}

// ----------------------------------------------------------------------

bool Time::operator < (const Time &t) const {
   if (seconds < t.seconds) {
      return true;
   }
   else if (minutes < t.minutes) {
      return true;
   }
   else if (hours < t.hours) {
      return true;
   }
   else {
      return false;
   }
}
  
// ----------------------------------------------------------------------


// Komplettering: Otroligt snarlikt operator<, kan ni använda operator< för att implementera operator> på?
// Tips: 1 < 2 samma sak som 2 > 1
bool Time::operator > (const Time &t) const {
   return t < *this;
}

// ----------------------------------------------------------------------

bool Time::operator == (const Time& t) const {
   return (hours == t.hours && minutes == t.minutes && seconds == t.seconds);
}

// ----------------------------------------------------------------------

bool Time::operator != (const Time& t) const {
   return !(*this == t);
}
	
// ----------------------------------------------------------------------

// Komplettering: Väldigt snarlikt operator< och operator>.
// Kan ni använda några andra operatorer för att implementera >= och <= ?

bool Time::operator >= (const Time &t) const {
   return !(*this < t);
}

// ----------------------------------------------------------------------

bool Time::operator <= (const Time &t) const {
   return !(t > *this);
}

// ----------------------------------------------------------------------

// Kommentar: bra!
std::ostream& operator << (std::ostream& os, const Time& t) {
   os << t.to_string();
   return os;
}

// ----------------------------------------------------------------------

// Komplettering: Ni saknar dokumentation som beskriver när felet upptäcks.

// Komplettering: Ni läser inte in på rätt format. Det ska vara HH:MM:SS,
// men ni läser in [HH:MM:SS].
std::istream& operator >> (std::istream& lhs, Time& rhs) {
   int h;
   int m;
   int s;
   char colon;
	 
   lhs >> h >> colon >> m >> colon >> s;
	 
	 //om felflagga har sätts kommer fail() att returnera true i testning
	 //felflagga sätts om timmar (h) är 24 timmar eller större
   if (h >= 24) {
      lhs.setstate(std::ios::failbit);
   }
	 //felflagga sätts om minuter (m) är 60 timmar eller större
   else if (m >= 60) {
      lhs.setstate(std::ios::failbit);
   }
	 //felflagga sätts om sekunder (s) är 60 timmar eller större
   else if (s >= 60) {
      lhs.setstate(std::ios::failbit);
   }
	 //om inga av dessa instanser händer är tiden giltig
	 
   return lhs;
}

