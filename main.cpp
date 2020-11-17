#include <iostream>
#include <vector>
#include "Board.h"
int main()
{
	Board x;
	Board y;
	
	std::cout << x;

	auto l=x.generate();
	for (auto i : l)
	{
		std::cout << std::endl << std::endl << std::endl;
		i.print();
		std::cout<<i.get_col()<<std::endl;
		std::cout<<i.get_last().first<<"  "<< i.get_last().second << std::endl;
	}
}