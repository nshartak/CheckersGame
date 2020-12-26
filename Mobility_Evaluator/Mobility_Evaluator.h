#pragma once
#include "Static_Evaluator.h"
class Mobility_Evaluator :
    public Static_Evaluator
{
public:
    Mobility_Evaluator(double d = 30.0) : den{ d } {}
    double operator()(const Board& b)const override;
    double get_scale() const { return den; }
    void set_scale(double d)
    {
        if (d > 0)
            den = d;
    }
private:
    double den;//The scale to divide
};

