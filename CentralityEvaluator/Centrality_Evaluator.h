#pragma once
#include "Static_Evaluator.h"
class Centrality_Evaluator :
    public Static_Evaluator
{
public:
    Centrality_Evaluator(double p = 0.03) : point{ p } {}
    double operator()(const Board& b)const override;
    double get_point()const { return point; }
    void set_point(double p)
    {
        if (p >= 0 && p <= 1)
            point = p;
    }
private:
    double point;
};

