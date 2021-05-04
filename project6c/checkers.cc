#include "checkers.h"
#include "colors.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
namespace main_savitch_14{

void Checkers::display_status()const{ //displays the board
int count = 1;
        cout << B_BLACK << "                                " << RESET << endl;
        cout << B_BLACK << "  " << B_BLACK << "   A  B  C  D  E  F  G  H   "  << B_BLACK << "  " << RESET << endl;
        for (int i = 0; i < 8; i++) {
            cout << B_BLACK << "  " << B_BLACK << count << " ";   
            for (int j = 0; j < 8; j++) {
                if (((j+i)%2) == 0) cout << B_WHITE << "   " << RESET;
                else if (!board[i][j].is_white() && !board[i][j].is_black()) cout << B_BLACK << "   " << RESET;  
                else if (board[i][j].is_black() && board[i][j].is_king()) cout << B_BLACK << RED << " O " << RESET; //added is_king
                else if (board[i][j].is_black()) cout << B_BLACK << RED << " O " << RESET;
                else if (board[i][j].is_white() && board[i][j].is_king()) cout << B_BLACK << CYAN << " O " << RESET; //added is_king
                else if (board[i][j].is_white()) cout << B_BLACK << CYAN << " O " << RESET; 
            }
            cout << B_BLACK << " " << count << B_BLACK << "  " << RESET << endl;
            count++;
        }
        cout << B_BLACK << "  " << B_BLACK << "   A  B  C  D  E  F  G  H   " << B_BLACK << "  " << RESET<< endl << B_BLACK << "                                " << RESET << endl;
    }

void Checkers::restart(){ //places all pieces at the right spot
    for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                
                if (i == 0 && (j == 1 || j == 3 || j == 5 || j == 7)) board[i][j].make_black();
                else if (i == 1 && (j == 0 || j == 2 || j == 4 || j == 6)) board[i][j].make_black();
                else if (i == 2 && (j == 1 || j == 3 || j == 5 || j == 7)) board[i][j].make_black();
                else if (i == 5 && (j == 0 || j == 2 || j == 4 || j == 6)) board[i][j].make_white();
                else if (i == 6 && (j == 1 || j == 3 || j == 5 || j == 7)) board[i][j].make_white();
                else if (i == 7 && (j == 0 || j == 2 || j == 4 || j == 6)) board[i][j].make_white();
                else board[i][j].make_empty();
                if(board[i][j].is_king()) //added this
                {
                    board[i][j].kingslayer(); //added this
                } 
               
            }
        }
        game::restart(); 
    }

game* Checkers::clone() const{
    void restart();
        for (int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                if (i == 0 && (j == 1 || j == 3 || j == 5 || j == 7)) board[i][j].is_black();
                else if (i == 1 && (j == 0 || j == 2 || j == 4 || j == 6)) board[i][j].is_black();
                else if (i == 2 && (j == 1 || j == 3 || j == 5 || j == 7)) board[i][j].is_black();
                else if (i == 5 && (j == 0 || j == 2 || j == 4 || j == 6)) board[i][j].is_white();
                else if (i == 6 && (j == 1 || j == 3 || j == 5 || j == 7)) board[i][j].is_white();
                else if (i == 7 && (j == 0 || j == 2 || j == 4 || j == 6)) board[i][j].is_white();
                else board[i][j].is_empty();
                if (board[i][j].is_king()) board[i][j].is_king();
            }
        }
    }

void Checkers::compute_moves(std::queue<std::string>& moves) const{
    string temp = "Computer";
    for (char one = 'a'; one <'i'; one++)
    {
        for (char two = '1'; two < '9'; two++)
        {
            for (char three = 'a'; three < 'i'; three++)
            {
                for(char four = '1'; four < '9'; four++)
                {
                    temp[0] = one;
                    temp[1] = two;
                    temp[2] = three;
                    temp[3] = four;
                    // if (is_legal(temp)) //this if statement makes it an infinite loop
                    // {
                    //     moves.push(temp);
                    // }
                }
            }
        }
    }
}

int Checkers::evaluate() const{
    int cpu = 0;
    for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j].is_white()) {
                    cpu--;
                    if (board[i][j].is_king()) cpu -= 4;
                }
                else if(board[i][j].is_black()) {
                    cpu++;
                    if (board[i][j].is_king()) cpu += 4;        
                }
                else;
            }
        }
        return cpu;
}

void Checkers::make_move(const std::string& move){
     int c1 = (int)(toupper(move[0]) - 'A'); //converts letter into a digit subtracts one from the asci table
     int r1 = (int)(move[1] - '1');
     int c2 = (int)(toupper(move[2]) - 'A');
     int r2 = (int)(move[3] - '1');
     cout << c1 << r1 << c2 << r2 << endl;
     board[r1][c1].make_empty();
     cout << moves_completed();
     if(moves_completed() % 2 == 0){
        board[r2][c2].make_white();
     }
     else if (moves_completed() % 2 == 1)
     {
         board[r2][c2].make_black();
     }
     if ((r2 == r1 - 2) && (c2 == c1 - 2)) //takes away pieces
        {
            board[r1 - 1][c1 - 1].make_empty();
        }

        if ((r2 = r1 - 2) && (c2 == c1 + 2))
        {
            board[r1 - 1][c1 + 1].make_empty();
        }

        if ((r2 = r1 + 2) && (c2 == c1 - 2))
        {
            board[r1 + 1][c1 - 1].make_empty();
        }
        if ((r2 = r1 + 2) && (c2 == c1 + 2))
        {
            board[r1 + 1][c1 + 1].make_empty();
        }
     game::make_move(move);

     
}

