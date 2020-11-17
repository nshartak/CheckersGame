#include "Board.h"
#include <list>
#include <algorithm>
#include <iterator>
Board::Board() : col{true}
{

	for (int i = 0; i < 10; ++i)
	{
		//Assigning the sentinels the value 7
		data[i][0] = data[i][9] = data[9][i] = data[0][i] = 7;
	}

	for (int i = 2; i < 9; i += 2)
	{
		//Filling the black pieces
		data[1][i] = data[2][i - 1] = data[3][i] = -1;
	}
	for (int i = 1; i < 8; i += 2)
	{
		//Filling the white pieces
		data[6][i] = data[7][i + 1] = data[8][i] = 1;
	}
}

Board::positions Board::generate() const
{
	std::list<Board> res=generate_moves();
	//TODO use generate_captures

	return res;
}



Board::positions Board::generate_moves() const
{
	positions res;
	int nx = col ? 1 : -1;//to find appropRiate pawns
	for (int i{ 1 }; i < 9; ++i)
	{
		for (int j{ 1 }; j < 9; ++j)
		{
			if (data[i][j] == nx)
			{
				int row = col ? i - 1 : i + 1;
				int col1 = j - 1;
				int col2 = j + 1;
				if (data[row][col1] == 0)
				{
					Board temp;
					temp.data = data;
					temp.data[row][col1] = col ? 1 : -1;
					temp.data[i][j] = 0;
					temp.col = !col;
					temp.last_move = convert(i, j, row, col1);
					res.push_back(temp);
				}
				if (data[row][col2] == 0)
				{
					Board temp;
					temp.data = data;
					temp.data[row][col2] = col ? 1 : -1;
					temp.data[i][j] = 0;
					temp.col = !col;
					temp.last_move = convert(i, j, row, col2);
					res.push_back(temp);
				}

				
			}
		}
	}
	return res;
}

Board::positions Board::generate_captures() const
{
	//TODO
	//integraTe and use jump()
	positions res;
	int nx = col ? 1 : -1;//my pawn
	int en = (nx == 1) ? -1 : 1;//enemy pawn
	for (int i{ 1 }; i < 9; ++i)
	{
		for (int j{ 1 }; j < 9; ++j)
		{
			if (data[i][j] == nx)
			{
				int row = col ? i - 1 : i + 1;
				int col1 = j - 1;
				int col2 = j + 1;
				if (data[row][col1] == en)
				{
					if (col)
					{
						if (data[row - 1][col1 - 1] == 0)
						{
							//jump from [i,j] to [row-1, col1-1]
						}
					}
					else
					{
						if (data[row + 1][col1 - 1] == 0)
						{
							//jump from [i,j] to [row+1, col1-1]
						}
					}
					
				}


				if (data[row][col2] == en)
				{
					if (col)
					{
						if (data[row - 1][col2 + 1] == 0)
						{
							//jump from [i,j] to [row-1, col2+1]
						}
					}
					else
					{
						if (data[row + 1][col2 + 1] == 0)
						{
							//jump from [i,j] to [row+1, col2+1]
						}
					}

				}
			}
		}
	}
	return res;
}

Board::positions Board::jump(int i, int j, int a, int b, int en1, int en2, std::vector<std::vector<int>> temp) const
{
	//TODO
	//debug
	positions res;
	auto it = std::back_inserter(res);
	int en = temp[en1][en2];
	temp[en1][en2] = 0;
	temp[i][j] = 0;
	temp[a][b] = -en;
	
		int row = col ? a - 1 : a + 1;
		int col1 = b - 1;
		int col2 = b + 1;
		if (data[row][col1] == en)
		{
			if (col)
			{
				if (data[row - 1][col1 - 1] == 0)
				{
					//jump from [a,b] to [row-1, col1-1]
					positions alfa=jump(a, b, row - 1, col1 - 1, row, col1, temp);
					std::copy(alfa.begin(), alfa.end(), it);
				}
			}
			else
			{
				if (data[row + 1][col1 - 1] == 0)
				{
					//jump from [a,b] to [row+1, col1-1]
					positions alfa = jump(a, b, row + 1, col1 - 1, row, col1, temp);
					std::copy(alfa.begin(), alfa.end(), it);
				}
			}

		}
		if (data[row][col2] == en)
		{
			if (col)
			{
				if (data[row - 1][col2 + 1] == 0)
				{
					//jump from [a,b] to [row-1, col2+1]
					positions alfa = jump(a, b, row - 1, col2 + 1, row, col2, temp);
					std::copy(alfa.begin(), alfa.end(), it);
				}
			}
			else
			{
				if (data[row + 1][col2 + 1] == 0)
				{
					//jump from [a,b] to [row+1, col2+1]
					positions alfa = jump(a, b, row + 1, col2 + 1, row, col2, temp);
					std::copy(alfa.begin(), alfa.end(), it);
				}
			}

		}
	

		if (res.empty())
		{
			Board newest;
			newest.data = temp;
			newest.col = !col;
			newest.last_move = convert(i, j, a, b);
			res.push_back(newest);
		}

	return res;
}

Board::mov Board::convert(int a, int b, int c, int d)//converting matrix coordinates to checKers notation
{
	int x = (a - 1) * 4 + b / 2;
	int y= (c - 1) * 4 + d / 2;
	if (a % 2 == 0)++x;
	if (c % 2 == 0)++y;
	return { x,y };
}

std::ostream& operator<<(std::ostream& os, const Board& b)
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			int temp = (b.getBoard)()[i][j];
			if (temp == 1)
				os << "w ";
			if (temp == -1)
				os << "b ";
			if (temp == 0)
				os << "_ ";
		}
		os << std::endl;
	}

	return os;
}



void Board::print() const
{
	for (auto& i : data)
	{
		for (auto j : i)
		{
			std::cout << j << "   ";
		}
		std::cout << std::endl;
	}
}

std::vector<std::vector<int>> Board::getBoard() const//returning the board without sentinels
{
	std::vector<std::vector<int>> temp = std::vector<std::vector<int>>(8, std::vector<int>(8));
	for (int i = 1; i < 9; ++i)
	{
		for (int j = 1; j < 9; ++j)
		{
			temp[i - 1][j - 1] = data[i][j];
		}
	}
	return temp;
}
