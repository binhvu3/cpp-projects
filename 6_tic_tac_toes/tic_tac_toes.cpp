#include <iostream>
#include <vector>

class TicTac{
  private:
    int ROWS = 3;
    int COLS = 3;
  
  public:
  
  void printBoard(const std::vector<std::vector<char>> &board){
    for (int i=0; i<ROWS; i++){
      std::cout << "_______" << std::endl;
      for (int j=0; j<COLS; j++){
        std::cout << "|" << board[i][j];
      }
      std::cout << "|" << std::endl;
    }
    std::cout << "_______" << std::endl;
  }

  bool checkWinner(const std::vector<std::vector<char>> &board, char player){
    for (int i = 0; i<ROWS; i++){
      if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
          (board[0][i] == player && board[1][i] == player && board[2][i] == player){
        return true;
      }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player){
      return true;
    }

    return false;
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