bool Checkers::is_legal(const std::string& move)const{
     int c1 = (int)(toupper(move[0]) - 'A');
     int r1 = (int)(move[1] - '1');
     int c2 = (int)(toupper(move[2]) - 'A');
     int r2 = (int)(move[3] - '1');
    // cout << c1 << r1 << c2 << r2 << endl; //this gets stuck

     if(c1 < 0  || c1 > 8) return false; 
     if(r1 < 0  || r1 > 8) return false; 
     if(c2 < 0  || c2 > 8) return false; 
     if(r2 < 0  || r2 > 8) return false; 

     if(r1 != 5){
         return true; //false
     }else if(c1 % 2 != 0){
         return true; //false
     }else if(r2 != 4){
         return true; //false
     }else if(c2 % 2 != 1){
         return true; //false
     }else{
         return true;
     }

    if(moves_completed() % 2 == 0){
        if(board[r2][c2].is_white() == true)
        {
            return true;
        }
        else{
            return false;
        }
        
     }

     if (moves_completed() % 2 == 1)
     {
         if(board[r2][c2].is_black() == true)
         {
             return true;
         }
         else{
             return false;
         }
     }


}

bool Checkers::moves(const string &move) const{ //added this
        int c1 = (int)(toupper(move[0]) - 'A'); //z
        int r1 = (int)(move[1] - '1'); //i
        int c2 = (int)(toupper(move[2]) - 'A'); //y
        int r2 = (int)(move[3] - '1'); //x

        if (moves_completed() % 2 == 0)
        {
            if (board[r1][c1].is_black()) //could be is_white
            {
                if (r1 - 1 == r2)
                {
                    if (board[r1 - 1][c1 - 1].is_empty() && c1 - 1 == c2)
                        return true;
                    if (board[r1 - 1][c1 + 1].is_empty() && c1 + 1 == c2)
                        return true;
                }
                if (board[r1][c1].is_king())
                {
                    if (r1 + 1 == r2)
                    {
                        if (board[r1 + 1][c1 - 1].is_empty() && c1 - 1 == c2)
                            return true;
                        if (board[r1 + 1][c1 + 1].is_empty() && c1 + 1 == c2)
                            return true;
                    }
                }
            }
        }
        if (moves_completed() % 2 == 1)
        {
            if (board[r1][c1].is_white()) //could be is_black
            {
                if (r1 + 1 == r2)
                {
                    if (board[r1 + 1][c1 - 1].is_empty() && c1 - 1 == c2)
                        return true;
                    if (board[r1 + 1][c1 + 1].is_empty() && c1 + 1 == c2)
                        return true;
                }
                if (board[r1][c1].is_king())
                {
                    if (r1 - 1 == r2)
                    {
                        if (board[r1 - 1][c1 - 1].is_empty() && c1 - 1 == c2)
                            return true;
                        if (board[r1 - 1][c1 + 1].is_empty() && c1 + 1 == c2)
                            return true;
                    }
                }
            }
        }
        return false;
}

Checkers::who Checkers::winning()const{
    //added this 
    int humancount = 0;
    int computercount = 0;
    for (int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++){
            if(board[i][j].is_white()){    
            humancount++;
            } 
            else if (board[i][j].is_black()){
            computercount++;
            } 
            else;
        }
    }
    if (humancount == computercount){
    return NEUTRAL;
    } 
    else if (humancount > computercount){
        return HUMAN;
    }
    else if(computercount > humancount)
    {
        return COMPUTER;
    }
}

bool Checkers::is_game_over()const{
    //same as winning function but if humancount or computer count has 0 pieces
      int humancount = 0;
    int computercount = 0;
    for (int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++){
            if(board[i][j].is_white()){    
            humancount++;
            } 
            else if (board[i][j].is_black()){
            computercount++;
            } 
            else;
        }
    }
    if (humancount == 0){
    return true;
    } 
    else if (computercount == 0){
        return true;
    }
    else
    {
        return false;
    }

}

bool Checkers::is_jumpavailable()const{ //added this
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if(moves_completed()%2 == 0)
            {
                if(board[i][j].is_white())
                {
                    if(board[i-1][j-1].is_black() && board[i-2][j-2].is_empty()) return true; 
                    if(board[i-1][j+1].is_black() && board[i-2][j+2].is_empty()) return true; 
                    if(board[i][j].is_king())
                    {
                        if(board[i+1][j-1].is_black() && board[i+2][j-2].is_empty()) return true; 
                        if(board[i+1][j+1].is_black() && board[i+2][j+2].is_empty()) return true; 
                    }
                }
            }

            if(moves_completed()%2 == 1){
                if(board[i][j].is_black())
                {
                    if(board[i+1][j-1].is_white() && board[i+2][j-2].is_empty()) return true; 
                    if(board[i+1][j+1].is_white() && board[i+2][j+2].is_empty()) return true; 
                    if(board[i][j].is_king())
                    {
                        if(board[i-1][j-1].is_white() && board[i-2][j-2].is_empty()) return true; 
                        if(board[i-1][j+1].is_white() && board[i-2][j-2].is_empty()) return true; 
                    }
                }
            }
        }
    }
    return false;
}



}

    
 



