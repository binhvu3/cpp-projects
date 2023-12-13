#include <iostream>
#include <vector>

class TicTac{
  private:
    int ROWS = 3;
    int COLS = 3;
  
  public:
  
  void printBoard(const std::vector<std::vector<char>> &board){
    for (int i=0; i<ROWS; i++){
      std::cout << "_______________" << std::endl;
      for (int j=0; j<COLS; j++){
        std::cout << " | " << board[i][j];
      }
      std::cout << " |" << std::endl;
    }
    std::cout << "_______________" << std::endl;
  }

  bool checkWinner(const std::vector<std::vector<char>> &board, char player, int &moves){
    if (moves == 9){
      return true;
    }
    else{
      return false;

    }
  }

  void markBoard(const std::vector<std::vector<char>> &board, char player){

  }

  void resetBoard(const std::vector<std::vector<char>> &board){

  }
};


int main(){
  TicTac game;
  std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
  board[0][0] = 'x';
  board[1][1] = 'y';
  game.printBoard(board);

  return 0;
}
