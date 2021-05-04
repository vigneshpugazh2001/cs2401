#ifndef PIECES_H
#define PIECES_H
#include <iostream>
#include <cstdlib>
#include <string>

class Pieces{
    public:
        Pieces(){ //added
            king = false;
        }
        void make_king(){ //added
            king = true;
        }
        void kingslayer(){ //added
            king = false;
        }
        bool is_king()const{ //added
            return king;
        }
        bool is_black()const
        {
            if(black == true)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        bool is_white()const
        {
            if(white == true)
            {
                return true;
            }
        }

        bool is_empty()const
        {
            if (black == false && white == false)
            return true;
            else return false;
        }

        void make_empty()
        {
            white = false;
            black = false;
        }

        void make_black()
        {
            black = true;
            white = false;
        }

        void make_white()
        {
            white = true;
            black = false;
        }


    private:
    bool black;
    bool white;
    bool empty;
    bool king;

};

#endif