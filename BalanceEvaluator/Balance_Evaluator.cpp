#include "Balance_Evaluator.h"
#include <cstdlib>
double Balance_Evaluator::operator()(const Board& b) const
{
    auto data = b.getBoard();
    //How equally the pieces are distributed on the left and right sides of the board
    double wlhs{}, blhs{}, wrhs{}, brhs{};
    for (int i{}; i <= 7; ++i)//how many pieces of corresponding color are in lhs
    {
        for (int j{}; j <= 3; ++j)
        {
            if (1==data[i][j])
                ++wlhs;
            if (-1==data[i][j])
                ++blhs;
        }
    }
    for (int i{}; i <= 7; ++i)
    {
        for (int j{ 4 }; j <= 7; ++j)
        {
            if (1 == data[i][j])
                ++wrhs;
            if (-1 == data[i][j])
                ++brhs;
        }
    }
    if ((wrhs + wlhs) == 0 || (brhs + blhs) == 0)return 0;
    double w1 = wlhs / (wrhs+wlhs);
    double w2= wrhs / (wrhs + wlhs);
    double b1 = blhs / (brhs+blhs);
    double b2 = brhs / (brhs + blhs);
    double white = abs(w1-w2);
    double black = abs(b1-b2);
    return scale*(black-white);
}
