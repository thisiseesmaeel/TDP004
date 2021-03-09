#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <cctype>
#include <string>
#include <map>
#include <vector>

/* Kompletteringar
* Ni får maximalt använda en loop, oavsett om det är en for, while, do-hile eller range based loop. 
* Parametrar av klasstyp ska aldrig tas som kopior om det inte är absolut nödvändigt, använd const&
*/

/*
./a.out testfil.txt (with flags)
1) add a file through argv and argc and read it
2) filter eligible words
3) clean the words and add them to the vector
4) add the clean words to the map and keep count on their occurrences
5) print the result based on the flags
*/

/*
rules:
1) acceptable before first letter: ( ' "
2) acceptable after last letter: " ' ) ! ? , : ; .
3) word has to be over 3 letters
4) only one 's is acceptable
5) no consecutive - (like un--acceptable) are allowed
6) no other junk in between letters
*/

//FILTER
bool check_beginning(std::string const& word, std::string const& target, std::string const& valid)
{
	bool acceptable{true};

	auto a{word.find_first_of(target, 0)};
	auto b{word.find_first_not_of(valid, 0)};

	if (a != b)
	{
		acceptable = false;
	}

	return acceptable;
}

bool check_end(std::string const& word, std::string const& target, std::string const& valid)
{
	bool acceptable{true};

	auto c{word.find_last_of(target, word.length() - 1)};

	if (c != word.length() - 1)
	{
		auto d{word.find_first_not_of(valid, c + 1)};

		if (d != std::string::npos)
		{
			acceptable = false;
		}
	}
	
	return acceptable;
}

bool check_middle(std::string const& word, std::string const& target)
{
	bool acceptable{true};
	auto special_char{word.find_first_of(target, 0)};
	auto limit{word.find_last_of(target, word.length() - 1)};

	do
	{
		special_char = word.find_first_not_of(target, special_char + 1);

		if (special_char < limit)
		{
			if (word.at(special_char) == '-' && word.at(special_char + 1) != '-')
			{
				continue;
			}
			else if (word.at(special_char) == '\'' && word.at(special_char + 1) == 's' && special_char == limit - 1)
			{
				continue;
			}
			else
			{
				acceptable = false;
			}
		}
	} while (special_char != std::string::npos);

	return acceptable;
}

//CLEANING
std::vector<std::string> clean(std::vector<std::string> & string_vector)
{
	std::vector<std::string>::iterator it{string_vector.begin()};
	std::string word_in_vector;
	
	for_each(string_vector.begin(), string_vector.end(), [&string_vector, &it, &word_in_vector](std::string const& word) {
		word_in_vector = string_vector[0];
		
		if (word_in_vector.find("'s") != std::string::npos)
		{
			word_in_vector.erase(word_in_vector.find("'s"), std::string::npos);
    }
		
		word_in_vector.erase(std::remove_if(word_in_vector.begin(), word_in_vector.end(), [](char character) {		
			return (!std::isalpha(character)) && (character != '-');
		}), word_in_vector.end());
		
		transform(word_in_vector.begin(), word_in_vector.end(), word_in_vector.begin(), ::tolower);
		
		string_vector.erase(it);
		string_vector.push_back(word_in_vector);
	});
	
	return string_vector;
}

std::vector<std::string> check_length(std::vector<std::string> & string_vector)
{
	/* Kommentar: erase( remove_if(vec.begin, vec.end, [](string const& word){ return word.size() < 3;}), 
						 string_vector.end() );
	*/
	string_vector.erase(std::remove_if(string_vector.begin(), string_vector.end(), [](std::string const& word) {
		return word.size() < 3;
	}), string_vector.end());
	
	return string_vector;
}

//MAPPING OCCURENCES
std::map<std::string, int> mapping(std::vector<std::string> const& string_vector)
{
	std::map<std::string, int> result;
	// Kommentar: const & på each_word
	for_each(string_vector.begin(), string_vector.end(), [&result](const std::string & word) {
		result[word] += 1;
	});
	
	return result;
}

//MAIN

int main(int argc, char *argv[])
{
	if (argc <= 1)
	{
		std::cerr << "Error: No arguments given." << std::endl
				  << "Usage: a.out FILE [-a] [-f] [-o N]" << std::endl;
		return 0;
	}

	else if (argc <= 2)
	{
		std::cerr << "Error: Second argument missing or invalid." << std::endl
				  << "Usage: ./a.out FILE [-a] [-f] [-o N]" << std::endl;
		return 0;
	}

	std::ifstream file{argv[1]};
	std::string argument{argv[2]};
	std::string potential_word{};

	std::string alphabet{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	std::string pretrash{"(\'\""};
	std::string posttrash{"\"\')!?,:;."};

	std::vector<std::string> eligible_words{};

	while (file >> potential_word)
	{
		bool beginning(check_beginning(potential_word, alphabet, pretrash));
		bool ending(check_end(potential_word, alphabet, posttrash));
		bool middle(check_middle(potential_word, alphabet));
		bool result{beginning && ending && middle};
		if (result)

		{
			eligible_words.push_back(potential_word);
		}
	}

	// Kommentar: Bra!
	file.close();

	eligible_words = clean(eligible_words);
	eligible_words = check_length(eligible_words);
	std::map<std::string, int> word_list{mapping(eligible_words)};

	//max prints
	auto max_word{std::max_element(word_list.begin(), word_list.end())};
	int max_word_print = (max_word->first).length();

	auto max_number{std::max_element(word_list.begin(), word_list.end(), [](const std::pair<std::string, int> &a, const std::pair<std::string, int> &b) {
		return a.second < b.second;
	})};

	int max_number_print = (std::to_string(max_number->second)).length();

	//flags
	if (argument == "-a")
	{		
		for (auto word_in_list : word_list)
		{
			std::cout << std::left << std::setw(max_word_print + 2) << word_in_list.first << word_in_list.second << std::endl;
		}
	}
	else if (argument == "-f")
	{
		std::vector<std::pair<std::string, int>> f_vector;

		for (auto &it : word_list)
		{
			f_vector.push_back(it);
		}

		std::sort(f_vector.begin(), f_vector.end(), [](std::pair<std::string, int> const& a, std::pair<std::string, int> const& b) {
			return (a.second > b.second);
		});

		for (auto &it : f_vector)
		{
			std::cout << std::right << std::setw(max_word_print) << it.first << std::setw(max_number_print + 2) << it.second << std::endl;
		}
	}
	else if (argument == "-o")
	{
		unsigned N = std::stoi(argv[3]);
		std::string word_line;

		for_each(eligible_words.begin(), eligible_words.end(), [&N, &word_line](std::string const& word) {
			if (word_line.empty())
			{
				word_line += word;
			}
			else if ((word_line.length() + word.length() + 1) < N)
			{
				word_line += " ";
				word_line += word;
			}
			else
			{
				std::cout << word_line << std::endl;
				word_line = word;
			}
		});
		std::cout << word_line << std::endl; //force print last element
	}

	return 0;
}

//g++ wordlist.cc
//./a.out better_example.txt -a
//./a.out better_example.txt -f
//./a.out better_example.txt -o 14
//./a.out better_example.txt -o 9
