#pragma once

#include <string>

//Kommentar: Behöver ni lagra voltage och current? Dessa kan hämtas ut
//via get_voltage och get_current när de behövs.

//TODO: I denna labb ska det finnas en deklarationsfil,
//implementationsfil och main. Sepparera filerna på ett korrekt sätt.

//TODO: Funktioner som inte ändrar på medlemsobjektet ska deklareras
//const.

//TODO: get_voltage() fungerar likadant i alla komponenter. Den
//behöver därför inte vara virtual.

//TODO: Vid felaktig inmatning ska ett instruktivt felmeddelande
//skrivas ut. "invalid arguments" säger inte så mycket. Exempel:
//"Usage: ...".

struct Connection
{
	double charge{};
};

class Component
{
	protected:
	std::string name{};
	Connection* positive{};
	Connection* negative{};
	
	public:
	//CONSTRUCTOR
	Component(std::string name, Connection* p, Connection* n)
	: name{name}, positive{p}, negative{n} {}
	
	//FUNCTIONS
	virtual std::string get_name() const;
	double get_voltage() const;
	virtual double get_current() const = 0;
	virtual void simulate(double time) = 0;
	
	//VIRTUAL DESTRUCTOR
	virtual ~Component() = default;

	//COPY CONSTRUCTOR AND COPY ASSIGNMENT CONSTRUCTOR
	Component(const Component &copy) = delete;
	Component &operator = (const Component &copy) = delete;
	
};

class Battery : public Component
{
	private:
	double charge{};
	
	public:
	//CONSTRUCTOR
	Battery(std::string name, double c, Connection* positive, Connection* negative)
		: Component{name, positive, negative}, charge{c} {}
	
	//FUNCTIONS
	double get_current() const override;
	void simulate(double) override;
	
};

class Resistor : public Component
{
	private:
	double resistance{};
	
	public:
	//CONSTRUCTOR
	Resistor(std::string name, double r, Connection* positive, Connection* negative)
		: Component{name, positive, negative}, resistance{r} {}
	
	//FUNCTIONS
	double get_current() const override;
	void simulate(double time) override;
	
};

class Condensator : public Component
{
	private:
	double inner_charge{};
	double capacity{};
	
	public:
	Condensator(std::string name, double cap, Connection* positive, Connection* negative)
		: Component{name, positive, negative}, capacity{cap} {}
	
	//FUNCTIONS
	double get_current() const override;
	void simulate(double time) override;
};

