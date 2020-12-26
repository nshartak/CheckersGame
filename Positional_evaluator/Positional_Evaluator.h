#pragma once
#include "Material_Evaluator.h"
class Positional_Evaluator :
    public Material_Evaluator
{
public:
    Positional_Evaluator(double w=1, double b=0) :Material_Evaluator{ w, b } {}
    virtual double operator()(const Board&) const override;
};

