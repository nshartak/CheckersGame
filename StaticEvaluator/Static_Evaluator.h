#pragma once
#include "Board.h"
class Static_Evaluator
{
public:
	virtual ~Static_Evaluator() {};
	virtual double operator()(const Board& b) const=0;
};

