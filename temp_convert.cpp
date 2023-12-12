#include <iostream>

double C_to_F(double C){
  return (9.0/5.0 * C) + 32.0;
}

double F_to_C(double F){
  return 5.0/9.0 * (F - 32.0);
}

double C_to_K(double C){
  return C + 273;
}

double K_to_C(double K){
  return K-273;
}

int main(){

  std::cout << "1. Convert Celsius to Fahrenheit" << std::endl;
  std::cout << "2. Fahrenheit to Celsius" << std::endl;
  std::cout << "3. Celsius to Kelvin" << std::endl;
  std::cout << "4. Kelvin to Celsius" << std::endl;

  char choice;
  std::cin >> choice;
  std::cout << "You Picked " << choice << std::endl;

  std::cout << "Enter Temperature: ";
  double temp;

  std::cin >> temp;
  std::cout << "You've Entered: " << temp << std::endl;

  switch (choice) {
    case '1':
      std::cout << "From " << temp << "C*" << " -> " << C_to_F(temp) << "F*" << std::endl;
      break;

    case '2':
      std::cout << "From " << temp << "F*" << " -> " << F_to_C(temp) << "C*" << std::endl;
      break;

    case '3':
      std::cout << "From " << temp << "C*" << " -> " << C_to_K(temp) << "K*" << std::endl;
      break;

    case '4':
      std::cout << "From " << temp << "F*" << " -> " << F_to_C(temp) << "C*" << std::endl;
      break;
    
    default:
      std::cout << "Invalid Input!";
      break;
  }

  return 0;
}

