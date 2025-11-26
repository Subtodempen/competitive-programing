#include <cstdio>
#include <iostream>
#include <ratio>
#include <system_error>
#include <vector>
#include <cassert>

enum Square{
    blank = 0, red, green
};


std::vector<Square> board;
int n, r, g;

void setUpBoard(){
    std::vector<Square> b(n * n, Square::blank);

    board = b;
    board[0] = Square::red;

    int pos = 0;
    int empties = (n * n) - 1;

    bool greenTurn = false;
    int redBlanks = 0, greenBlanks = 0; 

    while(empties > 0) {
        greenTurn = not greenTurn; // if true then greens turn, false for reds
        
        pos = (pos + 1) % (n * n);

        if(board.at(pos) == Square::blank){
            greenBlanks += (int)greenTurn;
            redBlanks += (int)not greenTurn;
        }

        if(redBlanks == r) {
            board.at(pos) = Square::red;
            
            redBlanks = 0;
            empties--;
        }

        else if(greenBlanks == g){
            board.at(pos) = Square::green;

            greenBlanks = 0;
            empties--;
        }
    }
}

bool isValid(int x, int y){
    int pos = (x + 1) * (y + 1);
    
    if(pos < 0)
        return false;

    if(pos % n != 0)
        return false;

    if(pos >= (n * n))
        return false;

    else if(board.at(pos) == Square::blank)
        return false;
    
    return true;
}

auto getNeighbors(int pos){
    std::vector<int> neighbors;
    int x = 0, y = 0;

    y = (pos % n);
    x = (pos % n);

    if(isValid(x, y - 1)){
        neighbors.push_back(pos);
    }
}

int main(){
    scanf("%d %d %d", &n, &r, &g);
    setUpBoard();
}