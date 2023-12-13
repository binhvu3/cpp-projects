#include <iostream>
#include <string>

class BankAccount{
private:
  std::string name;
  double balance;

public:
  BankAccount(std::string accountName, double initialAmount): name(accountName), balance(initialAmount) {}

  void deposit(double amount){
    if (balance > 0){
      balance += amount;
      std::cout << "Success deposit!" << std::endl;
      std::cout << "Current Balance is $" << balance << std::endl;
    }
    else{
      std::cout << "Invalid Amount !!! Please deposit more than $0!" << std::endl;
    }
  }

  void withdraw(double amount){
    if ((balance < amount) && (balance-amount < 0)){
      std::cout << "Insufficient fund!" << std::endl;
      std::cout << "Current Balance is $" << balance << std::endl;
      
    }
    else{
      balance -= amount;
      std::cout << "Success withdraw! Your current balance is $" << balance << std::endl;
    }
  }

  void check_balance(){
    std::cout << "Your current balance is $" << balance << std::endl;
  }
};

int main(){
  std::string name;
  double initialDeposit;

  std::cout << "Enter your name: ";
  getline(std::cin, name);

  std::cout << "Enter inital amount: ";
  std::cin >> initialDeposit;

  BankAccount account(name, initialDeposit);

  int choice;
  double amount;

  do {

    std::cout << "\n1. Deposit" << std::endl;
    std::cout << "2. Withdraw" << std::endl;
    std::cout << "3. Check Balance" << std::endl;
    std::cout << "4. Exit/" << std::endl;

    std::cout << "Please select (1-4): ";
    std::cin >> choice;

    switch (choice){
      case 1:
        std::cout << "1. How much do you want to deposit? ";
        std::cin >> amount;
        account.deposit(amount);
        break;

      case 2:
      std::cout << "2. How much do you want to withdraw? ";
      std::cin >> amount;
      account.withdraw(amount);
      break;

      case 3:
        std::cout << "3. Checking account balance..." << std::endl;
        account.check_balance();
        break;

      case 4:
      std::cout << "4. Exiting..." << std::endl;
      break;

      default:
      std::cout << "Invalid Choice! Please try again. " << std::endl;
    }
    
  } while(choice != 4);

  return 0;
}
