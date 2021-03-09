#include "Simulator.h"

//IMPLERMENTATIONER

// ----------------------------------------------------------------------

//COMPONENT

std::string Component::get_name() const
{
	return name;
}

double Component::get_voltage() const
{
	if (positive->charge > negative->charge)
	{
		return positive->charge - negative->charge;
	}
	else
	{
		return negative->charge - positive->charge;
	}
}

// ----------------------------------------------------------------------

//BATTERY

double Battery::get_current() const
{
	return 0.0;
}

void Battery::simulate(double)
{
	positive->charge = charge;
	negative->charge = 0.0;
}

// ----------------------------------------------------------------------

//RESISTOR

double Resistor::get_current() const
{
	return get_voltage() / resistance;
}

void Resistor::simulate(double time)
{
	double moved_charge = get_current() * time;

	if (positive->charge < negative->charge)
	{
		positive->charge += moved_charge;
		negative->charge -= moved_charge;
	}
	else
	{
		negative->charge += moved_charge;
		positive->charge -= moved_charge;
	}
}

/*
Antag att resistansen är 2.0 Ohm och vi simulerar i steg om
0.1 tidsenheter. Om laddningen på sida a är 5.0 och laddnigen på sida b är 9.0 
så är spänningen över resistorn 9.0 - 5.0 = 4.0.
Nu flyttas 4.0/2.0 * 0.1 laddningspartiklar från sida b (som ju har högst laddning) till sida a.
*/

// ----------------------------------------------------------------------

//CONDENSATOR

double Condensator::get_current() const
{
	return capacity * (get_voltage() - inner_charge);
}

void Condensator::simulate(double time)
{
	double moved_charge = get_current() * time;

	if (positive->charge > negative->charge)
	{
		negative->charge += moved_charge;
		positive->charge -= moved_charge;
		inner_charge += moved_charge;
	}
	else
	{
		positive->charge += moved_charge;
		negative->charge -= moved_charge;
		inner_charge += moved_charge;
	}
}

/*
Antag att kapacitancen är 0.8 Fahrad och vi simulerar i steg om 0.1 tidsenheter.
Omladdningen på sida a är 5.0 och laddnigen på sida b är 9.0 så är skillnaden 9.0 - 5.0 = 4.0.
Om vi har 3.0 lagrat sedan tidigare så kommer vi nu lagra ytterligare 0.8*(4.0-3.0)*0.1.
Dessa tas från sidan med högst laddning och läggs till både internt och på andra sidan.
*/

// ----------------------------------------------------------------------

