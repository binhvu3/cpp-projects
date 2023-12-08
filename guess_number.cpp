#include <iostream>
#include <cstdlib>  // For range() and srand()
#include <ctime>    // For the time() function

int main(){
  // Initialize random seed
  srand(static_cast<unsigned int>(time(0)));

  int secretNumber = rand()%100+1;
  int guess = 0;

  std::cout << "A number is picked between 1-100!" << std::endl;
  std::cout << "Guess a number..." << std::endl;

  while (guess != secretNumber){
    std::cout << "Enter a number: ";
    std::cin >> guess;

    if (guess > secretNumber){
      std::cout << "Too High! Try Again." << std::endl;
    }
    else if (guess < secretNumber){
      std::cout << "Too Low! Try Again." << std::endl;
    }
    else{
      std::cout << "Congrats! You got it!" << std::endl;
    }
  }

  return 0;
}
