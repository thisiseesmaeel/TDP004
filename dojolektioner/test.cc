#include <iostream>

class Square
{
	private:
		int length = 4;
	
	public:
		Square(int l)
		{
			length = l;
		}
		
		void setlength(int l)
			{
			length = l;
			};
	
		int getarea()
			{
			return length*length;
			};
};
		
int main()
{
	Square square1{5};
	
	std::cout << square1.getarea() << "\n";
	return 0;
}
