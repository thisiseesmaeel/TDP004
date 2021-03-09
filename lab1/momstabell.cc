#include <iomanip>
#include <iostream>

// KlaAr36: Helhet: Snyggt och lättläst. Bra jobbat!

// KlaAr36: Komplettering: 8-8 följande inmatning (som programmet godkänner!) ger ingen tabell
/* Följande exempel visat två saker i ett:
   - Rimplighetskontrollen på sista pris kan göras smartare, så det alltid blir en tabell
   - Utmatningen av minsta steglängd 0.01 kontrolleras inte rätt, det går mata in mindre
   
INMATNINGSDEL
============
Mata in första pris: 10
Mata in sista pris: 0
Mata in steglängd: -1
Steglängd måste vara minst 0.01
Mata in steglängd: 0.0000005
Mata in momsprocent: 25

MOMSTABELLEN
============
        Pris            Moms        Pris med moms
-------------------------------------------------
*/


// KlaAr36: Komplettering: 1-11 funktioner deklareras på global nivå i C++, före definitioner av huvudprogram och andra funktioner (undantag: lambdafunktioner skrivs där de behövs i koden)

// KlaAr36: Komplettering: 2-8 använd srd:cerr för felmeddelanden

// KlaAr36: Kompletering: utför sammanhängande unmatning i en sats med lämplig radrytning, exempel
//          cout << "abc" << ...
//               << "def" << ...
//               << endl;

using namespace std;

float tax_prices_calculation(float prices_without_taxes, float tax_percentage);
float prices_with_taxes_calculation(float prices_without_taxes, float tax_prices);

int tax_table(float first_price, float final_price, float step, float tax_percentage)
{	
	float prices_without_taxes{first_price};
	float tax_prices{};
	float prices_with_taxes{};
	
	cout << "MOMSTABELLEN" << endl;
	cout << setfill('=') << setw(13) << setprecision(2) << fixed << "\n";
	
// KlaAr36: Komplettering: 1-4 radbryt på lämpligt sätt
	cout << setfill(' ') << setw(12) << "Pris";
	cout << setfill(' ') << setw(16) << "Moms";
	cout << setfill(' ') << setw(21) << "Pris med moms" << "\n";	
	cout << setfill('-') << setw(50) << "\n";
	
// KlaAr36: Är while bästa valet av loop?
//          Det vore ännu bättre att använda heltal för att räkna
//          antal varv. Flyttal kan inte lagras exakt i datorn, så
//          'step' kommer att ha ett litet avrundningsfel som för
//          varje addition i loopen blir större så antal rader och
//          beräknade värden i slutet av tabellen blir fel.
//
//          OBS! Fundera gärna på detta, men ni behöver inte fixa!
//               Exempel längst ned.

// KlaAr36: Komplettering: 4-3 manipulatorer med permanent effekt
//          behöver bara utföras en gång (inte varje varv i loopen)
	while (prices_without_taxes <= final_price)
	{
		tax_prices = tax_prices_calculation(prices_without_taxes, tax_percentage);
		prices_with_taxes = prices_with_taxes_calculation(prices_without_taxes, tax_prices);
		
		cout << setfill(' ') << setw(12);
		cout << prices_without_taxes;
		cout << setfill(' ') << setw(16);
		cout << tax_prices;
		cout << setfill(' ') << setw(21);
		cout << prices_with_taxes;
		cout << "\n";
		
		prices_without_taxes = prices_without_taxes + step;
	}
	
	return 0;
}

// KlaAr36: Behövs så många tomrader här? Räcker inte en eller två?
float tax_prices_calculation(float prices_without_taxes, float tax_percentage)
{
// KlaAr36: Komplettering: 4-1 undvik onödiga variabler, det går bra att direkt returnera uträkningen
	return prices_without_taxes * (tax_percentage / 100);
}

float prices_with_taxes_calculation(float prices_without_taxes, float tax_prices)
{
// KlaAr36: Komplettering: 4-1 undvik onödiga variabler, det går bra att direkt returnera uträkningen
	return prices_without_taxes + tax_prices;
}

int main()
{
// KlaAr36: Komplettering: 1-1 en variabel per rad och ge initialvärde, default {} duger
	float first_price{};
	float final_price{};
	float step{};
	float tax_percentage{};
	
	cout << "INMATNINGSDEL" << endl;
	cout << setfill('=') << setw(13) << "\n";
	
// KlaAr36: Bra! Snyggt skriven inmatningsloop.
	cout << "Mata in första pris: ";
	cin >> first_price;
	while (first_price < 0)
	{
		cerr << "FEL: Första pris måste vara minst 0 (noll) kronor" << endl;
		
		cout << "Mata in första pris: ";
		cin >> first_price;
	}
	
// KlaAr36: Bra! Snyggt skriven inmatningsloop. Vänta! Är inte strukturen väldigt lik ovan inmatning?
	cout << "Mata in sista pris: ";
	cin >> final_price;
	while (final_price < first_price) // KlaAr36: Det är rimligt kräva final_price är större än ... vad?
	{
		cerr << "FEL: Sista pris måste vara minst 0 (noll) kronor" << endl;
		
		cout << "Mata in sista pris: ";
		cin >> final_price;
	}
	
// KlaAr36: Bra! Snyggt skriven inmatningsloop. Stopp! Går det undvika upprepa samma kodstruktur om igen på något sätt?
	cout << "Mata in steglängd: ";
	cin >> step;
	while (step < 0)
	{
// KlaAr36: Komplettering: Utmatningen stämmer inte med villkoret, se exempel högst upp.
		cerr << "Steglängd måste vara större än 0" << endl;
		
		cout << "Mata in steglängd: ";
		cin >> step;
	}
	
// KlaAr36: Bra! Snyggt skriven inmatningsloop. Ej krav, men kan ni få ihop en funktion så ni slipper upprepa samma kodstruktur 4 ggr? Ok att slopa kontrollen "tax_percentage > 100" i så fall.
	cout << "Mata in momsprocent: ";
	cin >> tax_percentage;
	while (tax_percentage < 0 || tax_percentage > 100)
	{
		cerr << "Momsprocent måste vara mellan 0 till 100" << endl;
		
		cout << "Mata in momsprocent: ";
		cin >> tax_percentage;
	}
	
	cout << endl;
	tax_table(first_price, final_price, step, tax_percentage);
	
	return 0;
}

// Klaar36: Exempelkörning som visar på problemet med avrundningsfel:
//          Startat programmet och räknar raderna istället för att skriva ut dem.
//          Det borde vara minst 10 000 000 rader, eller hur?
//          Men det blev bara 9 296 512, det fattas alltså drygt 700 000 rader!
/*
  $ ./a.out | wc -l
  0
  1000000
  .1
  25
  9296511
*/

// KlaAr36: Utskrivt av enbart de sista raderna, se hur sista
//          decimalen inte är 0 och varje steg går lite mer än 0.1 framåt.
/*
  $ ./a.out | tail
  0
  1000000
  .1
  25
  999998.81        249999.70         1249998.50
  999998.94        249999.73         1249998.62
  999999.06        249999.77         1249998.88
  999999.19        249999.80         1249999.00
  999999.31        249999.81         1249999.12
  999999.44        249999.86         1249999.25
  999999.56        249999.91         1249999.50
  999999.69        249999.92         1249999.62
  999999.81        249999.95         1249999.75
  999999.94        249999.98         1249999.88
*/
