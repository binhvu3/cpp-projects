#include <iostream>
#include <string>
#include <fstream>

void encryptFile(const std::string &inputFilePath, const std::string &outputFilePath, int key){
  std::ifstream fileIn(inputFilePath, std::ios::binary);
  std::ofstream fileOut(outputFilePath, std::ios::binary);

  char ch;
  while (fileIn.get(ch)){
    fileOut.put(ch+key);
  }

  fileIn.close();
  fileOut.close();
}

void decryptFile(const std::string &inputFilePath, const std::string &outputFilePath, int key){
  std::ifstream fileIn(inputFilePath, std::ios::binary);
  std::ofstream fileOut(outputFilePath, std::ios::binary);

  char ch;
  while (fileIn.get(ch)){
    fileOut.put(ch-key);
  }

  fileIn.close();
  fileOut.close();

}

int main(){
  std::string inputFilePath, outputFilePath;
  int choice, key;

  std::cout << "1. Encrypt File\n";
  std::cout << "2. Decrypt File\n";
  std::cout << "Enter your choice: ";
  std::cin >> choice;

  std::cout << "Enter key (integer): ";
  std::cin >> key;

  std::cout << "Enter input file path: ";
  std::cin >> inputFilePath;
  std::cout << "Enter output file path: ";
  std::cin >> outputFilePath;

  if (choice == 1){
    encryptFile(inputFilePath, outputFilePath, key);
  }
  else if (choice == 2){
    decryptFile(inputFilePath, outputFilePath, key);
  }
  else{
    std::cout << "Invalid choice!" << std::endl;
  }
  return 0; 
}
