//Uppgift 6
//my_map.insert_or_assign("Kaffee", 536);

//Uppgift 7
#include <map>
#include <vector>
#include <iostream>
std::map<std::string, std::vector<int>> my_map { 
															std::pair<std::string, std::vector<int>>{"I", {2, 3}},
															std::pair<std::string, std::vector<int>>{"V", {2, 3}},
															std::pair<std::string, std::vector<int>>{"X", {2, 3}},
															std::pair<std::string, std::vector<int>>{"C", {2, 3}},
															std::pair<std::string, std::vector<int>>{"M", {2, 3}} 
																								};

int main()
{	
	for (auto it = my_map.begin(); it != my_map.end(); it++)
	{
		it->second.insert(it->second.begin(), 1);
		
		for (auto& it2 : it->second)
		{
			std::cout << it2 << " ";
		}
	}
	
	std::cout << std::endl;
	
	return 0;
}

//------------------
/*
PROBLEM
Läs in heltal tills användaren matar in Ctrl-D (filslut). Skriv ut alla UNIKA tal, och hur många gånger de förekom, i stigande ordning.
*/
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	/*
	int nummer{};
	
	map<int, int> number_instances{};
	
	while ( cin >> nummer )
	{
		number_instances[nummer]++;
	}
	
	//för range-loop, element = *first istället för element->first
	for ( auto const& element : number_instances )
	{
		cout << "Key: " << element.first << "Freq: " << element.second << endl;
	}
	
	return 0;
	*/
	
	int nummer{};
	
	vector<int> num_vec{};
	
	while ( cin >> nummer )
	{
		num_vec.push_back{number}
	}
	
	//unique(num_vec.begin(), num_vec.end());
	vector<int> uni{num_vec.begin(), num_vec.end()}
	uni.erase(unique(uni.begin(), uni.end()), uni.end());
	unique_copy(num_vec.begin(), num_vec.end(), back_inserter(uni));
	sort(uni.begin(), uni.end());
	
	cout << endl;
	for ( const int val : uni ) 
	{
		cout << val << " " << count(num_vec.begin(), num_vec.end(), val) << endl;
	}
	
}

/*
$ ./a.out
$ 1 4 5 6 6 7 2 3 <Ctrl-D>
*/

//lärdom: kolla under algoritmer i cppreference!!!!


















