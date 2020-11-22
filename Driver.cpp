#include <fstream>
#include <iostream>
#include <string>
#include "Matrix.h"

int main(){
  std::string fileName;
  std::cout << "Enter in the file to read: " << std::endl;
  std::cin >> fileName;
  Matrix a(fileName);

  //shows you the matrix that was read in
  std::cout << "\n\nHere is the matrix that was read in: " << std::endl;
  a.prettyPrint();

  //gets starting and destination nodes
  std::cout << "\n\n\n";
  std::string start, dest;
  std::cout << "Enter starting node" << std::endl;
  std::cin >> start;
  std::cout << "Now enter the destination node " << std::endl;
  std::cin >> dest;
  std::cout << "\n\n\n";

  //performs djikstras
  a.djikstras(stoi(start), stoi(dest));

}
