
#include "Material_Evaluator.h"

double Material_Evaluator::operator()(const Board& b) const
{
	auto data = b.getBoard();
	double eval{ bonus };
	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j)
			eval += data[i][j]*weight;
	for (int i = 0; i < 8; ++i)
	{
		//if there is a promoted pawn it is game over
		if (data[0][i] == 1)
			eval += 1000;
		if (data[7][i] == -1)
			eval -= 1000;
	}
	return eval;
}
