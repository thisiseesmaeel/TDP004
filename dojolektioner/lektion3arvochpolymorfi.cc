//Uppgift 1 (UTAN KONSTRUKTOR OCH IF)
//Uppgift 2 (UTAN STD::DESCRIPTION DESCRIPTION OCH INCLUDES)
//Uppgift 3 

//.h

#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include <string>

class Vehicle
{
	private:
	int tires; //can be 0, yet can always move from A to B lol
	float top_speed;
	
	public:
	Vehicle(int t, float t_s) {
		if (t >= 6) {
			tires = t;
			top_speed = 100;
		}
		else {
			tires = t;
			top_speed = t_s;
		}
	}
	
	void drive(Point const& a, Point const& b);
	
	virtual std::string description() const {
		return std::cout << "En sak för att transportera" << "\n";
	}
	
}

#endif

#ifndef CAR_H
#define CAR_H

class Car : public Vehicle
{
	private:
	int seats;
	int passangers; //can come and go
	
	public:
	Car(int t, float t_s, int s, int p)
	: Vehicle{t, t_s}, seats{s}, passangers{p} {}
	
	void get_in(int new_passangers);
	void get_out(int exiting_passangers);
	
	std::string description() const override {
		return std::cout << "En bil är ett fordon som transporterar passagerare" << "\n";
	}
	
}

#endif

#ifndef TRUCK_H
#define TRUCK_H

class Truck : public Vehicle
{
	private:
	float max_freight; //can be loaded or unloaded
	
	public:
	Truck(int t, float t_s, int m_f)
	: Vehicle{t, t_s}, max_freight{m_f} {}
	
	void load(float freight_load);
	void unload(float freight_unload);
	
	std::string description() const override {
		return std::cout << "En lastbil är ett fordon som transporterar goods" << "\n";
	}
	
}

#endif




