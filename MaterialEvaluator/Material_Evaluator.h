#pragma once
#include "Board.h"
#include "Static_Evaluator.h"
class Material_Evaluator:
	public Static_Evaluator 
{
public:
	Material_Evaluator(double w = 1, double b = 0) :bonus{ b }, weight{w} {};
	virtual double operator()(const Board& b) const override;//just count material
	double getBonus() const
	{
		return bonus;
	}
	void setBonus(double b)
	{
		bonus = b;
	}
	double getWeight() const
	{
		return weight;
	}
	void setWeight(double w)
	{
		weight = w;
	}
private:
	double bonus;//giving one of the sides optional point(s)
	double weight;//weight of each piece
};

