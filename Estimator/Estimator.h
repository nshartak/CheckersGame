#pragma once
#include <memory>
#include <vector>
#include "Advanced_Positional_Evaluator.h"
#include "Balance_Evaluator.h"
#include "Board.h"
#include "Centrality_Evaluator.h"
#include "Material_Evaluator.h"
#include "Mobility_Evaluator.h"
#include "Mobility_Evaluator.h"
#include "Positional_Evaluator.h"
#include "Rank_Evaluator.h"
#include "Static_Evaluator.h"
#include <initializer_list>
#include <string>
class Estimator//To Evaluate the position given several positional evaluators
{
public:
	
	Estimator( std::initializer_list<std::string> il = {"rank", "balance", "centrality", "mobility"}, const std::string pos = "advanced")
	{
		if (pos == "material")
			data.push_back(std::make_shared<Material_Evaluator>());
		if (pos == "positional")
			data.push_back(std::make_shared<Positional_Evaluator>());
		if (pos == "advanced")
			data.push_back(std::make_shared<Advanced_Positional_Evaluator>());
		for (auto s : il)
		{
			insert(s);
		}
	}
	double operator()(const Board& b) const;
private:
	typedef Static_Evaluator se;
	std::vector<std::shared_ptr<se>> data;
	void insert(const std::string s);
};

