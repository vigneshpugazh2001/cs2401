#ifndef CHECKERS_H
#define CHECKERS_H
#include "pieces.h"
#include "game.h"

namespace main_savitch_14
{
class Checkers: public game{
public:
Checkers(){};

//virtual functions that must be overriden
void make_move(const std::string& move);
void restart();
who winning() const{};

//pure virtual functions
game* clone() const{};
void compute_moves(std::queue<std::string>& moves) const{};
void display_status()const;
int evaluate() const{};
bool is_game_over() const{};
bool is_legal(const std::string& move)const;

private:

Pieces board[8][8];

};

}//for the savitch namespace


#endif