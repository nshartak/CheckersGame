#include "Game.h"
#include <algorithm>
#include <sstream>
#include <vector>
#include <utility>
Game::Game(bool col, int n, Estimator e) : depth{ n }, color{ col }, estimate{ e } 
{
    if (col)
    {
        data = Board{};
    }
    else
    {
        data = best_move(Board{});
    }
}

void Game::make_move(std::string s)
{
    std::istringstream st(s);
    std::vector<std::pair<int, int>> moves;
    int i;
    while (st >> i)
    {
        moves.push_back({ (i / 10), (i % 10) });
    }
    auto& arr = data.data;
    while (moves.size() > 1)
    {
        int i = moves[0].first;
        int j = moves[0].second;
        int a = moves[1].first;
        int b = moves[1].second;
        int temp = arr[i][j];
        arr[i][j] = 0;
        arr[a][b] = temp;
        if (a == i - 2 && b == j - 2)
            arr[i - 1][j - 1] = 0;
        if (a == i - 2 && b == j + 2)
            arr[i - 1][j + 1] = 0;
        if (a == i + 2 && b == j - 2)
            arr[i + 1][j - 1] = 0;
        if (a == i + 2 && b == j + 2)
            arr[i + 1][j + 1] = 0;
        moves.erase(moves.begin());
    }
    data.normalize();
    data.reverse_col();
    if (game_over(data))
    {
        stop();
        return;
    }
    data = best_move(data);
    if (game_over(data))
    {
        stop();
        return;
    }
}

void Game::stop()
{
    std::cout << std::endl << "Game over!" << std::endl;
    state = true;
}

bool Game::game_over(const Board& b)
{

    const auto& arr = b.data;
    for (int i = 1; i < 9; ++i)
        if (arr[1][i] == 1 || arr[8][i] == -1)//someone has a king
            return true;
    int wcnt{}, bcnt{};
    for (int i = 1; i < 9; ++i)
        for (int j = 1; j < 9; ++j)
        {
            if (1 == arr[i][j])
                ++wcnt;
            if (-1 == arr[i][j])
                ++bcnt;
        }
    if (wcnt == 0 || bcnt == 0 || b.num_of_moves() == 0)
        return true;
    return false;
}

double Game::alpha_beta(const Board& b, int dep) const
{
    return ab_recursive(b, dep, -10000, 10000);
}

double Game::ab_recursive(const Board& b, int dep, double alpha, double beta) const
{
    if (dep == 0 || game_over(b))
        return estimate(b);
    double eval{};
    if (b.get_col())
    {
        eval = -10000;//minus infinity
        auto moves = b.generate();
        for (const auto& i : moves)
        {
            double temp = ab_recursive(i, dep - 1, alpha, beta);
            eval = std::max(eval, temp);
            alpha = std::max(alpha, temp);
            if (beta <= alpha)break;
        }
        return eval;
    }
    else//blacks turn
    {
        eval = 10000;//plus infinity
        auto moves = b.generate();
        for (const auto& i : moves)
        {
            double temp = ab_recursive(i, dep - 1, alpha, beta);
            eval = std::min(eval, temp);
            beta = std::min(beta, temp);
            if (beta <= alpha)break;
        }
        return eval;
    }
    
}

double Game::minimax(const Board& b, int dep) const
{
    if (dep == 0||game_over(b))
        return estimate(b);
    double eval{};
    if (b.get_col())//white's turn
    {
        eval=-10000;//minus infinity
        auto moves = b.generate();
        for (const auto& i : moves)
        {
            double temp = minimax(i, dep - 1);
            eval = std::max(eval, temp);
        }
        return eval;
    }
    else//blacks turn
    {
        eval = 10000;//plus infinity
        auto moves = b.generate();
        for (const auto& i : moves)
        {
            double temp = minimax(i,dep - 1);
            eval = std::min(eval, temp);
        }
        
        return eval;
    }

    
}

double Game::calculate(const Board& b) const
{
    if (alpha)
        return alpha_beta(b, depth);
    return minimax(b, depth);
}

Board Game::best_move(const Board& b)
{
    bool flag = b.get_col();
    auto all_moves = b.generate();
    Board guess = all_moves.front();
    double eval = calculate(guess);
    for (const auto& i : all_moves)
    {
        double temp = calculate(i);
        if (flag)//white's turn, so we need to MAXIMIZE
        {
            if (temp > eval)
            {
                eval = temp;
                guess = i;
            }
        }
        else//black's turn we need to minimize
        {
            if (temp < eval)
            {
                eval = temp;
                guess = i;
            }
        }
    }
    return guess;
}

std::ostream& operator<<(std::ostream& os, const Game& g)
{
    os << g.data<<"\n"<<g.calculate(g.data);
    return os;
}
