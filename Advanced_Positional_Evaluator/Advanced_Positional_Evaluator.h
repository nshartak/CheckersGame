#pragma once
#include "Positional_Evaluator.h"
class Advanced_Positional_Evaluator :
    public Positional_Evaluator
{
public:
    Advanced_Positional_Evaluator(double w=1, double b=0) : Positional_Evaluator{ w, b } {}
    virtual double operator()(const Board&) const override;
};
