#include <iostream>
#include <vector>
#include "Board.h"
#include "Positional_Evaluator.h"
#include "Material_Evaluator.h"
#include "Advanced_Positional_Evaluator.h"
#include "Estimator.h"
#include "Game.h"
#include <bitset>
#include <chrono>
int main()
{
	
	
	/*auto start = std::chrono::high_resolution_clock::now();
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "\n \n" << duration.count() << "\n \n";*/
	
	Game g{true, 8};
	while (!g.get_state())
	{
		std::cout << g << std::endl;
		std::string s;
		std::getline( std::cin, s);
		g.make_move(s);
	}
	std::cout << g;
	
}