
#include "Static_Evaluator.h"

double Static_Evaluator::operator()(const Board& b) const
{
	auto data = b.getBoard();
	double eval{ bonus };
	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j)
			eval += data[i][j];
	return eval;
}
