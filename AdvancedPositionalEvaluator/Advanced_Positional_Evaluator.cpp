#include "Advanced_Positional_Evaluator.h"

double Advanced_Positional_Evaluator::operator()(const Board& b) const
{
    auto data = b.getBoard();
    double val = Material_Evaluator::operator()(b);//take the previous estimate
    for (int i{1}; i < 4; ++i)
    {
        for (int j{}; j < 8; ++j)
        {
            if (data[i][j] == 1)
            {
                val += 0.4 - i * 0.1;
            }
        }
    }
    for (int i{ 6 }; i > 3; --i)
    {
        for (int j{}; j < 8; ++j)
        {
            if (data[i][j] == -1)
            {
                val -= 0.4 -(7.0-i) * 0.1;
            }
        }
    }
    return val;
}
