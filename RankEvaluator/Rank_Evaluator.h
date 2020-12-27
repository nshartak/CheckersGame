#pragma once
#include "Static_Evaluator.h"
class Rank_Evaluator :
    public Static_Evaluator
{
public:
    virtual double operator()(const Board&) const override;
};

