#include "Positional_Evaluator.h"
#include "Board.h"
double Positional_Evaluator::operator()(const Board& b) const
{
    
    auto data = b.getBoard();
    double val = Material_Evaluator::operator()(b);//take the previous estimate
    for (int i = 0; i < 4; ++i)//check if we have a white pawn advanced
    {
        for (int j = 0; j < 8; ++j)
        {
            if (data[i][j] == 1)
                val += 0.2;
        }
    }

    for (int i = 4; i < 8; ++i)//check if we have a black pawn advanced
    {
        for (int j = 0; j < 8; ++j)
        {
            if (data[i][j] == -1)
                val -= 0.2;
        }
    }


    return val;
}
