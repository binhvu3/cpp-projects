#include <iostream>

int main(){
  double num1, num2;
  char operation;

  std::cout << "Enter first num: ";
  std::cin >> num1;

  std::cout << "Enter second num: ";
  std::cin >> num2;

  std::cout << "Enter the operation (+, -, *, /): ";
  std::cin >> operation;

  switch (operation) {
    case '+':
      std::cout << "Result: " << num1+num2; break;

    case '-':
      std::cout << "Result: " << num1-num2; break;

    case '*':
      std::cout << "Result: " << num1*num2; break;

    case '/':
      if (num2 != 0){
        std::cout << "Result: " << num1/num2; break;
      }
      else{
        std::cout << "Error: Divide by zero!!!"; break;
      }
    default:
      std::cout << "Invalid Input!" << std::endl;
  }
  return 0;
}
