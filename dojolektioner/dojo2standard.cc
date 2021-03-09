//Uppgift 1
#include <map>
//går att skriva const std::map också om den ska vara konstant
//går att skriva std::pair<char, int>{'I', 1} också, bättre t.o.m. då den är mer explicit
std::map<char, int> roman_map { {'I', 1}, {'V', 5}, {'X', 10}, {'C', 100}, {'M', 1000} };

//Uppgift 2
#include <iostream>

int roman_to_numbers(std::string roman_numbers)
{
	int length = roman_numbers.length();
	int sum = 0;
	
	for (int i = 0; i < length; i++)
	{
		char roman_key = roman_numbers[i];
		
		if ((i != length-1) && (roman_key == 'I') && (roman_numbers[i+1] != 'I'))
		{
			sum = sum - 1;
		}
		else
		{
			sum = sum + roman_map[roman_key];
		}
		//std::cout << roman_map[roman_key] << std::endl;
		//std::cout << sum << std::endl;
	}
	
	std::cout << sum << std::endl;
	return 0;
}

int main()
{
	std::string idk = "XXXVII";
	roman_to_numbers(idk);
	return 0;
}

//Uppgift 3, 4
//include previous #includes
int numbers_to_roman(int numbers)
{
	std::string result;
	
	while (numbers > 0)
	{
		//std::cout << "inside while" << std::endl;
		
		if (numbers - roman_map['M'] >= 0)
		{
			numbers = numbers - roman_map['M']; //1000
			result = result + 'M';
			//std::cout << "inside M" << std::endl;
		}
		else if (numbers - roman_map['C'] >= 0)
		{
			numbers = numbers - roman_map['C']; //100
			result = result + 'C';
		}
		else if (numbers - roman_map['X'] >= 0)
		{
			numbers = numbers - roman_map['X']; //10
			result = result + 'X';
		}
		else if (numbers - roman_map['V'] >= 0)
		{
			numbers = numbers - roman_map['V']; //5
			result = result + 'V';
		}
		else if (numbers - roman_map['I'] >= 0)
		{
			numbers = numbers - roman_map['I']; //1
			result = result + 'I';
		}
	}
	
	std::cout << result << std::endl;
	return 0;
}

/*
int main()
{
	int idk = 2013;
	numbers_to_roman(idk);
	return 0;
}
*/

//saknar funktionalitet för IV/IX















