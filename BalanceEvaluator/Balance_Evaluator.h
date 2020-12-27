#pragma once
#include "Static_Evaluator.h"
#include "Board.h"
class Balance_Evaluator:
	public Static_Evaluator//To consider if the pieces are equally distributed in rhs & lhs
{
public:
	Balance_Evaluator(double s = 0.5) :scale{ s } {}
	double operator()(const Board& b)const override;
	double get_scale() const { return scale; }
	void set_scale(double x) {if(x<=1&&x>0) scale = x; }
private:
	double scale;
};

