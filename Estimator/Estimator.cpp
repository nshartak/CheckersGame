#include "Estimator.h"

double Estimator::operator()(const Board& b) const
{
	double res{};
	for (const auto& ev : data)
	{
		res+=(*ev)(b);
	}
	return res;
}

void Estimator::insert(const std::string s)
{
	if (s == "rank")
		data.push_back(std::make_shared<Rank_Evaluator>());
	if(s=="balance")
		data.push_back(std::make_shared<Balance_Evaluator>());
	if (s == "centrality")
		data.push_back(std::make_shared<Centrality_Evaluator>());
	if (s == "mobility")
		data.push_back(std::make_shared<Mobility_Evaluator>());
}
