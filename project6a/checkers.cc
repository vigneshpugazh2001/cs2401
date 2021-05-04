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
                else if (board[i][j].is_black() && board[i][j].is_white()) cout << B_BLACK << RED << " O " << RESET;
                else if (board[i][j].is_black()) cout << B_BLACK << RED << " O " << RESET;
                else if (board[i][j].is_white() && board[i][j].is_white()) cout << B_BLACK << CYAN << " O " << RESET;
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
               
            }
        }
        game::restart(); 
    }

void Checkers::make_move(const std::string& move){
    int c1 = (int)(toupper(move[0]) - 'A'); //converts letter into a digit subtracts one from the asci table
    int r1 = (int)(move[1] - '1');
    int c2 = (int)(toupper(move[2]) - 'A');
    int r2 = (int)(move[3] - '1');
    cout << c1 << r1 << c2 << r2 << endl;

       board[r1][c1].make_empty();
    if(c1 == 0 && c2 == 1){
        board[r2][c2].make_white();
    }else if(c1 == 2 && c2 == 1){
        board[r2][c2].make_white();
    }else if(c1 == 2 && c2 == 3){
        board[r2][c2].make_white();
    }else if(c1 == 4 && c2 == 3){
        board[r2][c2].make_white();
    }else if(c1 == 4 && c2 == 5){
        board[r2][c2].make_white();
    }else if(c1 == 6 && c2 == 5){
        board[r2][c2].make_white();
    }else if(c1 == 6 && c2 == 7){
        board[r2][c2].make_white();
    }
}

bool Checkers::is_legal(const std::string& move)const{
     int c1 = (int)(toupper(move[0]) - 'A');
     int r1 = (int)(move[1] - '1');
     int c2 = (int)(toupper(move[2]) - 'A');
     int r2 = (int)(move[3] - '1');
     cout << c1 << r1 << c2 << r2 << endl;

     if(c1 < 0  || c1 > 8) return false;
     if(r1 < 0  || r1 > 8) return false;
     if(c2 < 0  || c2 > 8) return false;
     if(r2 < 0  || r2 > 8) return false;

     if(r1 != 5){
         return false;
     }else if(c1 % 2 != 0){
         return false;
     }else if(r2 != 4){
         return false;
     }else if(c2 % 2 != 1){
         return false;
     }else{
         return true;
     }


}


}

    
 



