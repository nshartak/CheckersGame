#pragma once
#include <vector>
#include <iostream>
#include <utility>
#include <list>
#include <bitset>
class Board
{
public:
	typedef std::pair<int, int> mov;
	typedef std::list<Board> positions;
	friend class Game;
	Board();
	positions generate() const;
	mov get_last() const { return last_move; }
	void set_last(mov n) { last_move = n; }
	bool get_col() const { return col; }
	void set_col(bool c) { col = c; }
	void reverse_col() { col = !col; }
	bool operator==(const Board& x) const //Fast version (using bitsets)
	{
		return (col == x.col) && (table == x.table);
	}
	bool operator!=(const Board& x) const
	{
		return !((*this) == x);
	}
	bool equals(const Board& x) const//slower version of equality operator
	{
		return (col == x.col) && (data == x.data);
	}
	int num_of_captures() const
	{
		auto x = generate_captures();
		return x.size();
	}
	int num_of_moves() const
	{
		auto x = generate();
		return x.size();
	}
	
	std::vector<std::vector<int>> getBoard() const;//returns the board(without sentinels)
	friend std::ostream& operator<<(std::ostream& os, const Board& b);
	static mov convert(int a, int b, int c, int d);//converting matrix coordinates to checkers notation
private:
	void print() const;//for debug purpose only
	positions generate_moves() const;
	positions generate_captures() const;
	positions jump(int i, int j, int a, int b, int en1, int en2, std::vector<std::vector<int>> temp) const;
	void normalize();//update the bitset
	std::bitset<32> table;
	std::vector<std::vector<int>> data = std::vector<std::vector<int>>(10, std::vector<int>(10));
	bool col=true;//player's turn, white by default
	mov last_move{ 1,1 };//the last move made(for debug purpose only)
	
	
	
};