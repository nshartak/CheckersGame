#include "Centrality_Evaluator.h"

double Centrality_Evaluator::operator()(const Board& b) const
{
	
	//The influence of checkers on the center of the board.
	double res{};
	auto data = b.getBoard();
	for (int i = 2; i <= 5; ++i)
	{
		for (int j = 2; j <= 5; ++j)
		{
			//black pieces
			if (data[i - 1][j - 1] == -1)
				res -= point;
			if (data[i - 1][j + 1] == -1)
				res -= point;
			//white pieces
			if (data[i + 1][j - 1] == 1)
				res += point;
			if (data[i + 1][j + 1] == 1)
				res += point;

		}
	}
	return res;
}
