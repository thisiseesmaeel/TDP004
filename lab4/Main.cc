#include "Simulator.h"
#include "Simulator.cc"

#include <vector>
#include <iostream>
#include <iomanip>

// ----------------------------------------------------------------------

//SIMULATE

void print_table(std::vector<Component*> vec)
{
	for (Component* comp : vec)
	{
		std::cout << std::setw(4) << "  " << comp->get_voltage() << std::setw(8) << comp->get_current() << " ";
	}
	
	std::cout << std::endl;
}

void print_name(std::vector<Component*> vec)
{
	for (Component* comp : vec)
	{
		std::cout << std::setw(16) << comp->get_name();
	}
	
	std::cout << std::endl;
}

void print_headers(std::vector<Component*> vec)
{
	int size = vec.size();
	
	for (int i = 0; i < size; ++i)
	{
		std::cout << std::setw(9) << "volt" << std::setw(8) << "curr";
	}
	
	std::cout << std::endl;
	std::cout << std::fixed << std::setprecision(2);
}

void simulate(std::vector<Component*> vec, int iterations, int prints, double time)
{
	print_name(vec);
	print_headers(vec);

	for (int i = 1; i <= iterations; i++)
	{
		for (Component* comp : vec)
		{
			comp->simulate(time);
		}

		if (i % (iterations / prints) == 0 && i != 0)
		{
			print_table(vec);
		}
	}
}

// ----------------------------------------------------------------------

//MAIN

int main(int argc, char *argv[])
{
	if (argc != 5)
	{
		std::cerr << "Invalid Arguments: Please write in the correct format" << '\n';
		std::cerr << "Example: ./a.out 200000 10 0.01 24" << '\n';
		return 1;
	}

	int iterations{};
	int prints{};
	double time{};
	double charge{};

	try
	{
		iterations = std::stoi(argv[1]);
		prints = std::stoi(argv[2]);
		time = std::stod(argv[3]);
		charge = std::stod(argv[4]);
	}

	catch (std::invalid_argument v)
	{
		std::cerr << "Invalid input type" << '\n';
		return 1;
	}

	// ----------------------------------------------------------------------

	//RUNNING EXAMPLES
	
	/*
	Connection *p = new Connection;
	Connection *n = new Connection;
	Connection *R124 = new Connection;
	Connection *R23 = new Connection;

	std::vector<Component *> net;
	net.push_back(new Battery("Bat", charge, p, n));
	net.push_back(new Resistor("R1", 6.0, R124, p));
	net.push_back(new Resistor("R2", 4.0, R124, R23));
	net.push_back(new Resistor("R3", 8.0, R23, n));
	net.push_back(new Resistor("R4", 12.0, R124, n));
	simulate(net, iterations, prints, time);
	//simulate(net, 200000, 10, 0.01);

	//for memory leak
	for (Component *comp : net)
	{
		delete comp;
	}

	delete p;
	delete n;
	delete R124;
	delete R23;
	*/
	
	Connection *p = new Connection;
	Connection *n = new Connection;
	Connection *l = new Connection;
	Connection *r = new Connection;

	std::vector<Component *> net;
	net.push_back(new Battery("Bat", charge, p, n));
	net.push_back(new Resistor("R1", 150.0, p, l));
	net.push_back(new Resistor("R2", 50.0, p, r));
	net.push_back(new Resistor("R3", 100.0, l, r));
	net.push_back(new Resistor("R4", 300.0, l, n));
	net.push_back(new Resistor("R5", 250.0, r, n));
	simulate(net, iterations, prints, time);
	//simulate(net, 200000, 10, 0.01);

	//for memory leak
	for (Component *comp : net)
	{
		delete comp;
	}

	delete p;
	delete n;
	delete l;
	delete r;
	
	/*
	Connection *p = new Connection;
	Connection *n = new Connection;
	Connection *l = new Connection;
	Connection *r = new Connection;

	std::vector<Component *> net;
	net.push_back(new Battery("Bat", 24.0, p, n));
	net.push_back(new Resistor("R1", 150.0, p, l));
	net.push_back(new Resistor("R2", 50.0, p, r));
	net.push_back(new Condensator("C3", 1.0, l, r));
	net.push_back(new Resistor("R4", 300.0, l, n));
	net.push_back(new Condensator("C5", 0.75, r, n));
	simulate(net, iterations, prints, time);
	//simulate(net, 200000, 10, 0.01);

	//for memory leak
	for (Component *comp : net)
	{
		delete comp;
	}

	delete p;
	delete n;
	delete l;
	delete r;
	*/
}

//main() i .cc
//g++ -Wall -Wextra -Weffc++ -Wold-style-cast -Woverloaded-virtual -std=c++17 -pedantic -Werror -g Main.cc
//./a.out

//valgrind
//valgrind --tool=memcheck --leak-check=yes ./a.out
