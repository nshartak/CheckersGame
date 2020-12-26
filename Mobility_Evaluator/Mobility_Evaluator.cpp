#include "Mobility_Evaluator.h"

double Mobility_Evaluator::operator()(const Board& b) const
{
    //The degree to which pieces are free or restricted intheir movements.
    double res{};
    if (b.num_of_moves() == 0)//if there are no moves possible the game is lost
    {
        if (b.get_col())
            res -= 1000;
        else
            res += 1000;
    }
    double sum = b.num_of_moves()/den;
    if (b.get_col())
        res += sum;
    else
        res -= sum;
    return res;
}
