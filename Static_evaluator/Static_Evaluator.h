#pragma once
#include "Board.h"
class Static_Evaluator
{
public:
	Static_Evaluator(double b = 0) :bonus{b} {};
	virtual ~Static_Evaluator() {};
	virtual double operator()(const Board& b) const;//just count material
	
private:
	double bonus;//giving one of the sides optional point(s)
};

