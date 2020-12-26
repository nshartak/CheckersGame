#pragma once
#include "Board.h"
#include "Estimator.h"
#include <string>
class Game//The game
{
public:
	Game(bool col = true, int n = 7, Estimator e = Estimator{});
	void make_move(std::string move);
	void set_depth(int n)
	{
		depth = n;
	}
	int get_depth()const
	{
		return depth;
	}
	bool get_state() const
	{
		return state;
	}
	static bool game_over(const Board& b);
	friend std::ostream& operator<<(std::ostream& os, const Game& g);
private:
	bool state = false;
	double alpha_beta(const Board& b,  int dep) const;
	double ab_recursive(const Board& b, int dep, double alpha, double beta) const;
	double minimax(const Board& b, int dep) const;
	double calculate(const Board& b) const;
	Board best_move(const Board& b);
	Board data;//opponent's turn position
	int depth;//the depth for the search
	bool color;//the color of the player
	bool alpha = true;//use alpha_beta or minimax
	Estimator estimate;//static evaluator
	void stop();
};

