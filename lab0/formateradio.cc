// UTDATERAD

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int heltal, heltal1, heltal2, heltal3, heltal4;
  float flyttal;
  char tecken;
  string strang;


//KÖREXEMPEL 1

// HELTAL

  cout << "Skriv in ett heltal:";
  cin >> heltal;
  cout << "Du skrev in talet: " << heltal << "\n\n";

// FEM HELTAL

  cout << "Skriv in fem heltal: ";
  cin >> heltal >> heltal1 >> heltal2 >> heltal3 >> heltal4;
  cout << "Du skrev in talen: " << heltal << " , " << heltal1 << " , " << heltal2 << " , " << heltal3 << " , " << heltal4 << "\n\n";

// FLYTTAL

  cout << "Skriv in ett flyttal: ";
  cin >> flyttal;
  cout << "Du skev in flyttalet: " << setprecision(5) << flyttal << "\n\n";

// ETT HELTAL OCH ETT FLYTTAL
//precision printar ej ut

  cout << "Skriv in ett heltal och ett flyttal: ";
  cin >> heltal >> flyttal;
  cout << "Du skrev in heltalet: " << setw(10) << heltal << endl;
  cout << "Du skrev in flyttalet: " << setw(5) << setprecision(4) << flyttal << "\n\n";

// ETT FLYTTAL OCH ETT HELTAL
//Andra setfill printar ej ut

  cout << "Skriv in ett flyttal och ett heltal: ";
  cin >> flyttal >> heltal;
  cout << "Du skrev in heltalet: " << setfill('-') << setw(8) << heltal << endl;
  cout << "Du skrev in flyttalet: " << setfill('-') << setw(4) << flyttal << "\n\n";

// TECKEN

  cout << "Skriv in ett tecken: ";
  cin >> tecken;
  cout << "Du skrev in tecknet: " << tecken << "\n\n";

// STRÄNG
  
  cout << "Skriv in en sträng: ";
  cin >> strang;
  cout << "Strängen " << "'" << strang << "'" << " har 5 tecken." << "\n\n";

// HELTAL OCH STRÄNG

  cout << "Skriv in ett heltal och en sträng: ";
  cin >> heltal >> strang;
  cout << "Du skrev in talet " << "|" << heltal << "|" << " och strängen " << "|" << strang << "|." << "\n\n";

// STRÄNG OCH FLYTTAL

  cout << "Skriv in en sträng och ett flyttal: ";
  cin >> flyttal >> strang;
  cout << "Du skrev in " << '"' << setprecision(4) << flyttal << '"' << " och " << '"' << strang << '"' << "\n\n";

// RAD

  cout << "Skriv in en hel rad med text:" << endl;
  cin >> strang;
  cout << "Du skrev in textraden: " << "'" << strang << "'" << "\n\n";

// RAD SOM SLUTAR MED ETT NEGATIVT HELTAL

  cout << "Skriv in en textrad som slutar med ett negativt heltal:" << endl;
  cin >> strang >> heltal;
  cout << "Du skrev in textraden: " << "'" << strang << ",  '" << " och heltalet " << "'" << heltal << "'" << "\n\n";



//KÖREXEMPEL 2

  cout << "Skriv in ett heltal: " << endl;
  cin >> heltal;
  cout << "Du skrev in talet: " << heltal << "\n\n";


  cout << "Skriv in fem heltal: " << endl;
  cin >> heltal;
  cout << "Du skrev in talen: " << heltal << "," << heltal << "," << heltal << "," << heltal << "," << heltal << "\n\n";


  cout << "Skriv in ett flyttal: " << endl;
  cin >> flyttal;
  cout << "Du skrev in flyttalet: " << setprecision(5) << flyttal << "\n\n";



  cout << "Skriv in ett heltal och ett flyttal: " << endl;
  cin >> heltal >> flyttal;
  cout << "Du skrev in heltalet: " << setprecision(10) << heltal << endl;
  cout << "Du skrev in flyttalet:    " << flyttal << "\n\n";

  
  cout << "Skriv in ett flyttal och ett heltal: " << endl;
  cin >> heltal >> flyttal;
  cout << "Du skrev in heltalet: " << setfill('-') << setw(8) << heltal << endl;
  cout << "Du skrev in flyttalet: " << setfill('-') << setw(4) << flyttal << "\n\n";



  cout << "Skriv in ett tecken:         " << endl;
  cin >> tecken;
  cout << "Du skrev in tecknet: " << tecken;


  cout << "Skriv in en sträng: " << endl;
  cin >> strang;
  cout << "Strangen " << "'" << strang << "'" << "har 6 tecken.";

  cout << "Skriv in ett heltal och en sträng:  ";
  cin >> heltal >> strang;
  cout << "Du skrev in talet " << "|" << heltal << "|" << " och strängen " << "|" << strang << "|." << "\n\n";


  cout << "Skriv in en sträng och ett flyttal: " << endl;
  cin >> flyttal >> strang;
  cout << "Du skrev in " << '"' << flyttal << '"' << " och " << '"' << strang << '"' << "\n\n";


  cout << "Skriv in en hel rad med text: " << endl;
  cin >> strang;
  cout << "Du skrev in textraden: " << "'" << strang << "'" << "\n\n";


  cout << "Skriv in en textrad som slutar med ett negativt heltal: " << endl;
  cin >> heltal;
  cout << "Du skrev in textraden: " << "' " << heltal << " ' " << " och heltalet " << "'" << heltal << "'" << "\n\n";


  return 0;

}
