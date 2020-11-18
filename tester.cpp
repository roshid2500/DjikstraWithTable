#include <fstream>
#include <iostream>
#include <string>
#include "Matrix.h"

int main(){
  Matrix a("partA.txt");
  a.prettyPrint();
  std::cout << "\n\n\n";
  a.djikstras(0, 3);

}
