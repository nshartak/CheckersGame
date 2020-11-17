#pragma once
#include "Static_Evaluator.h"
class Positional_Evaluator :
    public Static_Evaluator
{
public:
    Positional_Evaluator(double n) :Static_Evaluator{ n } {}
    virtual double operator()(const Board& b) const override;
};

