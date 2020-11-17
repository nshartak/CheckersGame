#pragma once
#include <vector>
#include <iostream>
#include <utility>
#include <list>
class Board
{
public:
	typedef std::pair<int, int> mov;
	typedef std::list<Board> positions;
	Board();
	positions generate() const;
	mov get_last() const { return last_move; }
	void set_last(mov n) { last_move = n; }
	bool get_col() const { return col; }
	void set_col(bool c) { col = c; }
	void reverse_col() { col = !col; }
	bool operator==(const Board& x) const 
	{
		return (col == x.col) && (data == x.data);
	}
	bool operator!=(const Board& x) const
	{
		return !((*this) == x);
	}
	void print() const;//for debug purpose only
	std::vector<std::vector<int>> getBoard() const;

	friend std::ostream& operator<<(std::ostream& os, const Board& b);
	static mov convert(int a, int b, int c, int d);//converting matrix coordinates to checkers notation
private:
	positions generate_moves() const;
	positions generate_captures() const;
	positions jump(int i, int j, int a, int b, int en1, int en2, std::vector<std::vector<int>> temp) const;
	std::vector<std::vector<int>> data = std::vector<std::vector<int>>(10, std::vector<int>(10));
	bool col;//player's turn
	mov last_move{ 1,1 };//the last move made
};