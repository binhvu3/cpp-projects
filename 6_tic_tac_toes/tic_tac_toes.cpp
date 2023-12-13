/*
 * TODO: 
 * 1. Invalid user input check
 * 2. Recuring game after win:w
 *
*/
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
          (board[0][i] == player && board[1][i] == player && board[2][i] == player)){
        return true;
      }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)){
      return true;
    }

    return false;
  }

  char checkDraw(const std::vector<std::vector<char>> &board){
    for (const auto &row : board){
      for (char cell : row){
        if (cell == ' '){
          return false;
        }
      }
    }
    return true;
  }
};


int main(){
  TicTac game;
  std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
  char currPlayer = 'X';
  int row, col;
  bool gameOver = false;

  while (!gameOver){
    game.printBoard(board);
    std::cout << "Player " << currPlayer << ", enter row (0-2): ";
    std::cin >> row;

    std::cout << "Player " << currPlayer << ", enter col (0-2): ";
    std::cin >> col;

    if (board[row][col] == ' '){
      board[row][col] = currPlayer;
      gameOver = game.checkWinner(board, currPlayer);

    if (gameOver){
      game.printBoard(board);
      std::cout << "Player " << currPlayer << " wins!" << std::endl;
    }
    else if (game.checkDraw(board)){
      std::cout << "It's a draw!" << std::endl;
      gameOver = true;
    }
    currPlayer = (currPlayer == 'X') ? 'O' : 'X';
    }
    else{
      std::cout << "That spot is already taken. Try again." << std::endl;
    }
  }


  return 0;
}
