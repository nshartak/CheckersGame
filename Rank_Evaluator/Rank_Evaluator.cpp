#include "Rank_Evaluator.h"

double Rank_Evaluator::operator()(const Board& b) const
{
    auto data = b.getBoard();
    double val{ 0 };
    for (int i = 1; i < 8; i+=2)//penalty if the front black pieces were moved 
    {
        if (data[0][i] != -1)
        {
            val += 0.15;
        }
    }
    for (int i = 0; i < 8; i += 2)//penalty if the front white pieces were moved 
    {
        if (data[7][i] != 1)
        {
            val -= 0.15;
        }
    }
    return val;
}
