#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <chrono>
#include <string.h>

int main(){
  
  bool timer = false;
  auto start = std::chrono::high_resolution_clock::now(); 
  int sock = 0, valread;
  struct sockaddr_in serv_addr;
  char buffer[1024] = {0};

  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
    perror("Failed Socket");
    exit(EXIT_FAILURE);
  }

  perror("Socket");

  if (timer == false){
    auto end1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1-start);
    std::cout << "Execution time: " << duration1.count() << " milliseconds" << std::endl;
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(8080);

  if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <=0){
    perror("Failed IPv4");
    exit(EXIT_FAILURE);
  }

  perror("Specify Server Address and Port");
  
  if (timer == true){
    auto end2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2-start);
    std::cout << "Execution time: " << duration2.count() << " milliseconds" << std::endl;
  }

  if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0){
    perror("Fail Connect");
    exit(EXIT_FAILURE);
  }

  perror("Connected");

  if (timer == true){
    auto end3 = std::chrono::high_resolution_clock::now();
    auto duration3 = std::chrono::duration_cast<std::chrono::milliseconds>(end3-start);
    std::cout << "Execution time: " << duration3.count() << " milliseconds" << std::endl;
  }

  std::string message;

  while (true){
    std::cout << "Enter Message (type 'q' to close): ";
    std::getline(std::cin, message);

    if (message == "q"){
      break;
    }

    send(sock, message.c_str(), message.length(), 0);

    valread = read(sock, buffer, 1024);
    std::cout << "Server: " << buffer << std::endl;
    memset(buffer, 0, sizeof(buffer));
  }
  close(sock);
  return 0;
}
